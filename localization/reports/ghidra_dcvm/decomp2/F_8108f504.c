
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8108f504(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_20;
  int iStack_1c;
  
  iStack_1c = _UNK_8111a5b0;
  iVar3 = *(int *)(param_1 + 0x388);
  while( true ) {
    (**(code **)(**(int **)(iVar3 + 4) + 8))();
    uStack_20 = 1;
    iVar3 = *(int *)(*(int *)(param_1 + 0x388) + 4);
    piVar1 = *(int **)(iVar3 + 0x10);
    iVar3 = (**(code **)(*piVar1 + 0x10))(piVar1,&uStack_20,iVar3,*(undefined4 *)(param_1 + 0x1c));
    if (iVar3 == 0) break;
    iVar3 = *(int *)(param_1 + 0x388);
  }
  if (_UNK_8111a5b0 != iStack_1c) {
    iVar3 = iStack_1c;
    iVar2 = func_0x811185a0(uStack_20);
    FUN_8107e2a0();
    iVar4 = *(int *)(iVar2 + 0x20);
    *(int *)(iVar2 + 0x1c) = iVar3;
    if (iVar4 < 2) {
      if (-1 < iVar4) {
        if (iVar4 < 1) {
          piVar1 = *(int **)(*(int *)(iVar2 + 0x388) + 4);
          piVar1[2] = 0;
          (**(code **)(*piVar1 + 8))();
        }
        else {
          piVar1 = *(int **)(*(int *)(iVar2 + 0x388) + 4);
          piVar1[2] = 0;
          (**(code **)(*piVar1 + 8))();
        }
      }
    }
    else if (iVar4 < 3) {
      piVar1 = *(int **)(*(int *)(iVar2 + 0x388) + 4);
      piVar1[2] = 0xf;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    else if (iVar4 < 4) {
      piVar1 = *(int **)(*(int *)(iVar2 + 0x388) + 4);
      piVar1[2] = 0xf;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    return;
  }
  return;
}

