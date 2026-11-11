
void FUN_8106ab08(int *param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = (**(code **)(*param_1 + 0x8c))(param_1,param_2);
  if (iVar2 != 0) {
    (**(code **)(*param_1 + 0x50))(param_1,param_2);
    piVar3 = (int *)param_1[0x14];
    piVar1 = piVar3;
    if (param_2 == '\0') {
      while (piVar3 != (int *)0x0) {
        if (((int)*(char *)((int)piVar3 + 0x42) & 1U) == 0) {
          *(byte *)(piVar3 + 0x11) =
               *(byte *)(piVar3 + 0x11) & 0xdf |
               (byte)(((uint)(int)*(char *)((int)piVar3 + 0x42) >> 1 & 1) << 5);
          (**(code **)(*piVar1 + 0x14))(piVar1,0);
          piVar3 = piVar1;
        }
        if (piVar3 != (int *)0x0) {
          piVar3 = (int *)piVar3[2];
          piVar1 = piVar3;
        }
      }
      piVar3 = (int *)param_1[0x12];
      piVar1 = piVar3;
      while (piVar3 != (int *)0x0) {
        if (((int)*(char *)((int)piVar3 + 0x42) & 1U) == 0) {
          *(byte *)(piVar3 + 0x11) =
               *(byte *)(piVar3 + 0x11) & 0xdf |
               (byte)(((uint)(int)*(char *)((int)piVar3 + 0x42) >> 1 & 1) << 5);
          (**(code **)(*piVar1 + 0x14))(piVar1,0);
          piVar3 = piVar1;
        }
        if (piVar3 != (int *)0x0) {
          piVar3 = (int *)piVar3[2];
          piVar1 = piVar3;
        }
      }
    }
    else {
      while (piVar3 != (int *)0x0) {
        if ((*(byte *)((int)piVar3 + 0x42) & 1) == 0) {
          (**(code **)(*piVar3 + 0x14))(piVar3,(*(byte *)(piVar3 + 0x11) & 0x20) != 0);
          piVar3 = piVar1;
        }
        if (piVar3 != (int *)0x0) {
          piVar3 = (int *)piVar3[2];
          piVar1 = piVar3;
        }
      }
      for (piVar3 = (int *)param_1[0x12]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
        if ((*(byte *)((int)piVar3 + 0x42) & 1) == 0) {
          (**(code **)(*piVar3 + 0x14))(piVar3,(*(byte *)(piVar3 + 0x11) & 0x20) != 0);
        }
        if (piVar3 == (int *)0x0) {
          return;
        }
      }
    }
  }
  return;
}

