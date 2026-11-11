
void FUN_8108170c(int *param_1)

{
  char cVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x12) != '\0') {
    *(undefined *)((int)param_1 + 0x49) = 1;
    FUN_8108cc5c(param_1 + 0xb);
    cVar1 = *(char *)(param_1 + 0x12);
    while ((cVar1 != '\0' && (FUN_8108cfd4(10), *(char *)(param_1 + 0x12) != '\0'))) {
      cVar1 = *(char *)(param_1 + 0x12);
    }
    (**(code **)(param_1[9] + 8))(param_1 + 9);
    while (iVar2 = FUN_8107e09a(param_1 + 2), iVar2 != 0) {
      (**(code **)(*param_1 + 0xc))(param_1,iVar2);
    }
    (**(code **)(param_1[9] + 0xc))(param_1 + 9);
  }
  return;
}

