
int FUN_81069938(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  puVar1 = (undefined4 *)func_0x81005a98(0x300);
  puVar4 = *(undefined4 **)(param_1 + 8);
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar3 = puVar1;
  if (puVar2 != puVar4) {
    do {
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = *puVar2;
        puVar3[1] = puVar2[1];
        puVar3[2] = puVar2[2];
      }
      puVar2 = puVar2 + 3;
      puVar3 = puVar3 + 3;
    } while (puVar2 != puVar4);
    puVar2 = *(undefined4 **)(param_1 + 4);
    puVar4 = *(undefined4 **)(param_1 + 8);
  }
  if (puVar2 != (undefined4 *)0x0) {
    func_0x81005af0();
  }
  *(undefined4 **)(param_1 + 4) = puVar1;
  *(undefined4 **)(param_1 + 0xc) = puVar1 + 0xc0;
  *(undefined4 **)(param_1 + 8) = puVar1 + (((int)puVar4 - (int)puVar2) / 0xc) * 3;
  return param_1;
}

