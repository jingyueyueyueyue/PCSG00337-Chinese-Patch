
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8107e66e(undefined4 *param_1,int param_2,undefined4 ***param_3,char *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 ***pppuVar6;
  char *pcVar7;
  int unaff_r5;
  undefined8 uVar8;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  int *piStack_68;
  int *piStack_64;
  int iStack_60;
  undefined4 *puStack_5c;
  int iStack_58;
  undefined4 ***pppuStack_54;
  char *pcStack_50;
  undefined *puStack_4c;
  undefined4 uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 ***pppuStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int *piStack_24;
  
  piVar5 = _UNK_8111a5b0;
  piStack_24 = _UNK_8111a5b0;
  pppuVar6 = param_3;
  pcVar7 = param_4;
  if (*(char *)(param_2 + 0x24) == '\0') {
    if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
      *param_1 = 0;
    }
    else {
      piVar5 = *(int **)(param_2 + 0x30);
      uVar4 = (**(code **)(*piVar5 + 0xc))(piVar5);
      iVar1 = func_0x810780e6(uVar4,param_4);
      if (iVar1 == 0) {
        *param_1 = 0;
      }
      else {
        uStack_38 = 0;
        piVar5 = (int *)(**(code **)(*piVar5 + 0xc))(piVar5);
        piVar5 = (int *)(**(code **)(*piVar5 + 0x20))();
        iVar1 = 0;
        if (*piVar5 != 0) {
          uStack_40 = 0x81191264;
          pppuVar6 = &pppuStack_30;
          pcVar7 = param_4;
          iVar1 = FUN_810794f6(*piVar5,&uStack_34,pppuVar6);
        }
        piVar5 = *(int **)(param_2 + 0xc);
        if (iVar1 == 0) {
          (**(code **)(*piVar5 + 8))(piVar5);
          func_0x8107fc04(&uStack_28,param_2);
          uStack_38 = uStack_28;
          unaff_r5 = func_0x8107f04c(param_2,&uStack_38);
          if (unaff_r5 == 0) {
            *param_1 = uStack_38;
            pppuVar6 = *(undefined4 ****)(*piVar5 + 0xc);
            (*(code *)pppuVar6)(piVar5);
            goto LAB_8107e79a;
          }
          func_0x81080042(unaff_r5 + 0xc,param_4);
          uVar4 = func_0x8107f010(param_2,param_3);
          func_0x8107ff00(uVar4,unaff_r5);
          (**(code **)(*piVar5 + 0xc))(piVar5);
        }
        else {
          (**(code **)(*piVar5 + 8))(piVar5);
          func_0x8107fc04(&uStack_2c,param_2);
          uStack_38 = uStack_2c;
          unaff_r5 = func_0x8107f04c(param_2,&uStack_38);
          if (unaff_r5 == 0) {
            *param_1 = uStack_38;
            pppuVar6 = *(undefined4 ****)(*piVar5 + 0xc);
            (*(code *)pppuVar6)(piVar5);
            goto LAB_8107e79a;
          }
          func_0x8108001a(unaff_r5 + 0xc,uStack_34,pppuStack_30);
          uVar4 = func_0x8107f010(param_2,param_3);
          func_0x8107ff00(uVar4,unaff_r5);
          (**(code **)(*piVar5 + 0xc))(piVar5);
          pppuVar6 = pppuStack_30;
        }
        *param_1 = uStack_38;
      }
    }
  }
  else {
    *param_1 = 0;
  }
LAB_8107e79a:
  if (_UNK_8111a5b0 == piStack_24) {
    return;
  }
  uVar8 = func_0x811185a0();
  iVar1 = (int)((ulonglong)uVar8 >> 0x20);
  puVar2 = (undefined4 *)uVar8;
  puStack_4c = &UNK_8111a5b0;
  piStack_68 = _UNK_8111a5b0;
  piStack_64 = piVar5;
  iStack_60 = unaff_r5;
  puStack_5c = param_1;
  iStack_58 = param_2;
  pppuStack_54 = param_3;
  pcStack_50 = param_4;
  if (*(char *)(iVar1 + 0x24) == '\0') {
    if (pcVar7 == (char *)0x0) {
      *puVar2 = 0;
    }
    else {
      uStack_6c = 0;
      piVar5 = *(int **)(iVar1 + 0xc);
      (**(code **)(*piVar5 + 8))(piVar5);
      func_0x8107fc04(&uStack_70,iVar1);
      uStack_6c = uStack_70;
      iVar3 = func_0x8107f04c(iVar1,&uStack_6c);
      if (iVar3 == 0) {
        *puVar2 = uStack_6c;
        (**(code **)(*piVar5 + 0xc))(piVar5);
      }
      else {
        func_0x8108007c(iVar3 + 0xc,pcVar7,uStack_40);
        uVar4 = func_0x8107f010(iVar1,pppuVar6);
        func_0x8107ff00(uVar4,iVar3);
        *puVar2 = uStack_6c;
        (**(code **)(*piVar5 + 0xc))(piVar5);
      }
    }
  }
  else {
    *puVar2 = 0;
  }
  if (_UNK_8111a5b0 == piStack_68) {
    return;
  }
  piVar5 = (int *)func_0x811185a0();
  (**(code **)(*piVar5 + 0xc))();
  return;
}

