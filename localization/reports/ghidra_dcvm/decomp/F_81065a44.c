
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_81065a44(char *param_1)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint unaff_r4;
  int iVar8;
  int iVar9;
  int unaff_r6;
  int iVar10;
  code *pcVar11;
  int unaff_r7;
  int unaff_r8;
  int unaff_r9;
  int iVar12;
  undefined8 uVar13;
  undefined4 uStack_58;
  int iStack_54;
  uint uStack_4c;
  char *pcStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  undefined *puStack_34;
  undefined auStack_28 [4];
  int iStack_24;
  
  iVar10 = iRam811ae688;
  iStack_24 = _UNK_8111a5b0;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    uVar1 = 0;
    uStack_4c = unaff_r4;
    iVar10 = unaff_r9;
  }
  else {
    unaff_r8 = 0;
    if (iRam811ae688 != 0) {
      unaff_r8 = iRam811ae688 + 4;
    }
    unaff_r7 = unaff_r8 + 4;
    (**(code **)(*(int *)(unaff_r8 + 4) + 8))(unaff_r7);
    iVar9 = 0;
    if (iVar10 != 0) {
      iVar9 = iVar10 + 4;
    }
    unaff_r6 = *(int *)(iVar9 + 0x10);
    uStack_4c = 0;
    if (unaff_r6 == 0) {
      (**(code **)(*(int *)(unaff_r8 + 4) + 0xc))(unaff_r7);
      uVar1 = 0;
    }
    else {
      iVar9 = func_0x8107b846(iVar10 + 100,param_1,auStack_28);
      if (iVar9 == 0) {
        piVar2 = (int *)func_0x810a15ac(**(undefined4 **)(unaff_r6 + 0x1c));
        puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x20))();
        uVar1 = FUN_810794a2(*puVar3,param_1);
        (**(code **)(*(int *)(unaff_r8 + 4) + 0xc))(unaff_r7);
        uStack_4c = uVar1;
      }
      else {
        (**(code **)(*(int *)(unaff_r8 + 4) + 0xc))(unaff_r7);
        uVar1 = 1;
      }
    }
  }
  if (_UNK_8111a5b0 == iStack_24) {
    return uVar1;
  }
  uVar13 = func_0x811185a0(uVar1);
  iVar9 = iRam811ae688;
  pcVar4 = (char *)uVar13;
  puStack_34 = &UNK_8111a5b0;
  iStack_54 = _UNK_8111a5b0;
  pcStack_48 = param_1;
  iStack_44 = unaff_r6;
  iStack_40 = unaff_r7;
  iStack_3c = unaff_r8;
  iStack_38 = iVar10;
  if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
    uVar1 = 1;
  }
  else {
    iVar10 = 0;
    if (iRam811ae688 != 0) {
      iVar10 = iRam811ae688 + 4;
    }
    iVar8 = iVar10 + 4;
    (**(code **)(*(int *)(iVar10 + 4) + 8))(iVar8);
    iVar6 = 0;
    if (iVar9 != 0) {
      iVar6 = iVar9 + 4;
    }
    if (*(int *)(iVar6 + 0x10) == 0) {
      (**(code **)(*(int *)(iVar10 + 4) + 0xc))(iVar8);
      uVar1 = 0;
    }
    else {
      iVar6 = func_0x8107b846(iVar9 + 100,pcVar4,&uStack_58);
      if (iVar6 == 0) {
        iVar6 = 0;
        if (iVar9 != 0) {
          iVar6 = iVar9 + 4;
        }
        iVar12 = iVar6 + 4;
        (**(code **)(*(int *)(iVar6 + 4) + 8))(iVar12);
        iVar7 = 0;
        if (iVar9 != 0) {
          iVar7 = iVar9 + 4;
        }
        if (*(int *)(iVar7 + 0x10) == 0) {
          (**(code **)(*(int *)(iVar6 + 4) + 0xc))(iVar12);
          (**(code **)(*(int *)(iVar10 + 4) + 0xc))(iVar8);
          uVar1 = 1;
          goto LAB_81065bee;
        }
        uVar5 = func_0x810a15ac(**(undefined4 **)(*(int *)(iVar7 + 0x10) + 0x1c));
        uVar1 = func_0x81078072(uVar5,pcVar4,0x81191264,1);
        (**(code **)(*(int *)(iVar6 + 4) + 0xc))(iVar12);
        pcVar11 = *(code **)(*(int *)(iVar10 + 4) + 0xc);
      }
      else {
        uVar1 = func_0x8107bedc(iVar9 + 100,uStack_58);
        pcVar11 = *(code **)(*(int *)(iVar10 + 4) + 0xc);
      }
      uVar1 = (uint)(uVar1 <= (uint)((ulonglong)uVar13 >> 0x20));
      (*pcVar11)(iVar8);
    }
  }
LAB_81065bee:
  if (_UNK_8111a5b0 == iStack_54) {
    return uVar1;
  }
  func_0x811185a0(uVar1);
  iVar10 = iRam811ae688;
  iVar9 = 0;
  if (iRam811ae688 != 0) {
    iVar9 = iRam811ae688 + 4;
  }
  iVar8 = iVar9 + 4;
  (**(code **)(*(int *)(iVar9 + 4) + 8))(iVar8);
  iVar6 = 0;
  if (iVar10 != 0) {
    iVar6 = iVar10 + 4;
  }
  if (*(int *)(iVar6 + 0x10) == 0) {
    (**(code **)(*(int *)(iVar9 + 4) + 0xc))(iVar8);
    uVar1 = 1;
  }
  else {
    uVar1 = func_0x810a17ce(**(undefined4 **)(*(int *)(iVar6 + 0x10) + 0x1c));
    (**(code **)(*(int *)(iVar9 + 4) + 0xc))(iVar8);
  }
  return uVar1;
}

