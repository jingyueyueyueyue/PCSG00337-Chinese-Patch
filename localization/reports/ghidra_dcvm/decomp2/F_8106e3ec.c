
undefined4 * FUN_8106e3ec(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  param_1[2] = 0;
  *param_1 = &UNK_811454ac;
  param_1[1] = 0;
  func_0x8108089e(param_1 + 3);
  param_1[3] = &UNK_8114732c;
  puVar1 = param_1 + 1;
  iVar2 = 2;
  do {
    iVar2 = iVar2 + -1;
    *(undefined2 *)((int)puVar1 + 0x1a) = 0;
    puVar1 = (undefined4 *)((int)puVar1 + -2);
  } while (-1 < iVar2);
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xe] = 0;
  *(undefined2 *)(param_1 + 0xf) = 0;
  *(undefined2 *)((int)param_1 + 0x3e) = 0;
  *(undefined *)((int)param_1 + 0x43) = 0;
  *(byte *)((int)param_1 + 0x42) = *(byte *)((int)param_1 + 0x42) & 0x86 | 6;
  *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xf8 | 0x78;
  func_0x8108d650(param_1 + 10,0,0x10);
  return param_1;
}

