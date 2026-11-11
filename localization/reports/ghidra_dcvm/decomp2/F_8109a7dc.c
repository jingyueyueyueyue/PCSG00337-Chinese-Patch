
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_8109a7dc(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int **ppiVar4;
  int **ppiVar5;
  int **ppiVar6;
  int **ppiVar7;
  bool bVar8;
  undefined8 uVar9;
  
  iVar3 = _UNK_8111a5b0;
  ppiVar5 = (int **)param_1[6];
  *param_1 = &UNK_811471b0;
  ppiVar6 = (int **)*ppiVar5;
  do {
    while( true ) {
      do {
        if (ppiVar6 == ppiVar5) {
          func_0x8110b958(param_1 + 5);
          FUN_8109a73a(param_1);
          if (_UNK_8111a5b0 == iVar3) {
            return param_1;
          }
          uVar9 = func_0x811185a0(param_1);
          puVar2 = (undefined4 *)uVar9;
          FUN_8109a6f2();
          puVar2[4] = (int)((ulonglong)uVar9 >> 0x20);
          *puVar2 = &UNK_811471b0;
          puVar2[6] = 0;
          puVar2[7] = 0;
          iVar3 = func_0x81005a98(0x14);
          if (iVar3 != 0) {
            *(int *)iVar3 = iVar3;
          }
          if (iVar3 != -4) {
            *(int *)(iVar3 + 4) = iVar3;
          }
          if (iVar3 != -8) {
            *(int *)(iVar3 + 8) = iVar3;
          }
          *(undefined *)(iVar3 + 0x11) = 1;
          *(undefined *)(iVar3 + 0x10) = 1;
          puVar2[6] = iVar3;
          return puVar2;
        }
        if (ppiVar6[3] != (int *)0x0) {
          (**(code **)(*ppiVar6[3] + 4))();
        }
      } while (*(char *)((int)ppiVar6 + 0x11) != '\0');
      ppiVar4 = (int **)ppiVar6[2];
      ppiVar7 = ppiVar6;
      if (*(char *)((int)ppiVar4 + 0x11) != '\0') break;
      cVar1 = *(char *)((int)*ppiVar4 + 0x11);
      ppiVar6 = ppiVar4;
      ppiVar7 = (int **)*ppiVar4;
      while (cVar1 == '\0') {
        cVar1 = *(char *)((int)*ppiVar7 + 0x11);
        ppiVar6 = ppiVar7;
        ppiVar7 = (int **)*ppiVar7;
      }
    }
    do {
      ppiVar6 = (int **)ppiVar7[1];
      if (*(char *)((int)ppiVar6 + 0x11) != '\0') break;
      bVar8 = ppiVar7 == (int **)ppiVar6[2];
      ppiVar7 = ppiVar6;
    } while (bVar8);
  } while( true );
}

