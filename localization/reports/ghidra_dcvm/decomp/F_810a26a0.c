
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_810a26a0(short *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 *param_7,byte param_8,uint param_9
                 )

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  undefined2 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined auStack_64 [8];
  undefined4 uStack_5c;
  undefined auStack_58 [8];
  undefined4 uStack_50;
  undefined auStack_4c [8];
  undefined4 uStack_44;
  undefined4 *puStack_40;
  undefined4 *puStack_3c;
  undefined4 uStack_38;
  short *psStack_34;
  uint uStack_30;
  byte bStack_2c;
  uint uStack_28;
  
  uStack_28 = _UNK_8111a5b0;
  bStack_2c = param_8;
  uStack_38 = param_5;
  uStack_30 = param_9;
  psStack_34 = param_1;
  if ((param_8 & 8) == 0) {
    uStack_6c = 0;
    uStack_68 = 0;
    piVar4 = (int *)(**(code **)(**(int **)(*param_2 + 4) + 0x20))();
    iVar7 = *piVar4;
    if (iVar7 != 0) {
      uStack_44 = 0;
      func_0x81080bb2(auStack_4c,param_6);
      iVar7 = FUN_81079552(iVar7,&uStack_6c,&uStack_68,auStack_4c,param_7);
      func_0x81005af0(uStack_44);
      uStack_44 = 0;
      if (iVar7 != 0) {
        func_0x810a1800(param_2,uStack_6c,uStack_68,1,0);
      }
    }
  }
  *param_4 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  puStack_40 = param_7;
  puStack_3c = param_4;
  piVar4 = (int *)(**(code **)(**(int **)(*param_2 + 4) + 0x20))();
  iVar7 = *piVar4;
  if (iVar7 != 0) {
    puStack_40 = param_7;
    uStack_50 = 0;
    puStack_3c = param_4;
    func_0x81080bb2(auStack_58,param_6);
    iVar7 = FUN_81079552(iVar7,&uStack_74,&uStack_70,auStack_58,param_7);
    func_0x81005af0(uStack_50);
    uStack_50 = 0;
    if (iVar7 != 0) {
      func_0x810a2530(psStack_34,param_2,param_3,param_4,uStack_38,uStack_74,uStack_70,bStack_2c,
                      uStack_30);
      goto LAB_810a28c8;
    }
  }
  func_0x810a170e(&uStack_78,*param_2 + 0x7c);
  if (uStack_78 == 0) {
    *psStack_34 = 0;
  }
  else {
    iVar8 = *param_2;
    (**(code **)(*(int *)(iVar8 + 0xa0) + 8))(iVar8 + 0xa0);
    iVar7 = 0;
    if ((char)uStack_78 == *(char *)(*(int *)(iVar8 + 0x94) + (uint)uStack_78._1_1_)) {
      iVar7 = (uint)uStack_78._1_1_ * 0x34 + *(int *)(iVar8 + 0x80);
    }
    (**(code **)(*(int *)(iVar8 + 0xa0) + 0xc))(iVar8 + 0xa0);
    uStack_5c = 0;
    func_0x81080bb2(auStack_64,param_6);
    uVar3 = uStack_5c;
    *(undefined4 *)(iVar7 + 4) = uStack_38;
    if (*(int *)(iVar7 + 0x10) == 0) {
      func_0x81005b02(*(undefined4 *)(iVar7 + 8));
    }
    *(undefined4 *)(iVar7 + 0xc) = 0;
    *(undefined4 *)(iVar7 + 0x10) = 1;
    *(undefined4 *)(iVar7 + 8) = 0;
    *(undefined4 *)(iVar7 + 0x14) = uRam81191264;
    iVar8 = func_0x81118330(uVar3);
    iVar5 = func_0x81005aaa(iVar8 + 1);
    *(int *)(iVar7 + 8) = iVar5;
    if (iVar5 == 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    func_0x8109d75c(iVar5,iVar8 + 1,uVar3);
    *(undefined4 *)(iVar7 + 0x10) = 0;
    *(undefined4 *)(iVar7 + 0x14) = *puStack_40;
    *(undefined4 **)(iVar7 + 0x18) = puStack_3c;
    *(undefined4 *)(iVar7 + 0x1c) = 0;
    *(byte *)(iVar7 + 0x24) = bStack_2c;
    func_0x81005af0(uStack_5c);
    uStack_5c = 0;
    *(byte *)(iVar7 + 0x24) = *(byte *)(iVar7 + 0x24) & 0xfd;
    *param_3 = 1;
    param_3[1] = 0;
    *(undefined4 **)(iVar7 + 0x30) = param_3;
    iVar8 = *param_2;
    (**(code **)(*(int *)(iVar8 + 0x3c) + 8))(iVar8 + 0x3c);
    func_0x8107e03a(iVar8 + 0x28,iVar7,(uStack_30 & 0xff) + 1);
    (**(code **)(*(int *)(iVar8 + 0x3c) + 0xc))(iVar8 + 0x3c);
    *psStack_34 = uStack_78;
  }
LAB_810a28c8:
  if (_UNK_8111a5b0 == uStack_28) {
    return _UNK_8111a5b0;
  }
  uVar9 = func_0x811185a0();
  pcVar6 = (char *)((ulonglong)uVar9 >> 0x20);
  iVar7 = (int)uVar9;
  (**(code **)(*(int *)(iVar7 + 0x24) + 8))(iVar7 + 0x24);
  cVar2 = *(char *)(*(int *)(iVar7 + 0x18) + (uint)(byte)pcVar6[1]);
  cVar1 = *pcVar6;
  (**(code **)(*(int *)(iVar7 + 0x24) + 0xc))(iVar7 + 0x24);
  return (uint)(cVar1 != cVar2);
}

