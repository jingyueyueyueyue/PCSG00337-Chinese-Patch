
void FUN_81082bb6(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(param_1 + 8);
  (**(code **)(*piVar2 + 8))(piVar2);
  FUN_81075858(*(undefined4 *)(*(int *)(param_1 + 4) + 0x14));
  FUN_81075834(*(undefined4 *)(*(int *)(param_1 + 4) + 0x14));
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x14);
  FUN_81075d78(iVar3);
  iVar3 = func_0x81116cf0(*(undefined4 *)(**(int **)(iVar3 + 4) + 4),0,0);
  if (iVar3 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  iVar3 = *(int *)(param_1 + 4);
  if ((*(char *)(iVar3 + 0x3c) != '\0') && (*(int *)(iVar3 + 0x24) != 0)) {
    iVar1 = func_0x81116760();
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    *(undefined4 *)(iVar3 + 0x24) = 0;
  }
  (**(code **)(*piVar2 + 0xc))(piVar2);
  return;
}

