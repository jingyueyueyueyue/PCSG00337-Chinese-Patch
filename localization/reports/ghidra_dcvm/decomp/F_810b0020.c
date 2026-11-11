
void FUN_810b0020(int *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iStack_f0;
  int iStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  int iStack_e0;
  int iStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  int iStack_c8;
  int iStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  int iStack_a8;
  int iStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined2 uStack_8c;
  undefined2 uStack_8a;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined2 uStack_74;
  undefined2 uStack_72;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  undefined4 uStack_60;
  undefined2 uStack_5c;
  undefined2 uStack_5a;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  undefined2 uStack_42;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  iVar3 = 1;
  switch(param_1[4]) {
  case 0:
    iStack_64 = FUN_810aff10(param_1);
    break;
  case 1:
    if ((param_1[0x1b] & 0x100000U) != 0) {
      if ((param_1[0x1b] & 0x400000U) != 0) {
        iStack_64 = -0x79ffffea;
        if (param_1[0x1c] != 0) {
          iStack_64 = param_1[0x1c];
        }
        break;
      }
      piVar2 = param_1 + 4;
      do {
        ExclusiveAccess(piVar2);
        bVar1 = (bool)hasExclusiveAccess(piVar2);
      } while (!bVar1);
      *piVar2 = 2;
    }
    iStack_64 = 0;
    break;
  case 2:
    uStack_98 = 0;
    uStack_94 = 0;
    uStack_90 = 0;
    uStack_8a = 0;
    uStack_8c = 10;
    uStack_a0 = 6;
    uStack_9c = 0x31;
    (**(code **)(*param_1 + 0xc))(param_1,&uStack_a0);
    return;
  case 3:
    uStack_bc = 0;
    uStack_b8 = 0;
    uStack_ac = 0;
    iStack_c8 = param_1[0x4a];
    iStack_c4 = param_1[0x4b];
    uStack_c0 = 1;
    uStack_b4 = 0x8114b388;
    uStack_b0 = 6;
    func_0x81117510(*(undefined2 *)(param_1 + 0xe),&iStack_c8,0,param_1 + 0x4f);
    param_1 = param_1 + 4;
    do {
      ExclusiveAccess(param_1);
      bVar1 = (bool)hasExclusiveAccess(param_1);
    } while (!bVar1);
    *param_1 = -1;
    return;
  case 4:
    iStack_64 = func_0x810aeaa4(param_1);
    iVar3 = 3;
    break;
  case 5:
    return;
  case 6:
    func_0x810ad478(param_1);
    param_1 = param_1 + 4;
    do {
      ExclusiveAccess(param_1);
      bVar1 = (bool)hasExclusiveAccess(param_1);
    } while (!bVar1);
    *param_1 = -1;
    return;
  case 7:
    iStack_64 = -0x79ffffe6;
    iVar3 = 3;
    goto code_r0x810b0440;
  case 8:
    iStack_64 = func_0x810aeea2(param_1);
    iVar3 = 2;
    break;
  case 9:
    iStack_64 = 0;
    if ((param_1[0x21] & 0x100000U) != 0) {
      if ((param_1[0x21] & 0x400000U) == 0) {
        piVar2 = param_1 + 4;
        do {
          ExclusiveAccess(piVar2);
          bVar1 = (bool)hasExclusiveAccess(piVar2);
        } while (!bVar1);
        *piVar2 = 10;
      }
      else {
        piVar2 = param_1 + 4;
        do {
          ExclusiveAccess(piVar2);
          bVar1 = (bool)hasExclusiveAccess(piVar2);
        } while (!bVar1);
        *piVar2 = -1;
        iStack_64 = -0x79ffffea;
        if (param_1[0x22] != 0) {
          iStack_64 = param_1[0x22];
        }
      }
    }
    if (param_1[0x41] == 1) {
      iStack_64 = 0;
    }
    iVar3 = 2;
    break;
  case 10:
    uStack_20 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_12 = 0;
    uStack_14 = 10;
    uStack_28 = 6;
    uStack_24 = 0x32;
    piVar2 = param_1 + 4;
    (**(code **)(*param_1 + 0xc))(param_1,&uStack_28);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = -1;
    return;
  case 0xb:
    func_0x810b7ae4(param_1 + 0x24);
    iStack_f0 = param_1[0x4a];
    iStack_ec = param_1[0x4b];
    uStack_e8 = 0x811ae57e;
    uRam811ae57e = 0x57;
    uRam811ae580 = 0x58;
    uStack_e4 = 2;
    iStack_64 = func_0x81117580(*(undefined2 *)(param_1 + 0xe),&iStack_f0,0,&iStack_a8);
    if (iStack_64 < 0) {
      piVar2 = param_1 + 4;
      do {
        ExclusiveAccess(piVar2);
        bVar1 = (bool)hasExclusiveAccess(piVar2);
      } while (!bVar1);
      *piVar2 = -1;
    }
    else {
      piVar2 = param_1 + 4;
      param_1[0x26] = iStack_a8;
      do {
        ExclusiveAccess(piVar2);
        bVar1 = (bool)hasExclusiveAccess(piVar2);
      } while (!bVar1);
      *piVar2 = 0xc;
      iStack_64 = 0;
    }
    iVar3 = 2;
    break;
  case 0xc:
    if ((param_1[0x24] & 0x100000U) == 0) {
code_r0x810b03d0:
      iStack_64 = 0;
    }
    else {
      if ((param_1[0x24] & 0x400000U) == 0) {
        piVar2 = param_1 + 4;
        do {
          ExclusiveAccess(piVar2);
          bVar1 = (bool)hasExclusiveAccess(piVar2);
        } while (!bVar1);
        *piVar2 = 0xd;
        goto code_r0x810b03d0;
      }
      piVar2 = param_1 + 4;
      do {
        ExclusiveAccess(piVar2);
        bVar1 = (bool)hasExclusiveAccess(piVar2);
      } while (!bVar1);
      *piVar2 = -1;
      iStack_64 = -0x79ffffea;
      if (param_1[0x25] != 0) {
        iStack_64 = param_1[0x25];
      }
    }
    iVar3 = 2;
    break;
  case 0xd:
    uStack_50 = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_42 = 0;
    uStack_44 = 10;
    uStack_58 = 6;
    uStack_54 = 0x32;
    piVar2 = param_1 + 4;
    (**(code **)(*param_1 + 0xc))(param_1,&uStack_58);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = -1;
    return;
  case 0xe:
    iStack_e0 = 0;
    iStack_dc = 0;
    uStack_d8 = 0;
    uStack_d4 = 0;
    uStack_d0 = 0;
    uStack_cc = 0;
    func_0x810b7ae4(param_1 + 0x1e);
    iStack_e0 = param_1[0x4a];
    iStack_dc = param_1[0x4b];
    uStack_d8 = CONCAT22(uStack_d8._2_2_,*(undefined2 *)(param_1[0x34] + 2));
    uRam811ae582 = 0x59;
    uStack_d0 = 0x811ae582;
    uStack_cc = 1;
    iStack_64 = func_0x811174a0(*(undefined2 *)(param_1 + 0xe),&iStack_e0,0,&iStack_a4);
    if (iStack_64 < 0) {
      piVar2 = param_1 + 4;
      do {
        ExclusiveAccess(piVar2);
        bVar1 = (bool)hasExclusiveAccess(piVar2);
      } while (!bVar1);
      *piVar2 = -1;
      if (param_1[0x41] == 1) {
        iStack_64 = 0;
      }
    }
    else {
      piVar2 = param_1 + 4;
      param_1[0x20] = iStack_a4;
      do {
        ExclusiveAccess(piVar2);
        bVar1 = (bool)hasExclusiveAccess(piVar2);
      } while (!bVar1);
      *piVar2 = 0xf;
      iStack_64 = 0;
    }
    iVar3 = 2;
    break;
  case 0xf:
    iStack_64 = 0;
    if ((param_1[0x1e] & 0x100000U) != 0) {
      if ((param_1[0x1e] & 0x400000U) == 0) {
        piVar2 = param_1 + 4;
        do {
          ExclusiveAccess(piVar2);
          bVar1 = (bool)hasExclusiveAccess(piVar2);
        } while (!bVar1);
        *piVar2 = 0x10;
      }
      else {
        piVar2 = param_1 + 4;
        do {
          ExclusiveAccess(piVar2);
          bVar1 = (bool)hasExclusiveAccess(piVar2);
        } while (!bVar1);
        *piVar2 = -1;
        iStack_64 = -0x79ffffea;
        if (param_1[0x1f] != 0) {
          iStack_64 = param_1[0x1f];
        }
      }
    }
    if (param_1[0x41] == 1) {
      iStack_64 = 0;
    }
    iVar3 = 2;
    break;
  case 0x10:
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2a = 0;
    uStack_2c = 10;
    uStack_40 = 6;
    uStack_3c = 0x32;
    piVar2 = param_1 + 4;
    (**(code **)(*param_1 + 0xc))(param_1,&uStack_40);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = -1;
    goto LAB_810b047e;
  case -1:
    if ((int)((param_1[0x44] - param_1[0x43]) + ((uint)(param_1[0x44] - param_1[0x43] >> 4) >> 0x1c)
             ) >> 4 != 0) {
      uStack_80 = 0;
      uStack_7c = 0;
      uStack_78 = 0;
      uStack_72 = 0;
      uStack_74 = 10;
      uStack_88 = 6;
      uStack_84 = 0x32;
      (**(code **)(*param_1 + 0xc))(param_1,&uStack_88);
      return;
    }
    if (param_1[0x53] == 0) {
      return;
    }
    func_0x810affa2(param_1);
    return;
  default:
    goto LAB_810b047e;
  }
  if (iStack_64 != 0) {
code_r0x810b0440:
    uStack_6c = 0;
    uStack_68 = 0;
    uStack_60 = 0;
    uStack_5c = 10;
    uStack_5a = 0;
    uStack_70 = 6;
    if (iVar3 == 3) {
      uStack_6c = 0x33;
    }
    else if (iVar3 == 1) {
      uStack_6c = 0x31;
    }
    else if (iVar3 == 2) {
      uStack_6c = 0x32;
    }
    (**(code **)(*param_1 + 0xc))(param_1,&uStack_70);
  }
LAB_810b047e:
  return;
}

