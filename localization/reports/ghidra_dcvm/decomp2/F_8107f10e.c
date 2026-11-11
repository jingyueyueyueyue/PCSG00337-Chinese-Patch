
void FUN_8107f10e(int param_1,undefined4 *param_2)

{
  short sVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  sVar1 = *(short *)((int)param_2 + 0x1e);
  sVar2 = sVar1 + 1;
  *(short *)((int)param_2 + 0x1e) = sVar2;
  if (sVar2 == 0) {
    *(short *)((int)param_2 + 0x1e) = sVar1 + 2;
  }
  param_2[1] = 0;
  param_2[2] = 0;
  if (param_2[5] == 3) {
    func_0x81005b02(param_2[3]);
  }
  func_0x8108d650(param_2 + 3,0,8);
  param_2[5] = 1;
  *param_2 = 0;
  puVar3 = *(undefined4 **)(param_1 + 0x18);
  if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
    do {
      puVar4 = puVar3;
      puVar3 = (undefined4 *)*puVar4;
    } while ((undefined4 *)*puVar4 != (undefined4 *)0x0);
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = param_2;
      return;
    }
  }
  *(undefined4 **)(param_1 + 0x18) = param_2;
  return;
}

