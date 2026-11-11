
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_8106d08e(int param_1,char param_2)

{
  ushort uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined *puStack_28;
  undefined4 uStack_24;
  int *piStack_20;
  int iStack_1c;
  char cStack_18;
  undefined4 *puStack_14;
  
  puStack_14 = _UNK_8111a5b0;
  uVar1 = *(ushort *)(param_1 + 0x10);
  if ((bool)param_2 != ((uVar1 & 4) == 0)) {
    *(ushort *)(param_1 + 0x10) = uVar1 & 0xfffb;
    if (param_2 == '\0') {
      *(ushort *)(param_1 + 0x10) = uVar1 & 0xfffb | 4;
      FUN_8106cfa4(param_1,0);
      FUN_8106d010(param_1,0);
    }
    piVar2 = *(int **)(param_1 + 0x14);
    if (piVar2 != (int *)0x0) {
      puStack_28 = &UNK_81145030;
      uStack_24 = 0x80000027;
      piStack_20 = piVar2;
      iStack_1c = param_1;
      cStack_18 = param_2;
      (**(code **)(*piVar2 + 8))(piVar2,&puStack_28);
    }
  }
  if (_UNK_8111a5b0 == puStack_14) {
    return _UNK_8111a5b0;
  }
  uVar4 = 0x8106d113;
  puVar3 = (undefined4 *)func_0x811185a0();
  *(undefined *)(puVar3 + 0xd) = 1;
  puVar3[3] = 0;
  puVar3[4] = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  *puVar3 = &UNK_81145128;
  func_0x8108d650(puVar3 + 5,0,0x20,&UNK_81145128,param_1,param_2,&UNK_8111a5b0,uVar4);
  *(undefined *)(puVar3 + 0xd) = 0;
  return puVar3;
}

