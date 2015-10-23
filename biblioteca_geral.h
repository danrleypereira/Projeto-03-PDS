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
  #include <dirent.h>//está sendo usada;

  // #include <sys/stat.h>
  // #include <sys/types.h>
  #define TEATRO_INFANTIL "Teatro_Infantil/"
  #define CONTEUDO "Conteudo/"
  #define TURISMO_EM_GOIAS "Turismo_em_Goias/"
  #define PONTOS_TURISTICOS_EM_GOIANIA "Pontos_Turisticos_em_Goiania/"

  typedef struct {int dia, mes, ano;} Data;
  typedef struct Teatro_infantil
  {
    char nome[100];
    Data dia_da_atracao;
    char onde[100];
    int horario_de_funcionamento;
    int numero_contato;//numero para mais informações.
    int valor_ingresso;
    char descricao[300];
    /*
    Dentro de status tem que adicionar as seguintes informações;
    Informações gerias sobre a atração;
    Pontos de venda;
    */
  };

  int escolher_crud();
  void adicionar_crud();
  char* crud_para_ler();


  void create_teatro_infantil();
  void create_conteudo();
  void create_turismo_em_goias();
  void create_pontos_turisticos();

  void ler(char* nome_arquivo);
  void atualizar();
  void deletar();

  char* alocar_memoria(const int tamanho);
  void list_files_in_directory();


#endif
