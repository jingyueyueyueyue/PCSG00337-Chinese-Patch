
undefined4 * FUN_8107e09a(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = *(undefined4 **)(undefined4 *)*param_1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    uVar5 = 1;
    *(undefined4 *)*param_1 = *puVar2;
    iVar1 = param_1[2];
    if (1 < iVar1 + 1U) {
      iVar4 = 4;
      puVar3 = (undefined4 *)*param_1;
      do {
        puVar3 = puVar3 + 1;
        if ((undefined4 *)*puVar3 == puVar2) {
          *(undefined4 *)((int)(undefined4 *)*param_1 + iVar4) = 0;
          iVar1 = param_1[2];
          break;
        }
        uVar5 = uVar5 + 1;
        iVar4 = iVar4 + 4;
      } while (uVar5 < iVar1 + 1U);
    }
    func_0x8108d650(param_1[1],0xff,iVar1 << 2);
    param_1[3] = param_1[3] + -1;
  }
  return puVar2;
}

