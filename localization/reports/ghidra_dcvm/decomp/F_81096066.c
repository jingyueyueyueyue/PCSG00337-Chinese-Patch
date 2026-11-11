
void FUN_81096066(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)func_0x8109ca34(*(undefined4 *)(param_1 + 0x40));
  iVar2 = func_0x8109c2ae(*puVar1,param_2);
  if (iVar2 == 0) {
    *(undefined **)(param_1 + 0x38) = &UNK_81096439;
    *(undefined4 *)(param_1 + 0x34) = 3;
  }
  else {
    iVar3 = FUN_8109b50a(iVar2,&UNK_81138184,3);
    if (iVar3 != -1) {
      FUN_81095cfa(param_1,iVar2,&UNK_81138184,param_3,param_4,0x40000000,param_5);
    }
  }
  return;
}

