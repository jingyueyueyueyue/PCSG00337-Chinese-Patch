
void FUN_81075720(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 8);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)func_0x81082c5e(uRam811ae690);
  }
  uVar1 = (**(code **)(*piVar3 + 0x10))(piVar3);
  uVar2 = (**(code **)(*piVar3 + 0x14))(piVar3);
  func_0x81075688(param_1,0,0,uVar1,uVar2);
  return;
}

