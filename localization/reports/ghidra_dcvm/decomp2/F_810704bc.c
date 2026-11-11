
void FUN_810704bc(int param_1,short param_2)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = *(int *)(param_1 + 0x1f0);
  uVar5 = (uint)*(ushort *)(param_1 + iVar4 * 8 + 0xf4);
  do {
    if (iVar4 < 0) {
LAB_81070558:
      if (iVar4 < 0) {
        *(undefined4 *)(param_1 + 0x1f0) = 0;
      }
      *(uint *)(param_1 + 500) = uVar5;
      return;
    }
    iVar3 = param_1 + iVar4 * 8;
    piVar2 = *(int **)(iVar3 + 0xf0);
    if (*(short *)(iVar3 + 0xf4) == param_2) {
      if (piVar2 == (int *)0x0) {
        uVar1 = *(ushort *)(iVar3 + 0xf6);
        FUN_8107026c(param_1);
        iVar4 = param_1 + *(int *)(param_1 + 0x1f0) * 8;
        *(ushort *)(iVar4 + 0xf6) = *(ushort *)(iVar4 + 0xf6) & 0xfffe | uVar1 & 1;
        piVar2 = *(int **)(param_1 + *(int *)(param_1 + 0x1f0) * 8 + 0xf0);
        (**(code **)(*piVar2 + 0x20))(piVar2,uVar5);
        iVar4 = *(int *)(param_1 + 0x1f0);
      }
      goto LAB_81070558;
    }
    if ((*(ushort *)(iVar3 + 0xf6) & 2) != 0) {
      *(short *)(param_1 + 0x1f8) = *(short *)(param_1 + 0x1f8) + -1;
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x1c))();
      iVar4 = *(int *)(param_1 + 0x1f0);
      *(undefined4 *)(param_1 + iVar4 * 8 + 0xf0) = 0;
    }
    iVar4 = iVar4 + -1;
    *(int *)(param_1 + 0x1f0) = iVar4;
  } while( true );
}

