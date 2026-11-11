
void FUN_810a45f6(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2[2] == 3) {
    FUN_810a1a0e(*(undefined4 *)(param_1 + 200),*param_2,0x81191264,2,0);
  }
  else if (param_2[2] == 2) {
    uVar2 = *param_2;
    uVar1 = func_0x810783d6(uVar2,param_2[1]);
    func_0x810a1800(*(undefined4 *)(param_1 + 200),uVar2,uVar1,2,0);
  }
  return;
}

