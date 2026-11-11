
void FUN_81080caa(char **param_1,char **param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined *puVar4;
  char *pcVar5;
  
  pcVar2 = *param_1;
  *param_1 = (char *)0x0;
  func_0x81005af0(pcVar2);
  pcVar2 = *param_2;
  param_1[2] = pcVar2;
  if (pcVar2 != (char *)0x0) {
    pcVar3 = (char *)func_0x81005aaa(pcVar2 + 1);
    pcVar5 = *param_1;
    *param_1 = pcVar3;
    func_0x81005af0(pcVar5);
    func_0x8109d75c(*param_1,pcVar2 + 1,param_2[2]);
    pcVar2 = *param_1;
    param_1[1] = pcVar2;
    cVar1 = *pcVar2;
    while (cVar1 != '\0') {
      param_1[1] = pcVar2;
      puVar4 = (undefined *)func_0x81081a68(pcVar2,&UNK_81137434);
      if (puVar4 == (undefined *)0x0) {
        return;
      }
      cVar1 = puVar4[1];
      pcVar2 = puVar4 + 1;
      *puVar4 = 0;
    }
  }
  return;
}

