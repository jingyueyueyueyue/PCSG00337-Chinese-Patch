
undefined4 * FUN_8108af70(undefined4 *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  
  func_0x8107a746();
  iVar4 = 0;
  *param_1 = &UNK_811465e4;
  puVar1 = (undefined *)((int)param_1 + 0xd);
  do {
    iVar3 = 3;
    puVar2 = puVar1;
    do {
      *puVar2 = 0;
      iVar3 = iVar3 + -1;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[7] = 0;
      puVar2 = puVar2 + 8;
    } while (iVar3 != 0);
    puVar1[0x18] = 0;
    iVar4 = iVar4 + 1;
    puVar1[0x19] = 0;
    puVar1[0x1a] = 0;
    puVar1[0x1b] = 0;
    puVar1 = puVar1 + 0x1c;
  } while (iVar4 < 0x20);
  *(undefined *)((int)param_1 + 0x38e) = 0;
  *(undefined *)((int)param_1 + 0x38d) = 0;
  *(undefined *)((int)param_1 + 0x38f) = 0;
  param_1[1] = 0x18;
  param_1[2] = 2;
  return param_1;
}

