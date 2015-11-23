#include "funcoes.h"
#include "funcoes.c"

int main()
{
  system("clear");
    printf("Faculdade UnB Gama.\n");
    printf("Processo de Desenvolvimento de Software.\n");
    printf("Projeto 03.\n");
    printf("Este programa foi feito com a finalidade de criar, visualizar, atualizar e deletar atrações e pontos turísticos de Goiânia e do Goiás, simulando o uso do site www.curtamais.com.br\n");
    int opcao;
    do{
      system("clear");
      do{
        printf("Digite: 1 para Teatro Infantil.\nDigite: 2 para Conteúdo Infantil.\nDigite: 3 para Pontos Turísticos em Goiânia.\nDigite: 4 para Turismo em Goiás.\n");
        printf("Para sair digite 5\n");
        scanf("%d", &opcao); __fpurge(stdin);
      }while(!(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 5));
      switch(opcao)
      {
        case 1:
          teatro();
          break;
        case 2:
          conteudo();
          break;
        case 3:
          pontos();
          break;
        case 4:
          turismo();
          break;
      }
    }while(opcao != 5);
    return 0;
}
