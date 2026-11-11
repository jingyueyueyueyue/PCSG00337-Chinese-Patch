
void FUN_8106c9c2(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 4);
  if (((iVar1 == -0x7fffffe0) || (iVar1 == -0x7fffffdf)) || (iVar1 == -0x7fffffde)) {
    *(undefined *)(param_1 + 0xd9) = 0;
  }
  FUN_8106e9d0();
  return;
}

