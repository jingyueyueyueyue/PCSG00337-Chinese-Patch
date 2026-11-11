# Headless post-script: decompile target functions + callers, dump raw memory.
# Usage: -postScript DumpDcvm.py <out_dir> decomp:810d62da decomp:810d67b2 ... dump:811CDDA0:0x400
# @category Analysis
from ghidra.app.decompiler import DecompInterface
from ghidra.app.cmd.function import CreateFunctionCmd
from ghidra.util.task import ConsoleTaskMonitor

ARGS = getScriptArgs()
OUT = ARGS[0]
TASKS = ARGS[1:]
MON = ConsoleTaskMonitor()

af = currentProgram.getAddressFactory().getDefaultAddressSpace()
fm = currentProgram.getFunctionManager()
listing = currentProgram.getListing()
refMgr = currentProgram.getReferenceManager()


def A(v):
    return af.getAddress(v)


def ensure_function(addr):
    f = fm.getFunctionAt(addr)
    if f is not None:
        return f
    # try thumb (odd) then even
    CreateFunctionCmd(addr).applyTo(currentProgram, MON)
    f = fm.getFunctionAt(addr)
    if f is None and addr.getOffset() & 1:
        CreateFunctionCmd(A(addr.getOffset() - 1)).applyTo(currentProgram, MON)
        f = fm.getFunctionAt(A(addr.getOffset() - 1))
    return f


DI = DecompInterface()
DI.openProgram(currentProgram)


def decompile(addr):
    f = fm.getFunctionAt(addr)
    if f is None:
        return "// no function at %s" % addr
    res = DI.decompileFunction(f, 180, MON)
    if res.decompileCompleted():
        return res.getDecompiledFunction().getC()
    return "// decompile failed: %s" % res.getErrorMessage()


def callers_of(addr):
    out = set()
    for target in (addr, A(addr.getOffset() | 1)):
        for ref in refMgr.getReferencesTo(target):
            fn = fm.getFunctionContaining(ref.getFromAddress())
            if fn is not None:
                out.add(fn.getEntryPoint().getOffset())
    return out


todo = []       # (tag, addr, len)
decomp_targets = []
for t in TASKS:
    parts = t.split(":")
    if parts[0] == "decomp":
        todo.append(("decomp", int(parts[1], 16), 0))
    elif parts[0] == "dump":
        todo.append(("dump", int(parts[1], 16), int(parts[2], 16)))

done = set()
level = {int(t.split(":")[1], 16): 0 for t in TASKS if t.startswith("decomp:")}
queue = [k for k, v in level.items()]
MAX_DEPTH = 2
while queue:
    off = queue.pop(0)
    if off in done or level.get(off, 0) > MAX_DEPTH:
        continue
    done.add(off)
    fn = ensure_function(A(off))
    if fn is None:
        print("!! cannot create function at %x" % off)
        continue
    real = fn.getEntryPoint().getOffset()
    decomp_targets.append(real)
    if level.get(off, 0) >= MAX_DEPTH:
        continue
    for c in callers_of(A(real)):
        if c not in done and c not in queue:
            level[c] = level.get(off, 0) + 1
            queue.append(c)

import os
if not os.path.exists(OUT):
    os.makedirs(OUT)

index = []
for off in sorted(set(decomp_targets)):
    name = fm.getFunctionAt(A(off)).getName()
    txt = decompile(A(off))
    p = os.path.join(OUT, "FUN_%08x.c" % off)
    fh = open(p, "w")
    fh.write(txt)
    fh.close()
    ncallers = len(callers_of(A(off)))
    index.append("FUN_%08x %s callers=%d" % (off, name, ncallers))
    print("wrote %s (%s)" % (p, name))

for tag, off, ln in todo:
    if tag != "dump":
        continue
    data = getBytes(A(off), ln)
    p = os.path.join(OUT, "dump_%08x.bin" % off)
    fh = open(p, "wb")
    fh.write(data)
    fh.close()
    print("wrote %s" % p)
    # also a words view
    p2 = os.path.join(OUT, "dump_%08x.words.txt" % off)
    fh = open(p2, "w")
    import struct
    for i in range(0, ln - 3, 16):
        row = [struct.unpack_from("<I", data, i + 4 * k)[0] for k in range(4)]
        fh.write("%08x: %08x %08x %08x %08x\n" % ((off + i,) + tuple(row)))
    fh.close()

fh = open(os.path.join(OUT, "INDEX.txt"), "w")
fh.write("\n".join(index))
fh.close()
print("DONE, %d functions" % len(set(decomp_targets)))
