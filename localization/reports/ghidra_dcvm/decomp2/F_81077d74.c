
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_81077d74(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  
  pcVar1 = _UNK_811459cc;
  *param_1 = &UNK_811459b4;
  param_1[2] = &UNK_81145a04;
  (*pcVar1)(param_1);
  FUN_8108170c(param_1 + 2);
  param_1[1] = 0;
  if (param_1[0x71] != 0) {
    if (param_1 + 0x71 == (undefined4 *)param_1[0x73]) {
      func_0x81101b54();
    }
    else {
      iVar2 = param_1[0x72];
      ((undefined4 *)param_1[0x73])[1] = iVar2;
      *(undefined4 *)(iVar2 + 8) = param_1[0x73];
    }
  }
  param_1[0x71] = 0;
  param_1[0x72] = 0;
  param_1[0x73] = 0;
  param_1[2] = &UNK_8114596c;
  FUN_81081804(param_1 + 2);
  *param_1 = &UNK_81145920;
  return param_1;
}

