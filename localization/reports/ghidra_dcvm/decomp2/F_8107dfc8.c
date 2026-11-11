
void FUN_8107dfc8(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar4 = param_1[2];
  iVar2 = 0;
  puVar1 = (undefined4 *)*param_1;
  do {
    *puVar1 = 0;
    uVar3 = uVar3 + 1;
    *(undefined4 *)(param_1[1] + iVar2) = 0;
    iVar2 = iVar2 + 4;
    puVar1 = puVar1 + 1;
  } while (uVar3 <= uVar4);
  param_1[3] = 0;
  return;
}

