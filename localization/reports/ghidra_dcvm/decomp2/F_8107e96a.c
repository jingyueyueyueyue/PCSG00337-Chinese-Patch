
undefined4 FUN_8107e96a(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = (**(code **)(*param_1 + 0xc))();
  uVar2 = 0;
  if (param_2[2] == 3) {
    uVar2 = func_0x81078072(uVar1,*param_2,0x81191264,0);
  }
  else if (param_2[2] == 2) {
    uVar3 = *param_2;
    uVar2 = func_0x810783d6(uVar3,param_2[1]);
    uVar2 = func_0x810780ac(uVar1,uVar3,uVar2,0);
  }
  return uVar2;
}

