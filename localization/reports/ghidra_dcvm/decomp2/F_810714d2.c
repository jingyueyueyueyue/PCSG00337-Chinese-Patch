
void FUN_810714d2(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = *param_2;
  puVar2 = (undefined4 *)(param_1 + 4);
  iVar1 = 0xb;
  do {
    uVar3 = param_2[1];
    iVar1 = iVar1 + -1;
    *puVar2 = uVar4;
    puVar2[1] = uVar3;
    uVar4 = param_2[3];
    puVar2[2] = param_2[2];
    puVar2[3] = uVar4;
    puVar2 = puVar2 + 4;
    param_2 = param_2 + 4;
    uVar4 = *param_2;
  } while (iVar1 != 0);
  *(undefined4 *)(param_1 + 0xb4) = uVar4;
  return;
}

