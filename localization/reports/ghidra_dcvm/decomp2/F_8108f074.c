
void FUN_8108f074(uint *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  code *pcVar3;
  
  uVar1 = uRam81191408;
  FUN_81094444(uRam81191408,1,0);
  uVar2 = *param_1;
  if ((-1 < (int)uVar2) && (uVar2 < 0x10)) {
    pcVar3 = *(code **)(uVar2 * 8 + -0x7ee6ebf0);
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(param_1,*(undefined4 *)(uVar2 * 8 + -0x7ee6ebf4));
    }
  }
  FUN_81094472(uVar1,1);
  return;
}

