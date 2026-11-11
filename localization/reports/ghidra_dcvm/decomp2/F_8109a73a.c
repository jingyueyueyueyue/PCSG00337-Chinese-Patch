
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8109a73a(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int **ppiVar4;
  int **ppiVar5;
  int **ppiVar6;
  int **ppiVar7;
  bool bVar8;
  
  iVar2 = _UNK_8111a5b0;
  ppiVar5 = (int **)param_1[2];
  *param_1 = &UNK_8114719c;
  ppiVar6 = (int **)*ppiVar5;
  do {
    while( true ) {
      do {
        if (ppiVar6 == ppiVar5) {
          func_0x8110b430(param_1 + 1);
          if (_UNK_8111a5b0 == iVar2) {
            return;
          }
          uVar3 = func_0x811185a0(param_1);
          FUN_8109a73a();
          func_0x81005af0(uVar3);
          return;
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

