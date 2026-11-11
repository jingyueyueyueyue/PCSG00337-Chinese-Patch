
undefined4 FUN_81081c4c(byte *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  bVar1 = param_1[1];
  iVar2 = (**(code **)(&UNK_81138ee4 + iRam811913c8 * 4))(*param_1);
  if ((iVar2 == 0) || (iVar2 = (**(code **)(&UNK_81138eec + iRam811913c8 * 4))(bVar1), iVar2 == 0))
  {
    uVar4 = (uint)*param_1;
  }
  else {
    uVar4 = (uint)CONCAT11(*param_1,param_1[1]);
  }
  if ((uVar4 < 0x8281) || (0x829a < uVar4)) {
    uVar3 = 0;
    if ((0x825f < uVar4) && (uVar4 < 0x827a)) {
      uVar3 = *(undefined4 *)(&UNK_81129c80 + uVar4 * 4);
    }
  }
  else {
    uVar3 = *(undefined4 *)(&UNK_81129c64 + uVar4 * 4);
  }
  return uVar3;
}

