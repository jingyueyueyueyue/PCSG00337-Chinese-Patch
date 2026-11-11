
void FUN_81083ade(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if ((*(int *)(param_1 + 0x18) != 0) && (iVar1 = func_0x81087e90(), iVar1 != 0)) {
    func_0x81087d76(*(undefined4 *)(param_1 + 0x18),0);
    iVar1 = *(int *)(param_1 + 4);
    *(undefined *)(iVar1 + 0x2c) = 1;
    piVar2 = **(int ***)(param_1 + 0x18);
    *(int *)(iVar1 + 0x14) = piVar2[6] * piVar2[1] + *piVar2;
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0xc) & 2) != 0)) {
    *(byte *)(iVar1 + 0xc) = *(byte *)(iVar1 + 0xc) & 0xfd;
    *(undefined *)(*(int *)(param_1 + 4) + 0x2c) = 1;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (*(char *)(piVar2 + 0xb) != '\0') {
    piVar3 = (int *)piVar2[5];
    piVar4 = piVar2 + 1;
    *(undefined *)(piVar2 + 0xb) = 0;
    if (piVar3 == (int *)0x0) {
      func_0x81116620(*(undefined4 *)(*piVar2 + 4),0,*(int *)(iRam811ae690 + 4) + 0x58);
    }
    else {
      piVar2[1] = *piVar3;
      piVar2[2] = piVar3[1];
      piVar2[3] = piVar3[2];
      piVar2[4] = piVar3[3];
      func_0x81116890(piVar4,piVar2[7]);
      func_0x81116cd0(piVar4,piVar2[8]);
      func_0x811168a0(piVar4,piVar2[9]);
      func_0x811167c0(piVar4,piVar2[10]);
      if (piVar2[6] != 0) {
        func_0x81116bd0(piVar4);
      }
      func_0x81116620(*(undefined4 *)(**(int **)(param_1 + 4) + 4),0,*(int **)(param_1 + 4) + 1);
    }
  }
  return;
}

