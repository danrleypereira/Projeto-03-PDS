/*

Nome do programa
Objetivo do programa
Nome do programador
Data de criação

*/


#include "biblioteca_geral.h"
#include "biblioteca_geral.c"
#include "funcoes_CRUD.c"

int main()
{
  int escolha;

  printf("Digite 1: Adicionar um CRUD.");
  printf("Digite 2: Acessar um CRUD.");
  scanf("%d", &escolha);

  switch (escolha) {
    case 1:
      adicionar_crud(escolher_crud());
      break;
    case 2:
      ler(escolher_crud())
      break;
  }

  return 0;
}
