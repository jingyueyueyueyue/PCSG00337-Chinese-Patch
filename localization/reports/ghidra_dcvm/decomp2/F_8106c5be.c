
void FUN_8106c5be(int param_1,uint param_2)

{
  if (*(short *)(param_1 + 0xa4) != *(short *)(param_1 + 0xa6)) {
    if ((*(uint *)(param_1 + 0x104) & param_2) == 0) {
      if ((*(uint *)(param_1 + 0x108) & param_2) != 0) {
        *(undefined2 *)(param_1 + 0xe8) = 2;
      }
    }
    else {
      *(undefined2 *)(param_1 + 0xe8) = 1;
    }
  }
  FUN_8106ebd6();
  return;
}

