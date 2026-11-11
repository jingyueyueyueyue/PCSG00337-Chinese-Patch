
void FUN_81064ae4(undefined4 param_1,uint param_2)

{
  if (param_2 < 10) {
    switch(param_2) {
    case 1:
      FUN_81064d60();
      break;
    case 2:
      FUN_81064e74();
      break;
    case 3:
      FUN_81064f88();
      break;
    case 4:
      FUN_8106509c();
      break;
    case 5:
      FUN_810651b0();
      break;
    case 6:
      FUN_810652c4();
      break;
    case 7:
      FUN_810653d8();
      break;
    case 8:
      FUN_810654ec();
      break;
    case 9:
      FUN_81065600();
      break;
    default:
      goto LAB_81064b06;
    }
  }
  else {
    if (param_2 == 99) {
      FUN_81065780();
      return;
    }
LAB_81064b06:
    FUN_81064c4c();
  }
  return;
}

