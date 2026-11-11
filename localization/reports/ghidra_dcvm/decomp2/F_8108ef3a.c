
void FUN_8108ef3a(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  cVar1 = *(char *)(param_1 + 4);
  while( true ) {
    if (cVar1 != '\0') {
      piVar3 = *(int **)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x1c) = 0;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))();
      }
      piVar3 = *(int **)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x20) = 0;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))();
      }
      piVar3 = *(int **)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x24) = 0;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))();
      }
      piVar3 = *(int **)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x28) = 0;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))();
      }
      piVar3 = *(int **)(param_1 + 0x2c);
      *(undefined4 *)(param_1 + 0x2c) = 0;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))();
      }
      piVar3 = *(int **)(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x18) = 0;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))();
      }
      return;
    }
    iVar2 = func_0x81116fc0(*(undefined4 *)(param_1 + 8));
    if (iVar2 != 0) break;
    func_0x8109f58e(*(undefined4 *)(param_1 + 0x18));
    func_0x810a0448();
    cVar1 = *(char *)(param_1 + 4);
  }
  do {
    func_0x81118870(1000);
  } while( true );
}

