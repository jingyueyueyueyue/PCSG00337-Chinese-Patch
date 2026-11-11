
void FUN_81070776(int param_1,undefined4 *param_2)

{
  int *piVar1;
  
  if ((undefined4 *)(param_1 + 0xe8) != param_2) {
    piVar1 = *(int **)(param_1 + 0xe8);
    *(undefined4 *)(param_1 + 0xe8) = *param_2;
    *param_2 = 0;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))();
    }
  }
  return;
}

