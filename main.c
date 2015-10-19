#include <stdio.h>//está sendo usada;
// #include <stdlib.h>
#include <string.h>//está sendo usada;
#include "biblioteca_geral.c"

typedef struct {int Dia, Mes, Ano;} DATA;
typedef struct entidade
{
  char Nome[100];
  DATA Dia_da_atracao;//dia que aconterá a atração;
  char Endereco[100];
  int Horario_de_funcionamento;
  int Numero_contato;
  int Valor_ingresso;
  char Status[300];
  /*
  Dentro de status tem que adicionar as seguintes informações;
  Informações gerias sobre a atração;
  Pontos de venda;
  */
} ENTIDADE;

int main()
{
  struct entidade p;
  add_entidade(&p);
  mostrar(p);

  return 0;
}
