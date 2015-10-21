#include <stdio.h>//está sendo usada;
#include <stdlib.h>//está sendo usada;
#include <string.h>//está sendo usada;
#include "biblioteca_geral.c"

int main()
{
  int escolha;

  printf("Digite 1: Adicionar um CRUD."); scanf("%d", &escolha);
  if(escolha == 1)
  {
    adicionar_crud();
  }

  // mostrar(p);




  return 0;
}
