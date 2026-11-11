
undefined4 FUN_8107a75e(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (((uRam81191290 & 1) == 0) && (iVar1 = func_0x811183f0(0x81191290), iVar1 != 0)) {
    puRam81191270 = &UNK_81145cb0;
    uRam81191278 = 0;
    uRam8119127c = 1;
    uRam81191274 = 0;
    func_0x81118450(0x81191270,&UNK_81104921,0x811ae7e8);
    func_0x81118240(0x81191290);
  }
  uVar3 = 0x81191270;
  if ((-1 < param_2) && (param_2 < 8)) {
    param_1 = param_1 + param_2 * 4;
    piVar2 = *(int **)(param_1 + 0x14);
    if ((piVar2 != (int *)0x0) && (iVar1 = (**(code **)(*piVar2 + 0x14))(), iVar1 != 0)) {
      uVar3 = *(undefined4 *)(param_1 + 0x14);
    }
  }
  return uVar3;
}

