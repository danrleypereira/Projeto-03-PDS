//Especificação das funções de Criar, Ler, Atualizar e Deletar informações.

// Introduzir todas as informações;
void create_teatro_infantil()
{
  struct Teatro_infantil atracao;
  FILE *fp;

  //coloca '/0' em todos os indices;
  memset(atracao.nome, '\0', sizeof(atracao.nome));
  memset(atracao.onde, '\0', sizeof(atracao.onde));
  memset(atracao.descricao, '\0', sizeof(atracao.descricao));

  //Defini Nome, Endereço e Status;
  printf("Introduza o nome: \n"); scanf("%s" ,&atracao.nome); __fpurge(stdin);
  printf("Introduza o endereço: \n"); scanf("%s" ,&atracao.onde); __fpurge(stdin);
  printf("Introduza a descrição contendo as seguintes informações:\n1. Informações gerais sobre a atração;\n2. Pontos de vendas. \n");
  scanf("%s" ,&atracao.descricao); __fpurge(stdin);

  //Defini o dia da atração com dia mês e ano;
  printf("Introduza o dia da atração: \n"); scanf("%d", &atracao.dia_da_atracao.dia);
  printf("Introduza o mes da atração: \n"); scanf("%d", &atracao.dia_da_atracao.mes);
  printf("Introduza o ano da atração: \n"); scanf("%d", &atracao.dia_da_atracao.ano);

  //Defini o Horario de funcionamento, numero para mais informações e o valor do ingresso;
  printf("Introduza o horário de funcionamento: \n"); scanf("%d", &atracao.horario_de_funcionamento);
  printf("Introduza o numero para obter mais informações: \n"); scanf("%d", &atracao.numero_contato);
  printf("Introduza o valor do ingresso: \n"); scanf("%d", &atracao.valor_ingresso);

  fp = abrir_arquivo(TEATRO_INFANTIL, atracao.nome, fp);
  fprintf(fp, "%s %s %d %d %d %d %d %d %s", atracao.nome, atracao.onde, atracao.dia_da_atracao.dia,
    atracao.dia_da_atracao.mes, atracao.dia_da_atracao.ano, atracao.horario_de_funcionamento,
    atracao.numero_contato, atracao.valor_ingresso, atracao.descricao);//Aqui é para usar o fwriter.
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

void ler(char* nome_arquivo, char* nome_diretorio)
{
  char ch;
  FILE* fp;
  char* nome_diretorio = crud_para_ler();

  fp = fopen(nome_arquivo);
  ch = getc(fp);//Ler um caractere.

  while(ch != EOF)
  {
    putchar(ch); // Imprime na tela.
    ch = getc(fp);
  }
}

void atualizar()
{
  //usar o modo "r+" que sobrescreve os dados do arquivo;
}

void deletar()
{

}
