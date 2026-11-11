
void FUN_8108c730(uint param_1)

{
  if ((param_1 & 7) == 7) {
    func_0x811187b0(0);
  }
  else {
    if ((param_1 & 1) != 0) {
      func_0x811187b0(1);
    }
    if ((param_1 & 2) != 0) {
      func_0x811187b0(6);
    }
    if ((param_1 & 4) != 0) {
      func_0x811187b0(4);
    }
  }
  return;
}

