
void FUN_8107dfea(undefined4 *param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  param_1[1] = param_2;
  puVar1 = (undefined4 *)(param_2 + param_3 * 4);
  *param_1 = puVar1;
  param_1[2] = param_3;
  iVar2 = 0;
  do {
    *puVar1 = 0;
    uVar3 = uVar3 + 1;
    *(undefined4 *)(param_1[1] + iVar2) = 0;
    iVar2 = iVar2 + 4;
    puVar1 = puVar1 + 1;
  } while (uVar3 <= param_3);
  param_1[3] = 0;
  return;
}

