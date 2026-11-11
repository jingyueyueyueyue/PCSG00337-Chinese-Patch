
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810945c0(int **param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_40;
  int *piStack_3c;
  int *piStack_38;
  undefined auStack_34 [8];
  undefined4 uStack_2c;
  int iStack_28;
  
  iStack_28 = _UNK_8111a5b0;
  if ((cRam811adc20 == '\0') ||
     (piVar1 = (int *)func_0x8108c682(param_2,param_4,param_3), piVar1 == (int *)0x0)) {
    uStack_2c = 0;
    func_0x81080bb2(auStack_34,0);
    func_0x81080c16(auStack_34,&UNK_8113813c,param_2);
    iVar2 = func_0x81117140(0,uStack_2c);
    if (iVar2 < 1) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    piStack_38 = (int *)(**(code **)(*param_3 + 0xc))(param_3,iVar2,param_3 + 9,param_3[1]);
    piStack_3c = param_3;
    if (piStack_38 == (int *)0x0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    iVar3 = func_0x81117190(0,&uStack_40,uStack_2c,0);
    if (iVar3 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    iVar3 = func_0x81117120(0,uStack_40,piStack_38);
    if (iVar3 < 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    iVar3 = func_0x811170f0(0,uStack_40);
    if (iVar3 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    if (param_4 != (int *)0x0) {
      *param_4 = iVar2;
    }
    *param_1 = piStack_3c;
    param_1[1] = piStack_38;
    piStack_3c = (int *)0x0;
    piStack_38 = (int *)0x0;
    func_0x8107db94(&piStack_3c);
    func_0x81005af0(uStack_2c);
  }
  else {
    *param_1 = param_3;
    param_1[1] = piVar1;
  }
  if (_UNK_8111a5b0 == iStack_28) {
    return;
  }
  func_0x811185a0();
  return;
}

