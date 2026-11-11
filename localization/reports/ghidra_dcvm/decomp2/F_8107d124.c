
void FUN_8107d124(void)

{
  iRam81191354 = 0;
  uRam81191358 = 0;
  iRam81191354 = func_0x81005a98(0x30);
  if (iRam81191354 != 0) {
    *(int *)iRam81191354 = iRam81191354;
  }
  if (iRam81191354 != -4) {
    *(int *)(iRam81191354 + 4) = iRam81191354;
  }
  if (iRam81191354 != -8) {
    *(int *)(iRam81191354 + 8) = iRam81191354;
  }
  *(undefined *)(iRam81191354 + 0x2d) = 1;
  *(undefined *)(iRam81191354 + 0x2c) = 1;
  func_0x81118450(0x81191350,&UNK_81104d65,0x811ae7e8);
  return;
}

