
int FUN_8109548c(int param_1,uint *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  switch((*param_2 << 0x18) >> 0x1c) {
  case 0:
    iVar3 = *(int *)(param_1 + 0x24) + param_2[1] * 8;
    break;
  case 3:
    uVar2 = param_2[1];
    puVar1 = (undefined4 *)func_0x8109cdfe(*(undefined4 *)(param_1 + 0x40));
    iVar3 = func_0x8109d61e(*puVar1,uVar2);
    break;
  case 4:
    iVar3 = func_0x8109cf2a(*(undefined4 *)(param_1 + 0x40),*param_2 >> 8);
    iVar3 = *(int *)(iVar3 + 0x24) + param_2[1] * 8;
    break;
  case 6:
    uVar2 = param_2[1];
    puVar1 = (undefined4 *)func_0x8109ce4e(*(undefined4 *)(param_1 + 0x40));
    iVar3 = func_0x8109d61e(*puVar1,uVar2);
  }
  return iVar3;
}

