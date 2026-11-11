
uint FUN_8107d2d4(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  
  pcVar4 = *(code **)(*param_1 + 8);
  do {
    uVar1 = (*pcVar4)(param_1);
    uVar2 = func_0x810c83e2(uVar1,0x80000001);
    pcVar4 = *(code **)(*param_1 + 8);
  } while (0x7fffffff < uVar2);
  uVar3 = (*pcVar4)(param_1);
  if ((uVar3 & 1) != 0) {
    uVar2 = -uVar2;
  }
  return uVar2;
}

