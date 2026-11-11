
void FUN_81095664(undefined4 param_1)

{
  uint uVar1;
  
  do {
    uVar1 = func_0x81094bac(param_1);
    if (uVar1 == 0xffffffff) {
      return;
    }
  } while ((uVar1 & 0x40000000) == 0);
  if ((uVar1 & 0x80000000) == 0) {
    func_0x81094bac(param_1);
  }
  return;
}

