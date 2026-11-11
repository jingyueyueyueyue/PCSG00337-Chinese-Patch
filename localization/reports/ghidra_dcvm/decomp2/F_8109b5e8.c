
int * FUN_8109b5e8(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  iVar1 = func_0x81005a98(0x7c);
  if ((iVar1 != 0) && (piVar2 = (int *)FUN_8109ae02(), piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 0xc))(piVar2,param_1 + 0xc);
    if (piVar2 + 0x14 != (int *)(param_1 + 0x50)) {
      func_0x810c8628(piVar2 + 0x14,(int *)(param_1 + 0x50),0,0xffffffff);
    }
    piVar2[0x1b] = *(int *)(param_1 + 0x6c);
  }
  return piVar2;
}

