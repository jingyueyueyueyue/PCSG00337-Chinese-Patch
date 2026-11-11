
void FUN_81078c10(int param_1,undefined *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  func_0x81005b02(*(undefined4 *)(param_1 + 0x48));
  if (param_2 == (undefined *)0x0) {
    param_2 = &UNK_8113726c;
  }
  iVar1 = func_0x81118330(param_2);
  uVar2 = func_0x81005aaa(iVar1 + 1);
  *(undefined4 *)(param_1 + 0x48) = uVar2;
  func_0x8109d75c(uVar2,iVar1 + 1,param_2);
  return;
}

