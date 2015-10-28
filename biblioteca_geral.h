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
    Informações gerais sobre a atração;
    Pontos de venda;
    */
  };

    typedef struct HORARIO{
        int hora;
        int minuto;
    };

    typedef struct CONTATO{
        int numero_contato;
        char email_contato[50];
    };

  typedef struct CONTEUDO //andre e matheus
  {
      char nome_do_evento[70];  //
      Data dia_de_inicio_evento;
      Data dia_fim_evento;
      char local_do_evento[50];
      HORARIO horario_inicial;
      HORARIO horario_final;
      CONTATO info_contato;  //DDDe e-mail tbm?
      double preco_ingresso;    // assim vao ser aceitos valores como R$1.90 ou R$999.99
      char restricoes_do_evento[100];   // EX: Altura máxima permitida, etc.
      char descricao[335];  //informações adicionais, local de compra de ingresso, etc.
  };


  typedef struct Pontos_turisticos
  {
    char nome[100];
    char localizacao[100];
    int horario_de_funcionamento;// o horário deve ser dado em 0-23 horas
    int numero_contato;.
    double area;// a área será dada em metros quadrados. Será aceito o valor numérico de até 240.000
    char informacoes[300];/*descrição geral do ponto turístico, preço, informações sobre agendamento de visita,
    telefones para contato,pontos de referencia e a área do local.*/

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
