
void FUN_8109abb4(int *param_1,undefined4 param_2)

{
  char cVar1;
  int **ppiVar2;
  int **ppiVar3;
  int **ppiVar4;
  int **ppiVar5;
  bool bVar6;
  
  (**(code **)(*param_1 + 8))(param_1);
  ppiVar3 = (int **)param_1[2];
  ppiVar4 = (int **)*ppiVar3;
  do {
    while( true ) {
      do {
        if (ppiVar4 == ppiVar3) {
          return;
        }
        FUN_8109abb4(ppiVar4[3],param_2);
      } while (*(char *)((int)ppiVar4 + 0x11) != '\0');
      ppiVar2 = (int **)ppiVar4[2];
      ppiVar5 = ppiVar4;
      if (*(char *)((int)ppiVar2 + 0x11) != '\0') break;
      cVar1 = *(char *)((int)*ppiVar2 + 0x11);
      ppiVar4 = ppiVar2;
      ppiVar5 = (int **)*ppiVar2;
      while (cVar1 == '\0') {
        cVar1 = *(char *)((int)*ppiVar5 + 0x11);
        ppiVar4 = ppiVar5;
        ppiVar5 = (int **)*ppiVar5;
      }
    }
    do {
      ppiVar4 = (int **)ppiVar5[1];
      if (*(char *)((int)ppiVar4 + 0x11) != '\0') break;
      bVar6 = ppiVar5 == (int **)ppiVar4[2];
      ppiVar5 = ppiVar4;
    } while (bVar6);
  } while( true );
}

