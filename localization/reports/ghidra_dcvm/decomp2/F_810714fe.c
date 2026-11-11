
void FUN_810714fe(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 200);
  *(undefined4 *)(param_1 + 200) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  *(undefined4 *)(param_1 + 0xc4) = param_2;
  *(undefined4 *)(param_1 + 0xdc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  return;
}

