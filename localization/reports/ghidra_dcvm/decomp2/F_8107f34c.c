
void FUN_8107f34c(int *param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  *(undefined *)((int)param_1 + 0x25) = 1;
  if (param_1[7] != 0) {
    func_0x8107f1fe(param_1,0);
    while( true ) {
      piVar2 = (int *)param_1[3];
      (**(code **)(*piVar2 + 8))(piVar2);
      (**(code **)(*param_1 + 8))(param_1,10);
      (**(code **)(*piVar2 + 0xc))(piVar2);
      piVar2 = (int *)param_1[3];
      (**(code **)(*piVar2 + 8))(piVar2);
      uVar3 = 0;
      if (param_1[8] == 0) break;
      piVar1 = (int *)param_1[7];
      while (*piVar1 == 0) {
        uVar3 = uVar3 + 1;
        piVar1 = piVar1 + 9;
        if ((uint)param_1[8] <= uVar3) goto LAB_8107f3b2;
      }
      (**(code **)(*piVar2 + 0xc))(piVar2);
      FUN_8108cfd4(10);
    }
LAB_8107f3b2:
    (**(code **)(*piVar2 + 0xc))(piVar2);
  }
  return;
}

