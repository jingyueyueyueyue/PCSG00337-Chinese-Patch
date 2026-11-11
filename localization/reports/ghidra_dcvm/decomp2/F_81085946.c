
void FUN_81085946(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  puVar2 = *(undefined4 **)(param_2 + 0x24);
  piVar3 = *(int **)(param_1 + 4);
  iVar1 = (int)((puVar2[2] - puVar2[1]) + ((uint)((int)(puVar2[2] - puVar2[1]) >> 6) >> 0x1a)) >> 6;
  if (iVar1 != 0) {
    func_0x81116a30(*(undefined4 *)(*piVar3 + 4),0);
    func_0x81116b20(*(undefined4 *)(*piVar3 + 4),0,0,*puVar2,iVar1 * 6);
  }
  return;
}

