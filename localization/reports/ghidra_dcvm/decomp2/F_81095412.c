
void FUN_81095412(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)func_0x8109cdfe(*(undefined4 *)(param_1 + 0x40));
  uVar3 = *puVar1;
  if (((uRam811adc38 & 1) == 0) && (iVar2 = func_0x811183f0(0x811adc38), iVar2 != 0)) {
    func_0x8109cf58(0x811adc28);
    func_0x81118450(0x811adc28,&UNK_8110b3e1,0x811ae7e8);
    func_0x81118240(0x811adc38);
  }
  func_0x8109d338(uVar3,param_2);
  return;
}

