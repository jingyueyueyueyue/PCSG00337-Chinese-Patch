
void FUN_810805c8(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  short sVar5;
  int iVar6;
  undefined4 *puVar7;
  
  puVar7 = (undefined4 *)**(undefined4 **)(param_2 + 0xc);
  iVar6 = *(int *)(param_1 + 8);
  sVar1 = *(short *)((int)puVar7 + 0x1e);
  iVar2 = puVar7[5];
  if (puVar7 != (undefined4 *)0x0) {
    **(undefined4 **)(param_2 + 0xc) = *puVar7;
    *puVar7 = 0;
  }
  sVar5 = sVar1 + 1;
  *(short *)((int)puVar7 + 0x1e) = sVar5;
  if (sVar5 == 0) {
    *(short *)((int)puVar7 + 0x1e) = sVar1 + 2;
  }
  puVar7[1] = 0;
  puVar7[2] = 0;
  if (iVar2 == 3) {
    func_0x81005b02(puVar7[3]);
  }
  func_0x8108d650(puVar7 + 3,0,8);
  puVar7[5] = 1;
  *puVar7 = 0;
  puVar3 = *(undefined4 **)(iVar6 + 0x18);
  if (puVar3 != (undefined4 *)0x0) {
    do {
      puVar4 = puVar3;
      puVar3 = (undefined4 *)*puVar4;
    } while ((undefined4 *)*puVar4 != (undefined4 *)0x0);
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = puVar7;
      return;
    }
  }
  *(undefined4 **)(iVar6 + 0x18) = puVar7;
  return;
}

