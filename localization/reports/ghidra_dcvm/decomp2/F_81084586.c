
void FUN_81084586(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x1c00000;
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 2:
    uVar1 = 0x800000;
    break;
  case 3:
    uVar1 = 0x1400000;
    break;
  case 4:
    uVar1 = 0x1000000;
    break;
  case 5:
    uVar1 = 0x1800000;
    break;
  case 6:
    uVar1 = 0x400000;
    break;
  case 7:
    uVar1 = 0xc00000;
  }
  func_0x811167d0(*(undefined4 *)(**(int **)(param_1 + 4) + 4),uVar1);
  return;
}

