/*

Todos os typedef;
Todos os prototipos das funções
Todos os defines

*/
#ifndef __BIBLIOTECA_GERAL_H

  #define __BIBLIOTECA_GERAL_H
  #include <stdio.h>//está sendo usada;
  #include <stdlib.h>//está sendo usada;
  #include <string.h>//está sendo usada;
  // #include <sys/stat.h>
  // #include <sys/types.h>
  #define TEATRO_INFANTIL "Teatro_Infantil/"

  typedef struct {int dia, mes, ano;} Data;
  typedef struct Teatro_infantil
  {
    char nome[100];
    Data dia_da_atracao;
    char onde[100];
    int horario_de_funcionamento;
    int numero_contato;//numero para mais 
    int valor_ingresso;
    char descricao[300];
    /*
    Dentro de status tem que adicionar as seguintes informações;
    Informações gerias sobre a atração;
    Pontos de venda;
    */
  };

  void adicionar_crud();
  void create_teatro_infantil();
  void create_conteudo();
  void create_turismo_em_goias();
  void create_pontos_turisticos();

  void ler();
  void atualizar();
  void deletar();

  char* alocar_memoria(const int tamanho);


#endif
