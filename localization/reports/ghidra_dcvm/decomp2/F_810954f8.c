
uint * FUN_810954f8(undefined4 param_1,uint *param_2)

{
  uint *puVar1;
  
  if (((*param_2 & 0xf) == 4) && ((*param_2 & 0xf0) == 0x20)) {
    puVar1 = (uint *)0x0;
  }
  else {
    puVar1 = (uint *)FUN_8109548c(param_1);
    if ((puVar1 != (uint *)0x0) && ((*puVar1 & 0xf) == 4)) {
      puVar1 = (uint *)FUN_810954f8(param_1,puVar1);
    }
  }
  return puVar1;
}

