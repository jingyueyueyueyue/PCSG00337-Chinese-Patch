
void FUN_8107009c(ushort **param_1,int param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  
  puVar3 = *(ushort **)(param_2 + 0x10);
  puVar5 = *(ushort **)(param_2 + 0xc);
  puVar2 = puVar3 + (uint)*(ushort *)(param_2 + 10) * 2 + 2;
  puVar1 = (ushort *)(uint)*puVar3;
  if ((ushort *)(uint)*puVar3 == (ushort *)0xffff) {
    do {
      puVar4 = puVar3;
      puVar3 = puVar4 + 2;
      if (puVar3 == puVar2) break;
    } while (puVar4[2] == 0xffff);
    puVar1 = (ushort *)0xffff;
    if (puVar3 != puVar2) {
      puVar1 = (ushort *)(uint)puVar4[2];
    }
  }
  *param_1 = puVar3;
  param_1[1] = puVar2;
  param_1[2] = puVar5;
  param_1[3] = puVar1;
  return;
}

