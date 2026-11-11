
void FUN_8108184c(int param_1)

{
  char cVar1;
  
  FUN_8108170c();
  *(undefined *)(param_1 + 0x49) = 0;
  *(undefined *)(param_1 + 0x48) = 0;
  *(undefined **)(param_1 + 0x34) = &UNK_81137440;
  FUN_8108ceb0(param_1 + 0x30,&UNK_810d608d,param_1 + 0x38,*(undefined4 *)(param_1 + 0x20),0xf);
  cVar1 = *(char *)(param_1 + 0x48);
  while (cVar1 == '\0') {
    FUN_8108cfd4(1);
    cVar1 = *(char *)(param_1 + 0x48);
  }
  return;
}

