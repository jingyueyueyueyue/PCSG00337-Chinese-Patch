
undefined4 FUN_810b279a(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined2 uStack_48;
  undefined2 uStack_46;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  undefined2 uStack_18;
  undefined2 uStack_16;
  
  (**(code **)(*param_1 + 0x1c))();
  if (iRam811ae028 != 0) {
    iVar2 = -0x79fffffc;
    goto LAB_810b2bf4;
  }
  switch(param_1[3]) {
  case 0:
    iVar2 = func_0x810b2368(param_1);
    break;
  case 1:
    func_0x810b7ae4(param_1 + 0x12);
    iVar2 = func_0x81117560(*(undefined2 *)(param_1 + 0xe),20000000,20000000,0);
    if (-1 < iVar2) {
      piVar3 = param_1 + 3;
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = 2;
    }
    break;
  case 2:
    iVar2 = func_0x810b2300(param_1);
    break;
  case 3:
    iVar2 = func_0x810b22aa(param_1);
    break;
  case 4:
    iVar2 = func_0x810c5bac();
    if (iVar2 == 0) {
      piVar3 = param_1 + 3;
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = 5;
    }
    goto LAB_810b2bfc;
  case 5:
    iVar2 = func_0x810b21be(param_1);
    break;
  case 6:
    iVar2 = func_0x810c5bd0();
    if (iVar2 == 0) {
      if (*(short *)((int)param_1 + 0x3a) == 0) {
        *(undefined2 *)((int)param_1 + 0x3a) = 1;
      }
      piVar3 = param_1 + 3;
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = 7;
    }
    goto LAB_810b2bfc;
  case 7:
    func_0x810b7ae4(param_1 + 0x15);
    piVar3 = param_1 + 3;
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = 8;
    goto LAB_810b2bfc;
  case 8:
    iVar2 = func_0x810b2114(param_1);
    break;
  case 9:
    iVar2 = func_0x810b11fc(param_1);
    break;
  case 10:
    if ((param_1[0x2a] & 0x100000U) != 0) {
      if ((param_1[0x2a] & 0x400000U) != 0) {
        iVar2 = -0x79fffffd;
        if (param_1[0x2b] != 0) {
          iVar2 = param_1[0x2b];
        }
        break;
      }
      piVar3 = param_1 + 3;
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = 0xb;
    }
    iVar2 = 0;
    break;
  case 0xb:
    func_0x810b1150(param_1);
    goto LAB_810b2bfc;
  case 0xc:
    iVar2 = func_0x810b0efc(param_1);
    break;
  case 0xd:
    iVar2 = func_0x810b0d12(param_1);
    break;
  case 0xe:
    if ((param_1[0x2a] & 0x100000U) != 0) {
      if ((param_1[0x2a] & 0x400000U) != 0) {
        iVar2 = -0x79fffff7;
        if (param_1[0x2b] != 0) {
          iVar2 = param_1[0x2b];
        }
        break;
      }
      if ((param_1[0x2d] & 0x400U) == 0) {
        piVar3 = param_1 + 3;
        do {
          ExclusiveAccess(piVar3);
          bVar1 = (bool)hasExclusiveAccess(piVar3);
        } while (!bVar1);
        *piVar3 = 0x10;
      }
      else {
        piVar3 = param_1 + 3;
        do {
          ExclusiveAccess(piVar3);
          bVar1 = (bool)hasExclusiveAccess(piVar3);
        } while (!bVar1);
        *piVar3 = 0x11;
      }
    }
    iVar2 = 0;
    break;
  case 0xf:
    iVar2 = func_0x810b0bfa(param_1);
    break;
  case 0x10:
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_2e = 0;
    uStack_30 = 10;
    uStack_44 = 6;
    uStack_40 = 0x2e;
    (**(code **)(*param_1 + 0xc))(param_1,&uStack_44);
    goto LAB_810b2bfc;
  case 0x11:
    iVar2 = func_0x810b0b3c(param_1);
    break;
  case 0x12:
    iVar2 = func_0x810b0888(param_1);
    break;
  case 0x13:
    if ((param_1[0x2a] & 0x100000U) != 0) {
      if ((param_1[0x2a] & 0x400000U) != 0) {
        iVar2 = -0x79fffff5;
        if (param_1[0x2b] != 0) {
          iVar2 = param_1[0x2b];
        }
        break;
      }
      piVar3 = param_1 + 3;
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = 0x14;
    }
    iVar2 = 0;
    break;
  case 0x14:
    func_0x810b074c(param_1);
  default:
    goto LAB_810b2bfc;
  case 0x16:
    func_0x810b7ae4(param_1 + 0x2a);
    uStack_78 = 0;
    uStack_74 = 0;
    uStack_70 = 0;
    uStack_6c = 0;
    uStack_68 = 0;
    uStack_64 = 0;
    uStack_80 = *(undefined4 *)param_1[0x31];
    uStack_7c = ((undefined4 *)param_1[0x31])[1];
    iVar2 = func_0x81117590(*(undefined2 *)(param_1 + 0xe),&uStack_80,0,&iStack_60);
    if (-1 < iVar2) {
      piVar3 = param_1 + 3;
      param_1[0x2c] = iStack_60;
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = 0x17;
    }
    break;
  case 0x17:
    if ((param_1[0x2a] & 0x100000U) == 0) {
code_r0x810b2a72:
      iVar2 = 0;
    }
    else {
      iVar2 = param_1[0x2b];
      if (param_1[0x2b] == 0) {
        if ((param_1[0x2a] & 0x400000U) == 0) {
          piVar3 = param_1 + 3;
          do {
            ExclusiveAccess(piVar3);
            bVar1 = (bool)hasExclusiveAccess(piVar3);
          } while (!bVar1);
          *piVar3 = 0x18;
          goto code_r0x810b2a72;
        }
        iVar2 = -0x79fffff2;
      }
    }
    break;
  case 0x18:
    piVar3 = param_1 + 3;
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = 0x19;
    goto LAB_810b2bfc;
  case 0x19:
    piVar3 = param_1 + 3;
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = 0x1a;
    goto LAB_810b2bfc;
  case 0x1a:
    if (((param_1[0x2d] & 0x200U) == 0) || (param_1[0x40] != 0)) {
      piVar3 = param_1 + 3;
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = 0x1b;
    }
    else {
      piVar3 = param_1 + 3;
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = 0x20;
    }
    goto LAB_810b2bfc;
  case 0x1b:
    func_0x810b7ae4(param_1 + 0x15);
    iVar2 = func_0x811174d0(*(undefined2 *)(param_1 + 0xe));
    if (iVar2 == 0) {
      piVar3 = param_1 + 3;
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = 0x1c;
    }
    else {
      if (param_1[0x40] == 0) {
        piVar3 = param_1 + 3;
        do {
          ExclusiveAccess(piVar3);
          bVar1 = (bool)hasExclusiveAccess(piVar3);
        } while (!bVar1);
        *piVar3 = 0x20;
      }
      else {
        piVar3 = param_1 + 3;
        do {
          ExclusiveAccess(piVar3);
          bVar1 = (bool)hasExclusiveAccess(piVar3);
        } while (!bVar1);
        *piVar3 = 0x1e;
      }
      func_0x810b7ae4(param_1 + 0x12);
      *(undefined *)((int)param_1 + 0x45) = 0;
    }
    break;
  case 0x1c:
    if (((param_1[0x12] & 1U) != 0) && ((param_1[0x12] & 4U) != 0)) {
      if (param_1[0x40] == 0) {
        piVar3 = param_1 + 3;
        do {
          ExclusiveAccess(piVar3);
          bVar1 = (bool)hasExclusiveAccess(piVar3);
        } while (!bVar1);
        *piVar3 = 0x20;
      }
      else {
        piVar3 = param_1 + 3;
        do {
          ExclusiveAccess(piVar3);
          bVar1 = (bool)hasExclusiveAccess(piVar3);
        } while (!bVar1);
        *piVar3 = 0x1e;
      }
      func_0x810b7ae4(param_1 + 0x12);
    }
    goto LAB_810b2bfc;
  case 0x1e:
    uStack_16 = 0;
    uStack_24 = 0;
    uStack_1c = 0;
    uStack_18 = 10;
    iStack_20 = param_1[0x40];
    uStack_2c = 6;
    uStack_28 = 0x2f;
    if (*(short *)(param_1 + 0xe) != 0) {
      func_0x811174c0();
    }
    func_0x810c51fc(param_1 + 5);
    param_1[0x40] = 0;
    (**(code **)(*param_1 + 0xc))(param_1,&uStack_2c);
    goto LAB_810b2bfc;
  case 0x1f:
    FUN_810b0020(param_1);
    goto LAB_810b2bfc;
  case 0x20:
    if (*(char *)(param_1 + 0x39) == '\0') {
      uStack_54 = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_46 = 0;
      uStack_48 = 10;
      uStack_5c = 6;
      uStack_58 = 0x30;
      (**(code **)(*param_1 + 0xc))(param_1,&uStack_5c);
    }
    goto LAB_810b2bfc;
  }
  if (iVar2 != 0) {
LAB_810b2bf4:
    func_0x810ad5c6(param_1,iVar2);
  }
LAB_810b2bfc:
  (**(code **)(*param_1 + 0x20))(param_1);
  return 0;
}

