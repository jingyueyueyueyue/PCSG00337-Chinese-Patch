
undefined FUN_8107f588(int param_1,int param_2)

{
  undefined uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0xc);
  (**(code **)(*piVar2 + 8))(piVar2);
  uVar1 = *(undefined *)(*(int *)(param_1 + 0x1c) + param_2 * 0x24 + 0x22);
  (**(code **)(*piVar2 + 0xc))(piVar2);
  return uVar1;
}

