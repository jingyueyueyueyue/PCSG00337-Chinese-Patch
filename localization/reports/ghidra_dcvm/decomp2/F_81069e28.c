
bool FUN_81069e28(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  iVar2 = param_1 + 0x24;
  (**(code **)(*(int *)(param_1 + 0x24) + 8))(iVar2);
  iVar1 = *(int *)(param_1 + 0x24);
  if ((*param_2 == *(char *)(*(int *)(param_1 + 0x1ac) + (uint)(byte)param_2[1])) &&
     (iVar3 = *(int *)(param_1 + 0x198) + (uint)(byte)param_2[1] * 8, iVar3 != 0)) {
    *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) | 1;
    bVar4 = (*(uint *)(iVar3 + 4) & 2) == 0;
    (**(code **)(iVar1 + 0xc))(iVar2);
  }
  else {
    (**(code **)(iVar1 + 0xc))(iVar2);
    bVar4 = true;
  }
  return bVar4;
}

