
void FUN_810852bc(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x24);
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(param_1 + 0x18);
  (**(code **)(iVar3 + 0xd8))(uVar1,param_1);
  piVar2 = *(int **)(*(int *)(param_1 + 0x24) + 0xe0);
  (**(code **)(*piVar2 + 0xc))(piVar2,*(undefined4 *)(param_1 + 4),param_1);
  piVar2 = *(int **)(*(int *)(param_1 + 0x24) + 0xdc);
  (**(code **)(*piVar2 + 0xc))(piVar2,*(undefined4 *)(param_1 + 4),param_1);
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

