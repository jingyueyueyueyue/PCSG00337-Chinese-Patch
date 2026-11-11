
undefined4 * FUN_8108ca06(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &UNK_81146698;
  iVar1 = func_0x81118580(param_1[1]);
  if (iVar1 != 0) {
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

