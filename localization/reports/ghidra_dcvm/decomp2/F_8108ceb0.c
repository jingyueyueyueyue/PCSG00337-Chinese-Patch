
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8108ceb0(int **param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 uint param_5)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  undefined4 uVar3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int *piStack_20;
  int iStack_1c;
  
  iStack_1c = _UNK_8111a5b0;
  if (0x69 < param_5) {
    param_5 = 0x69;
  }
  fVar2 = (float)VectorUnsignedToFloat(param_5,(byte)(in_fpscr >> 0x15) & 3);
  uVar3 = VectorFloatToUnsigned((fVar2 / 105.0) * 127.0 + 64.0,3);
  iVar1 = func_0x811186d0(param_1[1],0x8108d19d,uVar3,param_4,0,0x70000,0);
  piStack_20 = *param_1;
  *piStack_20 = iVar1;
  if (*piStack_20 < 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  uStack_28 = param_3;
  uStack_24 = param_2;
  iVar1 = func_0x81118750(*piStack_20,0xc,&uStack_28);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (_UNK_8111a5b0 == iStack_1c) {
    return;
  }
  func_0x811185a0();
  return;
}

