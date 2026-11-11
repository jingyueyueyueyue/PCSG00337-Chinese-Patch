
void FUN_8109b4c8(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 != 0) {
    uVar2 = *(uint *)(param_1 + 0x2c);
    uVar3 = 0;
    if (uVar2 != 0) {
      do {
        if ((*(byte *)(iVar1 + 4) != 0) && (*(byte *)(iVar1 + 4) < 3)) {
          *(char *)(iVar1 + 0xb) = (char)*(undefined4 *)(param_1 + 0x74);
        }
        uVar3 = uVar3 + 1;
        iVar1 = iVar1 + 0xc;
      } while (uVar3 < uVar2);
    }
  }
  return;
}

