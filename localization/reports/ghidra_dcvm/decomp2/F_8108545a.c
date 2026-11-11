
void FUN_8108545a(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = *(int *)(param_1 + 0x24);
  if (*(int *)(param_1 + 8) == 4) {
    puVar1 = (undefined4 *)func_0x81005a98(0xc);
    puVar5 = (undefined4 *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      uVar3 = *(undefined4 *)(iRam811ae7b4 + 0x1c);
      puVar1[1] = 0;
      *puVar1 = &UNK_811463a8;
      puVar1[2] = uVar3;
      puVar5 = puVar1;
    }
    piVar2 = *(int **)(iVar4 + 0xdc);
    *(undefined4 **)(iVar4 + 0xdc) = puVar5;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))();
    }
  }
  else {
    puVar1 = (undefined4 *)func_0x81005a98(0xc);
    puVar5 = (undefined4 *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      uVar3 = *(undefined4 *)(iRam811ae7b4 + 0x18);
      puVar1[1] = 0;
      *puVar1 = &UNK_811463a8;
      puVar1[2] = uVar3;
      puVar5 = puVar1;
    }
    piVar2 = *(int **)(iVar4 + 0xdc);
    *(undefined4 **)(iVar4 + 0xdc) = puVar5;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))();
    }
  }
  return;
}

