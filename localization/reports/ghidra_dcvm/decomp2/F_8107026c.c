
void FUN_8107026c(int param_1,undefined2 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = param_1 + *(int *)(param_1 + 0x1f0) * 8;
  piVar2 = *(int **)(iVar1 + 0xf0);
  *(uint *)(param_1 + 500) = (uint)*(ushort *)(iVar1 + 0xf4);
  if (piVar2 == (int *)0x0) {
    *(undefined4 *)(param_1 + 500) = 0xffffffff;
  }
  else {
    (**(code **)(*piVar2 + 0x1c))();
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0xe8) + 8))(*(int **)(param_1 + 0xe8),param_2);
  if (iVar1 != 0) {
    iVar3 = param_1 + *(int *)(param_1 + 0x1f0) * 8;
    *(int *)(iVar1 + 8) = param_1;
    *(int *)(iVar3 + 0xf0) = iVar1;
    *(ushort *)(iVar3 + 0xf6) = *(ushort *)(iVar3 + 0xf6) & 0xfffe;
    *(undefined2 *)(iVar3 + 0xf4) = param_2;
    func_0x81070f52(param_1,iVar1,(char)*(undefined2 *)(param_1 + 0x1f8));
  }
  return;
}

