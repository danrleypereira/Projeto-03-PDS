/*
  Biblioteca geral de funções;
*/

// Introduzir todas as informações;
void add_entidade(ENTIDADE *ptr)
{
  //coloca '/0' em todos os indices;
  memset(ptr->Nome, '\0', sizeof(ptr->Nome));
  memset(ptr->Endereco, '\0', sizeof(ptr->Endereco));
  memset(ptr->Status, '\0', sizeof(ptr->Status));

  //Defini Nome, Endereço e Status;
  printf("Introduza o nome: \n"); gets(ptr->Nome);
  printf("Introduza o endereço: \n"); gets(ptr->Endereco);
  printf("Introduza o status contendo as seguintes informações:\n1. Informações gerais sobre a atração;\n2. Pontos de vendas. \n");
  gets(ptr->Status);

  //Defini o dia da atração;
  printf("Introduza o dia da atração: \n"); scanf("%d", &ptr->Dia_da_atracao.Dia);
  printf("Introduza o mes da atração: \n"); scanf("%d", &ptr->Dia_da_atracao.Mes);
  printf("Introduza o ano da atração: \n"); scanf("%d", &ptr->Dia_da_atracao.Ano);

  //Defini o Horario de funcionamento, numero para mais informações e o valor do ingresso;
  printf("Introduza o horário de funcionamento: \n"); scanf("%d", &ptr->Horario_de_funcionamento);
  printf("Introduza o numero para obter mais informações: \n"); scanf("%d", &ptr->Numero_contato);
  printf("Introduza o valor do ingresso: \n"); scanf("%d", &ptr->Valor_ingresso);

}

void mostrar(struct entidade x)
{
  printf("Nome:      %s\n", x.Nome);
  printf("Endereço:  %s\n", x.Endereco);
  printf("Status:    %s\n", x.Status);

  printf("Data:      %d/%d/%d\n", x.Dia_da_atracao.Dia, x.Dia_da_atracao.Mes, x.Dia_da_atracao.Ano);

  printf("Horário de funcionamento:  %d\n", x.Horario_de_funcionamento);
  printf("Numero de contato:         %d\n", x.Numero_contato);
  printf("Valor do ingresso:         R$%d.00\n", x.Valor_ingresso);

}
