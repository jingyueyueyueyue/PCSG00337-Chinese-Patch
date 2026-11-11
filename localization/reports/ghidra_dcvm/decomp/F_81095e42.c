
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81095e42(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = *(int *)(param_1 + 0x4c);
  iVar5 = *(int *)(param_1 + 0xc);
  uVar3 = *(undefined4 *)(param_1 + 0x50);
  uVar2 = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x4c) = 0;
  if (*(int *)(param_1 + 0x34) == 1) {
    if (iVar5 < 0) {
      *(undefined4 *)(param_1 + 0x38) = _UNK_81138470;
    }
    else {
      iVar6 = func_0x810949a0(param_1,iVar5,4);
      if (iVar6 != 0) {
        *(int *)(param_1 + 0xc) = iVar5;
        *(undefined4 *)(param_1 + 0x38) =
             *(undefined4 *)
              (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + iVar5 + 1) * 0xc);
      }
    }
  }
  else {
    *(undefined **)(param_1 + 0x38) = &UNK_81096439;
  }
  FUN_81095cfa(param_1,param_2,param_3,param_4,param_5,0,1);
  iVar6 = *(int *)(param_1 + 0x34);
  do {
    iVar4 = 0;
    if (iVar6 == 1) {
      iVar4 = (**(code **)(param_1 + 0x38))(param_1);
      iVar6 = *(int *)(param_1 + 0x34);
    }
  } while ((iVar4 != 0) && (iVar5 != *(int *)(param_1 + 0xc)));
  *(int *)(param_1 + 0x4c) = iVar1;
  if (iVar6 == 1) {
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0xc);
      if (iVar1 < 0) {
        *(undefined4 *)(param_1 + 0x38) = _UNK_81138470;
      }
      else {
        iVar5 = func_0x810949a0(param_1,iVar1,4);
        iVar6 = *(int *)(param_1 + 0x34);
        if (iVar5 != 0) {
          *(int *)(param_1 + 0xc) = iVar1;
          *(undefined4 *)(param_1 + 0x38) =
               *(undefined4 *)
                (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + iVar1 + 1) * 0xc);
        }
      }
    }
    else {
      *(undefined **)(param_1 + 0x38) = &UNK_8109643d;
    }
  }
  else {
    *(undefined **)(param_1 + 0x38) = &UNK_81096439;
  }
  *(undefined4 *)(param_1 + 0x50) = uVar3;
  *(undefined4 *)(param_1 + 0x54) = uVar2;
  if ((iVar6 == 1) && (iVar4 == 0)) {
    *(undefined **)(param_1 + 0x38) = &UNK_81096439;
    *(undefined4 *)(param_1 + 0x34) = 3;
  }
  return;
}

