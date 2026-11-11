
undefined4 FUN_8109aaf0(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int **ppiVar3;
  int **ppiVar4;
  int **ppiVar5;
  int **ppiVar6;
  bool bVar7;
  
  ppiVar4 = *(int ***)(param_1 + 8);
  ppiVar5 = (int **)*ppiVar4;
  do {
    while( true ) {
      do {
        if (ppiVar5 == ppiVar4) {
          return 1;
        }
        iVar2 = (**(code **)(*ppiVar5[3] + 0xc))(ppiVar5[3],param_2);
        if (iVar2 == 0) {
          return 0;
        }
      } while (*(char *)((int)ppiVar5 + 0x11) != '\0');
      ppiVar3 = (int **)ppiVar5[2];
      ppiVar6 = ppiVar5;
      if (*(char *)((int)ppiVar3 + 0x11) != '\0') break;
      cVar1 = *(char *)((int)*ppiVar3 + 0x11);
      ppiVar5 = ppiVar3;
      ppiVar6 = (int **)*ppiVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)((int)*ppiVar6 + 0x11);
        ppiVar5 = ppiVar6;
        ppiVar6 = (int **)*ppiVar6;
      }
    }
    do {
      ppiVar5 = (int **)ppiVar6[1];
      if (*(char *)((int)ppiVar5 + 0x11) != '\0') break;
      bVar7 = ppiVar6 == (int **)ppiVar5[2];
      ppiVar6 = ppiVar5;
    } while (bVar7);
  } while( true );
}

