
int FUN_8108c1f2(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 < *(byte *)(param_1 + (uint)*(byte *)(param_1 + 0x201a) + 0x2018)) {
    iVar2 = param_1 + (uint)*(byte *)(param_1 + 0x201a) * 0x700 + param_2 * 0x70 + 0x1218;
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = iVar2;
  }
  return iVar1;
}

