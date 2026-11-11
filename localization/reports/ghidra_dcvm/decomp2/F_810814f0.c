
undefined4 FUN_810814f0(int *param_1,int *param_2,uint **param_3,int param_4)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  *param_2 = param_4;
  puVar2 = *param_3;
  if ((puVar2 == (uint *)0x0) || ((*puVar2 & 0xf) != 2)) {
    param_1[2] = 3;
    uVar1 = 0;
  }
  else {
    iVar3 = *(int *)(*param_1 + 0xc);
    uVar4 = puVar2[1];
    param_1[2] = 0;
    *param_2 = iVar3 + uVar4 + 8;
    uVar1 = 1;
  }
  return uVar1;
}

