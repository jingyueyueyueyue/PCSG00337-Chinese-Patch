
undefined4 FUN_8106bae4(int param_1,int *param_2)

{
  char cVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  short sVar5;
  
  if (*(int *)(param_1 + 0xf8) < 0) {
    return 0;
  }
  *param_2 = *(int *)(param_1 + 0xf8);
  param_2[1] = *(int *)(param_1 + 0xf4);
  *(undefined2 *)(param_2 + 4) = 0;
  *(undefined2 *)((int)param_2 + 0x12) = 0;
  cVar1 = *(char *)(param_1 + 0xda);
  sVar5 = *(short *)(param_1 + 0x92);
  *(short *)(param_2 + 2) = *(short *)(param_1 + 0x90) + *(short *)(param_1 + 0x98);
  *(short *)((int)param_2 + 10) = sVar5 + *(short *)(param_1 + 0x9a);
  psVar3 = (short *)func_0x8106dda2(param_1 + 0xa8);
  iVar4 = param_2[1];
  if (psVar3 == (short *)0x0) {
LAB_8106bb82:
    if (cVar1 != '\x02') goto LAB_8106bbb0;
  }
  else if ((*(uint *)(param_1 + 0xdc) & 0x10) == 0) {
    *(short *)((int)param_2 + 0x12) = psVar3[1];
    sVar5 = *(short *)((int)param_2 + 10) + psVar3[1];
    *(short *)((int)param_2 + 10) = sVar5;
    if (psVar3[1] < 1) goto LAB_8106bb82;
    *(short *)((int)param_2 + 10) = sVar5 - *(short *)(iVar4 + 0xe);
  }
  else {
    *(short *)(param_2 + 4) = *psVar3;
    sVar5 = *(short *)(param_2 + 2);
    sVar2 = *psVar3;
    *(short *)(param_2 + 2) = sVar5 + sVar2;
    if (*psVar3 < 1) goto LAB_8106bb82;
    *(short *)(param_2 + 2) = (sVar5 + sVar2) - *(short *)(iVar4 + 0xc);
  }
  iVar4 = *(int *)(iVar4 + 4);
  param_2[1] = iVar4;
  if ((iVar4 == 0) && ((*(uint *)(param_1 + 0xdc) & 1) == 0)) {
    iVar4 = func_0x8106d280(param_1 + 0x58,*(int *)(param_1 + 0x5c) + -1);
    param_2[1] = iVar4;
    *param_2 = *param_2 + -1;
  }
  else {
    *param_2 = *(int *)(param_1 + 0x5c) + -1;
  }
LAB_8106bbb0:
  *(undefined2 *)(param_2 + 3) = *(undefined2 *)(param_1 + 0x98);
  *(undefined2 *)((int)param_2 + 0xe) = *(undefined2 *)(param_1 + 0x9a);
  *(undefined *)(param_2 + 5) = 0;
  return 1;
}

