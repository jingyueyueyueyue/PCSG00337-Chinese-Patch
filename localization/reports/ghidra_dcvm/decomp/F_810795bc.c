
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810795bc(undefined4 param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 param_5
                 )

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uStack_38;
  undefined auStack_34 [8];
  undefined4 uStack_2c;
  int iStack_28;
  
  iStack_28 = _UNK_8111a5b0;
  uStack_2c = 0;
  func_0x81080bb2(auStack_34,param_4);
  *param_2 = 0;
  *param_3 = 0;
  iVar1 = FUN_81078eaa(param_1,param_2,&uStack_38,auStack_34,param_5);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = *(int *)(*param_2 + 0x38);
    if (iVar1 == 0) {
      uStack_38 = 0xffffffff;
    }
    iVar2 = 0;
    if ((-1 < (int)uStack_38) && (iVar2 = 0, uStack_38 < *(uint *)(*(int *)(*param_2 + 0x34) + 8)))
    {
      iVar2 = iVar1 + uStack_38 * 0xc;
    }
    *param_3 = iVar2;
    uVar3 = 1;
  }
  func_0x81005af0(uStack_2c);
  if (_UNK_8111a5b0 == iStack_28) {
    return;
  }
  func_0x811185a0(uVar3);
  uRam81191264 = 0xffffffff;
  return;
}

