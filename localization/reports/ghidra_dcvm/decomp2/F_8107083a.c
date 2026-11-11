
void FUN_8107083a(int param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4,
                 undefined param_5)

{
  int *piVar1;
  int *piVar2;
  
  *(undefined2 *)(param_1 + 0xc) = param_2;
  *(undefined *)(param_1 + 0x12) = param_5;
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 4) + 8))(*(int **)(param_1 + 4));
  piVar2 = *(int **)(param_1 + 8);
  *(int **)(param_1 + 8) = piVar1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
    piVar1 = *(int **)(param_1 + 8);
  }
  (**(code **)(*piVar1 + 8))(piVar1,param_4);
  *(undefined *)(param_1 + 0x11) = 1;
  return;
}

