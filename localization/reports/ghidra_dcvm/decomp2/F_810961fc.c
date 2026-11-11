
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810961fc(undefined4 param_1,undefined4 param_2,int param_3,uint *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 in_cr0;
  undefined4 in_cr7;
  undefined8 uVar4;
  int iStack_118;
  int iStack_114;
  undefined auStack_110 [256];
  int iStack_10;
  
  iStack_10 = _UNK_8111a5b0;
  uVar3 = *param_4 & 0xf;
  switch(uVar3) {
  case 0:
    break;
  case 1:
    func_0x811182c0(auStack_110,&UNK_81138194,param_4[1]);
    break;
  case 2:
    coprocessor_function(10,0xb,6,in_cr0,in_cr7,in_cr0);
    func_0x811182c0(auStack_110,&UNK_81138198,param_4[1],param_2);
    break;
  case 3:
    if ((uVar3 != 6) && (func_0x810964f6(param_4,&iStack_118,&iStack_114), iStack_114 != 0)) {
      if (*(int *)(*(int *)(param_3 + 0x28) + 0x74) == iStack_118) {
        func_0x8109b066();
      }
      else {
        puVar1 = (undefined4 *)func_0x8109ca34(*(undefined4 *)(param_3 + 0x40));
        uVar2 = func_0x8109c2ae(*puVar1,iStack_118);
        func_0x8109b066(uVar2,iStack_114);
      }
    }
    break;
  case 4:
    if ((*param_4 & 0xf0) != 0x20) {
      func_0x811182c0(auStack_110,&UNK_811381ac,param_4[1]);
    }
    break;
  default:
    *(undefined **)(param_3 + 0x38) = &UNK_81096439;
    *(undefined4 *)(param_3 + 0x34) = 3;
  }
  if (_UNK_8111a5b0 != iStack_10) {
    uVar4 = func_0x811185a0();
    *(int *)((int)uVar4 + 0x5c) = (int)((ulonglong)uVar4 >> 0x20);
    return;
  }
  return;
}

