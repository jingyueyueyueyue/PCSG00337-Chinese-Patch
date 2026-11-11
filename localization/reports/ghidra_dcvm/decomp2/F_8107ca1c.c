
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8107ca1c(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int **ppiVar3;
  int **ppiVar4;
  
  iVar1 = _UNK_8111a5b0;
  ppiVar3 = (int **)param_1[2];
  *param_1 = &UNK_81145de4;
  ppiVar4 = ppiVar3 + param_1[1];
  for (; ppiVar3 != ppiVar4; ppiVar3 = ppiVar3 + 1) {
    if (*ppiVar3 != (int *)0x0) {
      (**(code **)(**ppiVar3 + 4))();
    }
  }
  *param_1 = &UNK_81145d84;
  if (_UNK_8111a5b0 != iVar1) {
    puVar2 = (undefined4 *)func_0x811185a0(param_1);
    ppiVar3 = (int **)puVar2[2];
    *puVar2 = &UNK_81145de4;
    ppiVar4 = ppiVar3 + puVar2[1];
    for (; ppiVar3 != ppiVar4; ppiVar3 = ppiVar3 + 1) {
      if (*ppiVar3 != (int *)0x0) {
        (**(code **)(**ppiVar3 + 4))();
      }
    }
    *puVar2 = &UNK_81145d84;
    func_0x81005af0(puVar2);
    return;
  }
  return;
}

