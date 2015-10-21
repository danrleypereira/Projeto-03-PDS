/*
  Biblioteca geral de funções;
*/

typedef struct {int Dia, Mes, Ano;} DATA;
typedef struct teatro_infantil
{
  char Nome[100];
  DATA Dia_da_atracao;//dia que aconterá a atração;
  char Onde[100];
  int Horario_de_funcionamento;
  int Numero_contato;
  int Valor_ingresso;
  char Descricao[300];
  /*
  Dentro de status tem que adicionar as seguintes informações;
  Informações gerias sobre a atração;
  Pontos de venda;
  */
};

void adicionar_crud()
{
  printf("Digite 1 para Teatro Infantil.\n");
  printf("Digite 2 para Conteúdo Infantil.\n");
  printf("Digite 3 para Turismo em Goiás.\n");
  printf("Digite 4 para Pontos Turisticos de Goiania.\n");

  int escolha;
  while(escolha<1 || escolha > 4)
  {
    scanf("%d",&escolha);
  }
  if(escolha == 1)
  {
    create_teatro_infantil();
  }else if(escolha == 2)
  {
    create_conteudo();
  }else if(escolha == 3)
  {
    create_turismo_em_goias();
  }else if(escolha == 4)
  {
    create_pontos_turisticos();
  }

}


// Introduzir todas as informações;
void create_teatro_infantil()
{
  struct teatro_infantil atracao;
  FILE *fp;
  char diretorio[16] = {"Teatro_Infantil/"};

  //coloca '/0' em todos os indices;
  memset(atracao.Nome, '\0', sizeof(atracao.Nome));
  memset(atracao.Onde, '\0', sizeof(atracao.Onde));
  memset(atracao.Descricao, '\0', sizeof(atracao.Descricao));

  //Defini Nome, Endereço e Status;
  printf("Introduza o nome: \n"); scanf("%s" ,&atracao.Nome);
  printf("Introduza o endereço: \n"); scanf("%s" ,&atracao.Onde); __fpurge(stdin);
  printf("Introduza a descrição contendo as seguintes informações:\n1. Informações gerais sobre a atração;\n2. Pontos de vendas. \n");
  scanf("%s" ,&atracao.Descricao);

  //Defini o dia da atração;
  printf("Introduza o dia da atração: \n"); scanf("%d", &atracao.Dia_da_atracao.Dia);
  printf("Introduza o mes da atração: \n"); scanf("%d", &atracao.Dia_da_atracao.Mes);
  printf("Introduza o ano da atração: \n"); scanf("%d", &atracao.Dia_da_atracao.Ano);

  //Defini o Horario de funcionamento, numero para mais informações e o valor do ingresso;
  printf("Introduza o horário de funcionamento: \n"); scanf("%d", &atracao.Horario_de_funcionamento);
  printf("Introduza o numero para obter mais informações: \n"); scanf("%d", &atracao.Numero_contato);
  printf("Introduza o valor do ingresso: \n"); scanf("%d", &atracao.Valor_ingresso);

  strcpy(diretorio, atracao.Nome);
  fp = fopen(diretorio, "w+");
  fprintf(fp, "%s %s %d %d %d %d %d %d %s", atracao.Nome, atracao.Onde, atracao.Dia_da_atracao.Dia, atracao.Dia_da_atracao.Mes, atracao.Dia_da_atracao.Ano, atracao.Horario_de_funcionamento, atracao.Numero_contato, atracao.Valor_ingresso, atracao.Descricao);
  fclose(fp);
}

void create_conteudo()
{

}

void create_pontos_turisticos()
{

}

void create_turismo_em_goias()
{

}

void mostrar()
{
  /*
  printf("Nome:      %s\n", x.Nome);
  printf("Endereço:  %s\n", x.Endereco);
  printf("Status:    %s\n", x.Descricao);

  printf("Data:      %d/%d/%d\n", x.Dia_da_atracao.Dia, x.Dia_da_atracao.Mes, x.Dia_da_atracao.Ano);

  printf("Horário de funcionamento:  %d\n", x.Horario_de_funcionamento);
  printf("Numero de contato:         %d\n", x.Numero_contato);
  printf("Valor do ingresso:         R$%d.00\n", x.Valor_ingresso);
*/
}

void atualizar()
{

}

void deletar()
{

}
