
int FUN_81081d84(byte *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  bVar1 = param_1[1];
  iVar2 = (**(code **)(&UNK_81138ee4 + iRam811913c8 * 4))(*param_1);
  if ((iVar2 == 0) || (iVar2 = (**(code **)(&UNK_81138eec + iRam811913c8 * 4))(bVar1), iVar2 == 0))
  {
    uVar3 = (uint)*param_1;
  }
  else {
    uVar3 = (uint)CONCAT11(*param_1,param_1[1]);
  }
  if (((uVar3 < 0x824f) || (0x8258 < uVar3)) ||
     (iVar2 = *(int *)(&UNK_81129c9c + uVar3 * 4), iVar2 == 0)) {
    bVar1 = param_1[1];
    iVar2 = (**(code **)(&UNK_81138ee4 + iRam811913c8 * 4))(*param_1);
    if ((iVar2 == 0) || (iVar2 = (**(code **)(&UNK_81138eec + iRam811913c8 * 4))(bVar1), iVar2 == 0)
       ) {
      uVar3 = (uint)*param_1;
    }
    else {
      uVar3 = (uint)CONCAT11(*param_1,param_1[1]);
    }
    if ((uVar3 < 0x8281) || (0x829a < uVar3)) {
      iVar2 = 0;
      if ((0x825f < uVar3) && (uVar3 < 0x827a)) {
        iVar2 = *(int *)(&UNK_81129c80 + uVar3 * 4);
      }
    }
    else {
      iVar2 = *(int *)(&UNK_81129c64 + uVar3 * 4);
    }
  }
  return iVar2;
}

