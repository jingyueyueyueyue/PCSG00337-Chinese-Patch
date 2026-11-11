
undefined4 FUN_810afbc8(int param_1,int *param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 *puStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  int iStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  
  puVar7 = &uStack_a8;
  uVar6 = 0;
  uVar4 = 0;
  iVar8 = 0;
  iStack_30 = param_1;
  uStack_2c = param_3;
  if (0 < param_2[1]) {
    iVar5 = 0;
    do {
      uStack_60 = 0;
      uStack_5c = 0;
      uStack_58 = 0;
      uStack_54 = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_48 = 0;
      uStack_44 = 0;
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      iStack_34 = 0;
      func_0x810c5022(0x811ae02c,*param_2 + iVar5,&uStack_60);
      if ((uStack_38 & 0xffff) == 0x57) {
        uVar6 = uVar6 | 1;
        puVar3 = (undefined *)(iStack_34 + -0x7ee51d98);
        uVar9 = uStack_3c << 0x18 | (uStack_3c >> 8 & 0xff) << 0x10 |
                (uStack_3c >> 0x10 & 0xff) << 8 | uStack_3c >> 0x18;
      }
      else {
        if ((uStack_38 & 0xffff) != 0x58) {
          return 0x86000017;
        }
        uVar6 = uVar6 | 2;
        puVar3 = (undefined *)(iStack_34 + -0x7ee51c94);
        uVar9 = uStack_3c << 0x18 | (uStack_3c >> 8 & 0xff) << 0x10 |
                (uStack_3c >> 0x10 & 0xff) << 8 | uStack_3c >> 0x18;
      }
      *puVar3 = (char)uVar9;
      puVar3[1] = (char)(uVar9 >> 8);
      puVar3[2] = (char)(uVar9 >> 0x10);
      puVar3[3] = (char)(uVar9 >> 0x18);
      iVar10 = **(int **)(iStack_30 + 200) + iVar5;
      if ((uStack_40 & 0x400) == 0) {
        uVar2 = *(undefined4 *)(iVar10 + 0x20);
        puVar3[4] = (char)((uint)uVar2 >> 0x18);
        puVar3[5] = (char)((uint)uVar2 >> 0x10);
        puVar3[6] = (char)((uint)uVar2 >> 8);
        puVar3[7] = (char)uVar2;
      }
      else {
        func_0x811182b0(puVar3 + 4,iVar10 + 0x20,(uStack_38 >> 0x10) - 4);
      }
      iVar8 = iVar8 + 1;
      iVar5 = iVar5 + 0x11c;
    } while (iVar8 < param_2[1]);
  }
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_90 = 0;
  uStack_8c = 0;
  uStack_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0x57;
  uStack_74 = 0x811ae268;
  uStack_70 = uRam811ae368;
  iVar8 = *(int *)(iStack_30 + 200);
  uStack_a8 = *(undefined4 *)(iStack_30 + 0x128);
  uStack_a4 = *(undefined4 *)(iStack_30 + 300);
  uVar1 = *(undefined2 *)(iStack_30 + 0x38);
  if (uVar6 == 3) {
    uVar4 = 2;
    puVar7 = &uStack_9c;
  }
  else if ((uVar6 & 2) == 0) {
    puVar7 = &uStack_9c;
    if ((uVar6 & 1) != 0) {
      uVar4 = 1;
    }
  }
  else {
    uVar4 = 1;
  }
  puVar7[0xe] = uRam811ae46c;
  *(undefined2 *)(puVar7 + 0xc) = 0x58;
  puVar7[0xd] = 0x811ae36c;
  puStack_98 = &uStack_78;
  uStack_a0 = *(undefined4 *)(iVar8 + 8);
  uStack_9c = *(undefined4 *)(iVar8 + 0xc);
  uStack_94 = uVar4;
  uVar4 = func_0x81117540(uVar1,&uStack_a8,0,uStack_2c);
  return uVar4;
}

