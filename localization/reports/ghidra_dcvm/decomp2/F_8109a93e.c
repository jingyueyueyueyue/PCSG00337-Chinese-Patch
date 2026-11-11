
undefined4 FUN_8109a93e(int param_1,int *param_2)

{
  char cVar1;
  int **ppiVar2;
  int **ppiVar3;
  int **ppiVar4;
  bool bVar5;
  
  ppiVar3 = (int **)**(int ***)(param_1 + 0x18);
  do {
    while( true ) {
      do {
        if (ppiVar3 == *(int ***)(param_1 + 0x18)) {
          return 0;
        }
        if (param_2 == ppiVar3[3]) {
          return 1;
        }
      } while (*(char *)((int)ppiVar3 + 0x11) != '\0');
      ppiVar2 = (int **)ppiVar3[2];
      ppiVar4 = ppiVar3;
      if (*(char *)((int)ppiVar2 + 0x11) != '\0') break;
      cVar1 = *(char *)((int)*ppiVar2 + 0x11);
      ppiVar3 = ppiVar2;
      ppiVar4 = (int **)*ppiVar2;
      while (cVar1 == '\0') {
        cVar1 = *(char *)((int)*ppiVar4 + 0x11);
        ppiVar3 = ppiVar4;
        ppiVar4 = (int **)*ppiVar4;
      }
    }
    do {
      ppiVar3 = (int **)ppiVar4[1];
      if (*(char *)((int)ppiVar3 + 0x11) != '\0') break;
      bVar5 = ppiVar4 == (int **)ppiVar3[2];
      ppiVar4 = ppiVar3;
    } while (bVar5);
  } while( true );
}

