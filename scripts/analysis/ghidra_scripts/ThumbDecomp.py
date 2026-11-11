# Create Thumb functions at given starts, decompile all.
# Usage: -postScript ThumbDecomp.py <out_dir> <hex_start> <hex_start> ...
# @category Analysis
from ghidra.app.cmd.disassemble import ArmDisassembleCommand
from ghidra.app.cmd.function import CreateFunctionCmd
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
import os

ARGS = getScriptArgs()
OUT = ARGS[0]
if ARGS[1].endswith('.txt'):
    SEEDS = [int(a, 16) for a in open(ARGS[1]).read().split()]
else:
    SEEDS = [int(a, 16) for a in ARGS[1:]]
MON = ConsoleTaskMonitor()
af = currentProgram.getAddressFactory().getDefaultAddressSpace()
fm = currentProgram.getFunctionManager()

def A(v):
    return af.getAddress(v)

DI = DecompInterface()
DI.openProgram(currentProgram)

created = 0
for off in SEEDS:
    addr = A(off)
    if fm.getFunctionAt(addr) is None:
        ArmDisassembleCommand(addr, None, True).applyTo(currentProgram, MON)
        CreateFunctionCmd(addr).applyTo(currentProgram, MON)
        if fm.getFunctionAt(addr) is not None:
            created += 1
        else:
            print("!! no function at %x" % off)
print("created %d/%d functions" % (created, len(SEEDS)))

if not os.path.exists(OUT):
    os.makedirs(OUT)
index = []
for off in SEEDS:
    f = fm.getFunctionAt(A(off))
    if f is None:
        continue
    res = DI.decompileFunction(f, 120, MON)
    txt = res.getDecompiledFunction().getC() if res.decompileCompleted() else "// FAIL: %s" % res.getErrorMessage()
    body = f.getBody()
    p = os.path.join(OUT, "F_%08x.c" % off)
    fh = open(p, "w")
    fh.write(txt)
    fh.close()
    index.append("%08x %s size=%s nbytes=%d" % (off, f.getName(), body.getNumAddresses(), body.getNumAddresses()))
    print("decompiled %08x (%s)" % (off, f.getName()))

fh = open(os.path.join(OUT, "INDEX.txt"), "w")
fh.write("\n".join(sorted(index)))
fh.close()
print("DONE")
