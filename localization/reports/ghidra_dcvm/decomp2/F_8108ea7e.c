
undefined4 * FUN_8108ea7e(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &UNK_81146700;
  *(undefined *)(param_1 + 1) = 1;
  if (param_1[4] != 0) {
    FUN_81094348();
    iVar1 = param_1[4];
    param_1[4] = 0;
    if (iVar1 != 0) {
      func_0x810942c4();
      func_0x81005af0();
    }
  }
  func_0x810a0446();
  if (param_1[2] != 0) {
    iVar1 = func_0x81116f80();
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    if (param_1[3] != 0) {
      func_0x81118280();
      param_1[3] = 0;
    }
    param_1[2] = 0;
  }
  func_0x81116d40(0xb);
  if ((int *)param_1[0xb] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xb] + 4))();
  }
  param_1[0xb] = 0;
  if ((int *)param_1[10] != (int *)0x0) {
    (**(code **)(*(int *)param_1[10] + 4))();
  }
  param_1[10] = 0;
  if ((int *)param_1[9] != (int *)0x0) {
    (**(code **)(*(int *)param_1[9] + 4))();
  }
  param_1[9] = 0;
  if ((int *)param_1[8] != (int *)0x0) {
    (**(code **)(*(int *)param_1[8] + 4))();
  }
  param_1[8] = 0;
  if ((int *)param_1[7] != (int *)0x0) {
    (**(code **)(*(int *)param_1[7] + 4))();
  }
  param_1[7] = 0;
  if ((int *)param_1[6] != (int *)0x0) {
    (**(code **)(*(int *)param_1[6] + 4))();
  }
  param_1[6] = 0;
  if (param_1[5] != 0) {
    FUN_81094398();
    func_0x81005af0();
  }
  param_1[5] = 0;
  if (param_1[4] != 0) {
    func_0x810942c4();
    func_0x81005af0();
  }
  param_1[4] = 0;
  *param_1 = &UNK_811466f0;
  uRam811ae7cc = 0;
  return param_1;
}

