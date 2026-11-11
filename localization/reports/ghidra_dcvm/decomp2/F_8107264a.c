
void FUN_8107264a(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 8) = 0;
  while (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x1c))(piVar2);
    if (piVar2 != (int *)0x0) {
      piVar2 = (int *)piVar2[4];
    }
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    piVar2 = *(int **)(iVar1 + 200);
    *(undefined4 *)(iVar1 + 200) = 0;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))();
    }
    *(undefined4 *)(iVar1 + 0xdc) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0xe0) = 0;
  }
  return;
}

