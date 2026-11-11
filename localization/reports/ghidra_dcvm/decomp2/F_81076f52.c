
void FUN_81076f52(int param_1,int param_2)

{
  int iVar1;
  
  (**(code **)(*(int *)(param_1 + 0x1c) + 8))(param_1 + 0x1c);
  FUN_81076ee8(param_1);
  *(int *)(param_1 + 8) = param_2;
  if (param_2 == 0) {
    if (((uRam81191260 & 1) == 0) && (iVar1 = func_0x811183f0(0x81191260), iVar1 != 0)) {
      puRam81191230 = &UNK_81145e9c;
      uRam8119125c = 0;
      uRam81191234 = 0;
      uRam81191254 = 0;
      uRam81191258 = 0;
      func_0x8108d650(0x81191238,0,0x1c);
      puRam81191230 = &UNK_81145ed4;
      func_0x81118450(0x81191230,&UNK_81103645,0x811ae7e8);
      func_0x81118240(0x81191260);
    }
    *(undefined4 *)(param_1 + 8) = 0x81191230;
  }
  (**(code **)(*(int *)(param_1 + 0x1c) + 0xc))(param_1 + 0x1c);
  return;
}

