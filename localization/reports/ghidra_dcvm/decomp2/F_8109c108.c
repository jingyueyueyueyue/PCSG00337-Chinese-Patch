
void FUN_8109c108(int *param_1,int *param_2)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  
  if ((param_2[0x1c] != 0) && (uVar1 = param_2[0x1c] - 1, param_2[0x1c] = uVar1, uVar1 < 2)) {
    piVar2 = (int *)0x0;
    if (param_2 != (int *)0x0) {
      piVar2 = param_2 + 1;
    }
    if (*piVar2 == 0) {
      piVar2 = (int *)0x0;
      if (param_2 != (int *)0x0) {
        piVar2 = param_2 + 1;
      }
      *param_1 = piVar2[1];
    }
    else {
      piVar2 = (int *)0x0;
      if (param_2 != (int *)0x0) {
        piVar2 = param_2 + 1;
      }
      piVar3 = (int *)0x0;
      if (param_2 != (int *)0x0) {
        piVar3 = param_2 + 1;
      }
      *(int *)(*piVar3 + 8) = piVar2[1];
    }
    piVar2 = (int *)0x0;
    if (param_2 != (int *)0x0) {
      piVar2 = param_2 + 1;
    }
    if (piVar2[1] == 0) {
      piVar2 = (int *)0x0;
      if (param_2 != (int *)0x0) {
        piVar2 = param_2 + 1;
      }
      param_1[1] = *piVar2;
    }
    else {
      piVar2 = (int *)0x0;
      if (param_2 != (int *)0x0) {
        piVar2 = param_2 + 1;
      }
      piVar3 = (int *)0x0;
      if (param_2 != (int *)0x0) {
        piVar3 = param_2 + 1;
      }
      *(int *)(piVar3[1] + 4) = *piVar2;
    }
    piVar2 = (int *)0x0;
    if (param_2 != (int *)0x0) {
      piVar2 = param_2 + 1;
    }
    piVar2[1] = 0;
    piVar2 = (int *)0x0;
    if (param_2 != (int *)0x0) {
      piVar2 = param_2 + 1;
    }
    *piVar2 = 0;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
  }
  return;
}

