
int FUN_8107b3aa(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 *puVar2;
  
  if (param_1[2] == 0) {
    if (((uRam811912a8 & 1) == 0) && (iVar1 = func_0x811183f0(0x811912a8), iVar1 != 0)) {
      puVar2 = (undefined2 *)0x811912b8;
      iVar1 = 8;
      do {
        *puVar2 = 0xffff;
        iVar1 = iVar1 + -1;
        puVar2[1] = 0xffff;
        *(undefined *)(puVar2 + 2) = 0xff;
        *(undefined *)((int)puVar2 + 5) = 0;
        puVar2[3] = 0xffff;
        puVar2[4] = 0xffff;
        *(undefined *)(puVar2 + 5) = 0xff;
        *(undefined *)((int)puVar2 + 0xb) = 0;
        puVar2 = puVar2 + 6;
      } while (iVar1 != 0);
      uRam81191318 = 0;
      uRam811912b0 = 0;
      uRam811912b4 = 0;
      func_0x81118450(0x811912b0,&UNK_8110495d,0x811ae7e8);
      func_0x81118240(0x811912a8);
    }
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,param_2);
    if (iVar1 == 0) {
      iVar1 = -0x7ee6ed50;
    }
  }
  else {
    iVar1 = param_1[2] + 8;
  }
  return iVar1;
}

