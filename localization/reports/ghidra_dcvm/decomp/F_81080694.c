
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81080694(undefined4 *param_1,int param_2,undefined4 param_3,char *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined8 uVar6;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  
  iStack_24 = _UNK_8111a5b0;
  if (*(char *)(param_2 + 0x24) != '\0') {
    *param_1 = 0;
    goto LAB_81080796;
  }
  if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
    *param_1 = 0;
    goto LAB_81080796;
  }
  uStack_38 = 0;
  if (*(int *)(param_2 + 0x30) == 0) {
LAB_81080742:
    piVar4 = *(int **)(param_2 + 0xc);
    (**(code **)(*piVar4 + 8))(piVar4);
    func_0x8107fc04(&uStack_28,param_2);
    uStack_38 = uStack_28;
    iVar1 = func_0x8107f04c(param_2,&uStack_38);
    if (iVar1 == 0) {
      *param_1 = uStack_38;
      (**(code **)(*piVar4 + 0xc))(piVar4);
      goto LAB_81080796;
    }
    func_0x81080042(iVar1 + 0xc,param_4);
    uVar2 = func_0x8107f010(param_2,param_3);
    func_0x8107ff00(uVar2,iVar1);
    (**(code **)(*piVar4 + 0xc))(piVar4);
  }
  else {
    iVar1 = FUN_810794f6(*(int *)(param_2 + 0x30),&uStack_34,&uStack_30,param_4,0x81191264);
    if (iVar1 == 0) goto LAB_81080742;
    piVar4 = *(int **)(param_2 + 0xc);
    (**(code **)(*piVar4 + 8))(piVar4);
    func_0x8107fc04(&uStack_2c,param_2);
    uStack_38 = uStack_2c;
    iVar1 = func_0x8107f04c(param_2,&uStack_38);
    if (iVar1 == 0) {
      *param_1 = uStack_38;
      (**(code **)(*piVar4 + 0xc))(piVar4);
      goto LAB_81080796;
    }
    func_0x8108001a(iVar1 + 0xc,uStack_34,uStack_30);
    uVar2 = func_0x8107f010(param_2,param_3);
    func_0x8107ff00(uVar2,iVar1);
    (**(code **)(*piVar4 + 0xc))(piVar4);
  }
  *param_1 = uStack_38;
LAB_81080796:
  if (_UNK_8111a5b0 == iStack_24) {
    return;
  }
  uVar6 = func_0x811185a0();
  piVar4 = (int *)((ulonglong)uVar6 >> 0x20);
  iVar1 = (int)uVar6;
  piVar5 = (int *)(iVar1 + 0x30);
  if (piVar5 != piVar4) {
    if (*(int *)(iVar1 + 0x30) != 0) {
      if (piVar5 == *(int **)(iVar1 + 0x38)) {
        func_0x81101b54();
      }
      else {
        iVar3 = *(int *)(iVar1 + 0x34);
        (*(int **)(iVar1 + 0x38))[1] = iVar3;
        *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar1 + 0x38);
      }
    }
    *(undefined4 *)(iVar1 + 0x30) = 0;
    *(undefined4 *)(iVar1 + 0x34) = 0;
    *(undefined4 *)(iVar1 + 0x38) = 0;
    iVar3 = *piVar4;
    *(int *)(iVar1 + 0x30) = iVar3;
    if (iVar3 == 0) {
      *(undefined4 *)(iVar1 + 0x34) = 0;
      *(undefined4 *)(iVar1 + 0x38) = 0;
    }
    else {
      *(int **)(iVar1 + 0x34) = piVar4;
      *(int *)(iVar1 + 0x38) = piVar4[2];
      piVar4[2] = (int)piVar5;
      *(int **)(*(int *)(iVar1 + 0x38) + 4) = piVar5;
    }
  }
  return;
}

