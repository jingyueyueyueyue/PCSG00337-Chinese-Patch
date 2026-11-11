
/* WARNING: Switch with 1 destination removed at 0x810968dc : 7 cases all go to same destination */

void FUN_81096888(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = (uVar1 << 0x18) >> 0x1c;
  if (uVar2 != 6) {
    if (uVar2 == 2) {
      switch(uVar1 & 0xf) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      }
    }
    else if (uVar2 == 1) {
      func_0x81096886();
    }
    else if (uVar2 == 0) {
      switch(uVar1 & 0xf) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      }
    }
  }
  return;
}

