
undefined4 * FUN_8108740c(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  *param_1 = &UNK_81146494;
  iVar1 = *(int *)param_1[1];
  *(int *)param_1[1] = 0;
  if (iVar1 != 0) {
    FUN_8108a4ce();
    func_0x81005af0();
  }
  iVar1 = *(int *)(param_1[1] + 4);
  *(undefined4 *)(param_1[1] + 4) = 0;
  if (iVar1 != 0) {
    func_0x8108769e();
    func_0x81005af0();
  }
  piVar2 = (int *)param_1[1];
  if (piVar2 != (int *)0x0) {
    if (piVar2[1] != 0) {
      func_0x8108769e();
      func_0x81005af0();
    }
    piVar2[1] = 0;
    if (*piVar2 != 0) {
      FUN_8108a4ce();
      func_0x81005af0();
    }
    *piVar2 = 0;
    func_0x81005af0(piVar2);
  }
  param_1[1] = 0;
  func_0x810769a6(param_1);
  return param_1;
}

