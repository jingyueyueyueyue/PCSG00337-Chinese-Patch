
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106932e(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint in_fpscr;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined auStack_c0 [4];
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_3c;
  int iStack_38;
  int iStack_34;
  
  iStack_34 = _UNK_8111a5b0;
  iVar6 = *(int *)(param_1 + 4);
  if (iVar6 == 0) {
    iVar6 = 1;
  }
  fVar8 = (float)VectorUnsignedToFloat(*(undefined4 *)(param_1 + 8),(byte)(in_fpscr >> 0x15) & 3);
  fVar9 = (float)VectorUnsignedToFloat(iVar6,(byte)(in_fpscr >> 0x15) & 3);
  fVar10 = (float)VectorUnsignedToFloat
                            (*(undefined4 *)(param_1 + 0x14),(byte)(in_fpscr >> 0x15) & 3);
  uVar1 = func_0x81082928(param_2);
  func_0x8108631c(auStack_c0);
  func_0x81076840(auStack_c0);
  puVar2 = (undefined4 *)func_0x81005a98(0x14);
  uVar5 = uRam811910fc;
  puVar7 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    func_0x810862ce(puVar2);
    puVar2[4] = uVar5;
    *puVar2 = &UNK_81144b40;
    puVar7 = puVar2;
  }
  piVar3 = *(int **)(iStack_38 + 0x30);
  *(undefined4 **)(iStack_38 + 0x30) = puVar7;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))();
  }
  puVar7[1] = (fVar8 / fVar9) * 2.0 + -1.0;
  puVar7[2] = 128.0 / fVar10;
  piVar3 = **(int ***)(param_1 + 0x10);
  puVar7[3] = piVar3[6] * piVar3[1] + *piVar3;
  FUN_81064908(param_1,param_2);
  func_0x8103d96e(*param_3,param_2,param_3,0,0xffffffff);
  iVar6 = func_0x81087722(param_5);
  iVar4 = func_0x81087736(param_5);
  if ((iStack_54 != iVar6) || (iStack_50 != iVar4)) {
    uStack_3c = uStack_3c | 0x80000000;
  }
  iStack_54 = iVar6;
  iStack_50 = iVar4;
  uVar5 = func_0x81087722(param_5);
  uStack_58 = func_0x81087736(param_5);
  uStack_5c = uVar5;
  func_0x81075bca(uVar1,param_5);
  uStack_bc = 0x3f800000;
  uStack_b8 = 0x3f800000;
  uStack_b4 = 0x3f800000;
  uStack_b0 = 0x3f800000;
  uStack_3c = uStack_3c & 0xdfffffff | 0x40000002;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  func_0x810868f4(auStack_c0,uVar1);
  func_0x81075bca(uVar1,0);
  func_0x810863d0(auStack_c0);
  if (_UNK_8111a5b0 == iStack_34) {
    return;
  }
  func_0x811185a0();
  uRam811910f8 = 0x80000001;
  uRam811910d0 = 0x80000001;
  uRam811910d4 = 0x80000002;
  uRam811910d8 = 0x80000003;
  uRam811910dc = 0x80000003;
  uRam811910e0 = 0x80000005;
  uRam811910e4 = 0x80000006;
  uRam811910e8 = 0x80000007;
  uRam811910ec = 0x80000008;
  uRam811910f0 = 0x80000009;
  uRam811910f4 = 0x8000000a;
  func_0x811184e0(0x811910cc);
  func_0x81118450(0x811910cc,&UNK_811184f0,0x811ae7e8);
  func_0x81118500(0x811910cd);
  func_0x81118450(0x811910cd,&UNK_811184d0,0x811ae7e8);
  return;
}

