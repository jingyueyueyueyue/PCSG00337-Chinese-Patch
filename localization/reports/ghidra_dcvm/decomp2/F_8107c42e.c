
void FUN_8107c42e(int param_1)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    uVar1 = 0;
    uVar2 = *(uint *)(param_1 + 0x28);
    if (uVar2 != 0) {
      do {
        puVar3 = (ushort *)(uVar1 * *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18));
        *puVar3 = *puVar3 & 0xff00;
        uVar1 = uVar1 + 1;
      } while (uVar1 < uVar2);
    }
  }
  return;
}

