
void FUN_8106e982(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)func_0x81005a98(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &UNK_81145574;
    puVar1[1] = 0;
    iVar2 = *param_3;
    puVar1[2] = iVar2;
    if (iVar2 == 0) {
      puVar1[3] = 0;
      puVar1[4] = 0;
    }
    else {
      puVar1[3] = param_3;
      puVar1[4] = param_3[2];
      param_3[2] = (int)(puVar1 + 2);
      *(undefined4 **)(puVar1[4] + 4) = puVar1 + 2;
    }
    FUN_81080a56(param_1 + 0xc,param_2,puVar1);
  }
  return;
}

