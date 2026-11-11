
undefined4 FUN_8107b0c6(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (((uRam81191298 & 1) == 0) && (iVar1 = func_0x811183f0(0x81191298), iVar1 != 0)) {
    puRam8119129c = &UNK_81145d38;
    uRam811912a0 = 1;
    uRam811912a4 = 0;
    func_0x81118450(0x8119129c,&UNK_81104961,0x811ae7e8);
    func_0x81118240(0x81191298);
  }
  uVar3 = 0x8119129c;
  if ((-1 < param_2) && (param_2 < 8)) {
    param_1 = param_1 + param_2 * 4;
    piVar2 = *(int **)(param_1 + 0x14);
    if ((piVar2 != (int *)0x0) && (iVar1 = (**(code **)(*piVar2 + 8))(), iVar1 != 0)) {
      uVar3 = *(undefined4 *)(param_1 + 0x14);
    }
  }
  return uVar3;
}

