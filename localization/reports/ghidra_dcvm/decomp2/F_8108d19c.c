
undefined4 FUN_8108d19c(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (*(code *)param_2[1])(*param_2);
  *(undefined4 *)param_2[2] = 0xffffffff;
  iVar2 = func_0x81118820(uVar1);
  if (-1 < iVar2) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  return uVar1;
}

