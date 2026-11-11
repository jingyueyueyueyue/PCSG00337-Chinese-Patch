
void FUN_810957b2(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  puVar1 = (undefined4 *)func_0x8109b4fe(*(undefined4 *)(param_1 + 0x28));
  iVar8 = *(int *)(param_1 + 0x14);
  iVar7 = iVar8 + -1;
  iVar4 = *(int *)(param_1 + 0x24);
  if (iVar7 < 0) {
    *(undefined **)(param_1 + 0x38) = &UNK_81096439;
    *(undefined4 *)(param_1 + 0x34) = 3;
    iVar7 = iVar8;
  }
  else if (*(int *)(param_1 + 0x1c) < 0) {
    *(undefined **)(param_1 + 0x38) = &UNK_81096439;
    *(undefined4 *)(param_1 + 0x34) = 3;
    iVar7 = iVar8;
  }
  else {
    *(int *)(param_1 + 0x14) = iVar7;
  }
  iVar7 = iVar7 * 8;
  *(uint *)(iVar4 + iVar7) = *(uint *)(iVar4 + iVar7) & 0xffffff00 | 0x21;
  *(undefined4 *)(iVar4 + iVar7 + 4) = param_3;
  func_0x810956d4(param_1,*(uint *)(*(int *)(param_1 + 0x28) + 0x74) | param_4);
  uVar2 = func_0x8109b066(*(undefined4 *)(param_1 + 0x28),*puVar1);
  if (*(char *)(puVar1 + 1) == '\x04') {
    puVar3 = (undefined4 *)func_0x8109ca34(*(undefined4 *)(param_1 + 0x40));
    if ((puVar1[2] & 0xffffff) == 0xffffff) {
      iVar7 = func_0x8109c2c4(*puVar3,puVar1,uVar2);
      if (iVar7 == 0) {
        *(undefined **)(param_1 + 0x38) = &UNK_81096439;
        *(undefined4 *)(param_1 + 0x34) = 3;
        return;
      }
      *(int *)(param_1 + 0x28) = iVar7;
      *(undefined **)(param_1 + 0x58) = &UNK_81138164;
      *(undefined4 *)(param_1 + 0x5c) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x44) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
      uVar2 = *(undefined4 *)(iVar7 + 0x1c);
      *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(iVar7 + 0x18);
      *(undefined4 *)(param_1 + 0x48) = uVar2;
    }
    else {
      iVar7 = func_0x8109c2ae(*puVar3,*(undefined *)((int)puVar1 + 0xb));
      *(undefined **)(param_1 + 0x58) = &UNK_81138164;
      *(undefined4 *)(param_1 + 0x5c) = 0xffffffff;
      *(int *)(param_1 + 0x28) = iVar7;
      *(undefined4 *)(param_1 + 0x44) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
      if (iVar7 == 0) {
        *(undefined **)(param_1 + 0x38) = &UNK_81096439;
        *(undefined4 *)(param_1 + 0x34) = 3;
        return;
      }
      uVar2 = *(undefined4 *)(iVar7 + 0x1c);
      *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(iVar7 + 0x18);
      *(undefined4 *)(param_1 + 0x48) = uVar2;
    }
    uVar5 = puVar1[2] & 0xffffff;
    iVar7 = func_0x810949a0(param_1,uVar5,4);
    if (iVar7 != 0) {
      *(uint *)(param_1 + 0xc) = uVar5;
      *(undefined4 *)(param_1 + 0x38) =
           *(undefined4 *)
            (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + uVar5 + 1) * 0xc);
    }
  }
  else {
    uVar5 = puVar1[2] & 0xffffff;
    iVar7 = func_0x810949a0(param_1,uVar5,4);
    if (iVar7 != 0) {
      *(uint *)(param_1 + 0xc) = uVar5;
      *(undefined4 *)(param_1 + 0x38) =
           *(undefined4 *)
            (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + uVar5 + 1) * 0xc);
    }
    if ((param_4 & 0x40000000) != 0) {
      iVar7 = FUN_8109b50a(*(undefined4 *)(param_1 + 0x28),&UNK_81138168,1);
      iVar4 = *(int *)(param_1 + 0x24);
      if (iVar7 != -1) {
        iVar6 = *(int *)(param_1 + 0x14);
        iVar8 = iVar6 + -1;
        if (iVar8 < 0) {
          *(undefined **)(param_1 + 0x38) = &UNK_81096439;
          *(undefined4 *)(param_1 + 0x34) = 3;
          iVar8 = iVar6;
        }
        else if (*(int *)(param_1 + 0x1c) < 0) {
          *(undefined **)(param_1 + 0x38) = &UNK_81096439;
          *(undefined4 *)(param_1 + 0x34) = 3;
          iVar8 = iVar6;
        }
        else {
          *(int *)(param_1 + 0x14) = iVar8;
        }
        iVar8 = iVar8 * 8;
        *(uint *)(iVar4 + iVar8) = *(uint *)(iVar4 + iVar8) & 0xffffff00 | 0x21;
        *(undefined4 *)(iVar4 + iVar8 + 4) = 0;
        iVar7 = func_0x8109b4fe(*(undefined4 *)(param_1 + 0x28),iVar7);
        func_0x810956d4(param_1,*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x74));
        uVar5 = *(uint *)(iVar7 + 8) & 0xffffff;
        iVar7 = func_0x810949a0(param_1,uVar5,4);
        if (iVar7 != 0) {
          *(uint *)(param_1 + 0xc) = uVar5;
          *(undefined4 *)(param_1 + 0x38) =
               *(undefined4 *)
                (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + uVar5 + 1) * 0xc);
        }
      }
    }
  }
  func_0x8108d650(param_1 + 0x2c,0,8);
  return;
}

