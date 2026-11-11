
int * FUN_8109ceba(int **param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = func_0x81005a98(100);
  if ((iVar1 != 0) && (piVar2 = (int *)FUN_81094940(), piVar2 != (int *)0x0)) {
    piVar2[0x10] = (int)param_1;
    iVar1 = FUN_81095624(piVar2,param_2);
    if (iVar1 == 0) {
      FUN_81094e48(piVar2);
      func_0x81005af0();
    }
    else {
      iVar1 = func_0x8109ce5a(param_1);
      piVar2[2] = iVar1;
      if (iVar1 != 0) {
        FUN_810949fe(piVar2,0);
        piVar3 = param_1[1];
        if (piVar3 == (int *)0x0) {
          *piVar2 = 0;
          piVar2[1] = 0;
          *param_1 = piVar2;
        }
        else {
          *piVar2 = (int)piVar3;
          piVar2[1] = 0;
          piVar3[1] = (int)piVar2;
        }
        param_1[1] = piVar2;
        return piVar2;
      }
      FUN_81094e48(piVar2);
      func_0x81005af0();
    }
  }
  return (int *)0x0;
}

