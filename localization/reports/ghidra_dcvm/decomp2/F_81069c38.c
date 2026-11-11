
undefined4 * FUN_81069c38(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  func_0x81081704();
  *param_1 = &UNK_81144c14;
  param_1[0x67] = 0;
  iVar1 = 4;
  param_1[6] = 4;
  param_1[1] = param_1 + 0x13;
  param_1[0x65] = param_1 + 0x1d;
  param_1[0x66] = param_1 + 0x1d;
  puVar2 = param_1 + 0x5d;
  param_1[0x68] = 0;
  param_1[0x69] = 0x20;
  param_1[0x6a] = 0;
  param_1[0x6b] = puVar2;
  param_1[0x6c] = 0x20;
  do {
    *(undefined *)puVar2 = 1;
    iVar1 = iVar1 + -1;
    *(undefined *)((int)puVar2 + 1) = 1;
    *(undefined *)((int)puVar2 + 2) = 1;
    *(undefined *)((int)puVar2 + 3) = 1;
    *(undefined *)(puVar2 + 1) = 1;
    *(undefined *)((int)puVar2 + 5) = 1;
    *(undefined *)((int)puVar2 + 6) = 1;
    *(undefined *)((int)puVar2 + 7) = 1;
    puVar2 = puVar2 + 2;
  } while (iVar1 != 0);
  puVar2 = (undefined4 *)0x0;
  puVar3 = (undefined4 *)param_1[0x66];
  iVar1 = 4;
  param_1[0x67] = 0;
  do {
    *puVar3 = puVar2;
    puVar3[2] = puVar3;
    puVar3[4] = puVar3 + 2;
    puVar3[6] = puVar3 + 4;
    puVar3[8] = puVar3 + 6;
    puVar3[10] = puVar3 + 8;
    puVar3[0xc] = puVar3 + 10;
    iVar1 = iVar1 + -1;
    puVar3[0xe] = puVar3 + 0xc;
    puVar2 = puVar3 + 0xe;
    puVar3 = puVar3 + 0x10;
  } while (iVar1 != 0);
  param_1[0x68] = puVar2;
  param_1[0x6a] = 0x20;
  FUN_8108197a(param_1);
  *param_1 = &UNK_81144c38;
  param_1[0x14d] = 0;
  param_1[0x14e] = 0;
  param_1[7] = 0x4b;
  param_1[8] = 0x2000;
  return param_1;
}

