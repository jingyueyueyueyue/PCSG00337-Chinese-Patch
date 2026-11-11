
undefined4
FUN_8109c978(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = func_0x81005a98(100);
  if ((iVar1 == 0) || (iVar1 = func_0x81094940(), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(iVar1 + 0x40) = param_1;
    iVar3 = func_0x81095624(iVar1,0x400);
    if (iVar3 == 0) {
      func_0x81094e48(iVar1);
      func_0x81005af0();
      uVar2 = 0;
    }
    else {
      func_0x810949fe(iVar1,1);
      func_0x81095f72(iVar1,param_3,param_4,param_5,param_6,1);
      while( true ) {
        func_0x81095606(iVar1);
        iVar3 = *(int *)(iVar1 + 0x34);
        if ((iVar3 != 1) && (iVar3 != 0)) break;
        func_0x8108cfd4(10);
      }
      if (iVar3 == 3) {
        if (iVar1 != 0) {
          func_0x81094e48(iVar1);
          func_0x81005af0();
        }
        uVar2 = 0;
      }
      else {
        *param_2 = *(undefined4 *)(iVar1 + 0x2c);
        param_2[1] = *(undefined4 *)(iVar1 + 0x30);
        if (iVar1 != 0) {
          func_0x81094e48(iVar1);
          func_0x81005af0();
        }
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}

