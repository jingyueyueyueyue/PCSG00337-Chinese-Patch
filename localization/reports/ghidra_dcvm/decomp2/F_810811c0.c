
void FUN_810811c0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = param_1 + 5;
  FUN_8107db94(puVar1);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  if (puVar1 != param_2) {
    FUN_8107db94(puVar1);
    param_1[6] = param_2[1];
    param_1[5] = *param_2;
    *param_2 = 0;
    param_2[1] = 0;
  }
  FUN_8108101c(param_1);
  return;
}

