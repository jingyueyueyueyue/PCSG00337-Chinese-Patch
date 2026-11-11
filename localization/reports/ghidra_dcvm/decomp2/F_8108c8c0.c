
undefined4 * FUN_8108c8c0(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)param_1[1];
  *param_1 = &UNK_81146680;
  iVar2 = func_0x811188a0(uVar1);
  if (iVar2 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (param_1[1] != 0) {
    param_1[1] = 0;
    func_0x81005af0();
    if (param_1[1] != 0) {
      func_0x81005af0();
    }
  }
  *param_1 = &UNK_81145e6c;
  param_1[1] = 0;
  return param_1;
}

