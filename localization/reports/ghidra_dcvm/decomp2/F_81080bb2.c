
void FUN_81080bb2(undefined4 *param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = param_1[2];
  param_1[2] = 0;
  func_0x81005af0(uVar1);
  if (param_2 == (undefined *)0x0) {
    param_2 = &UNK_8113743c;
  }
  iVar2 = func_0x81118330(param_2);
  uVar1 = func_0x81005aaa(iVar2 + 1);
  uVar3 = param_1[2];
  param_1[2] = uVar1;
  func_0x81005af0(uVar3);
  func_0x8109d75c(param_1[2],iVar2 + 1,param_2);
  func_0x81080ade(param_1[2]);
  uVar1 = func_0x81118330(param_1[2]);
  *param_1 = uVar1;
  uVar1 = FUN_81081f30(param_1[2],uRam8114a5c4);
  param_1[1] = uVar1;
  return;
}

