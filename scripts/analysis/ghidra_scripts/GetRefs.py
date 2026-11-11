# Find references to given addresses, decompile containing functions.
# Usage: -postScript GetRefs.py <hex_addr> <hex_addr> ...
# @category Analysis
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

ARGS = getScriptArgs()
TARGETS = [int(a, 16) for a in ARGS]
MON = ConsoleTaskMonitor()
af = currentProgram.getAddressFactory().getDefaultAddressSpace()
fm = currentProgram.getFunctionManager()
RM = currentProgram.getReferenceManager()
DI = DecompInterface()
DI.openProgram(currentProgram)


def A(v):
    return af.getAddress(v)


for t in TARGETS:
    ta = A(t)
    refs = RM.getReferencesTo(ta)
    funcs = set()
    for r in refs:
        fa = r.getFromAddress()
        f = fm.getFunctionContaining(fa)
        print("ref to %x from %x in %s" % (t, fa.getOffset(), f))
        if f is not None:
            funcs.add(f.getEntryPoint().getOffset())
    for fo in sorted(funcs):
        f = fm.getFunctionAt(A(fo))
        res = DI.decompileFunction(f, 120, MON)
        txt = res.getDecompiledFunction().getC() if res.decompileCompleted() else "// FAIL"
        print("==== decomp of %x ====" % fo)
        print(txt[:20000])
print("DONE")
