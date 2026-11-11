
void FUN_81076c68(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0x10) != '\x01') {
    *(undefined *)(param_2 + 0x10) = 1;
    if (*(char *)(param_2 + 0x20) != '\0') {
      func_0x810846aa(param_2);
      *(undefined *)(param_2 + 0x20) = 0;
    }
    func_0x81084028(param_2,1);
  }
  if (*(int *)(param_2 + 0x14) != 0) {
    *(undefined4 *)(param_2 + 0x14) = 0;
    if (*(char *)(param_2 + 0x20) != '\0') {
      func_0x810846aa(param_2);
      *(undefined *)(param_2 + 0x20) = 0;
    }
    func_0x810845d0(param_2,0);
  }
  FUN_81075858(param_2);
  if (*(char *)(param_2 + 0x20) != '\0') {
    func_0x810846aa(param_2);
    *(undefined *)(param_2 + 0x20) = 0;
  }
  func_0x8108461e(param_2,0,0);
  if (*(char *)(param_2 + 0x20) != '\0') {
    func_0x810846aa(param_2);
    *(undefined *)(param_2 + 0x20) = 0;
  }
  func_0x81084610(param_2,1,1);
  func_0x8108816e(param_1,param_2);
  return;
}

