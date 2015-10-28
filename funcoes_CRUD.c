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
  printf("Introduza o nome: \n"); gets(atracao.nome); __fpurge(stdin);
  printf("Introduza o endereço: \n"); gets(atracao.onde); __fpurge(stdin);
  printf("Introduza a descrição contendo as seguintes informações:\n1. Informações gerais sobre a atração;\n2. Pontos de vendas. \n");
  gets(atracao.descricao); __fpurge(stdin);

  //Defini o dia da atração com dia mês e ano;
  printf("Introduza o dia da atração: \n"); scanf("%d", &atracao.dia_da_atracao.dia);
  printf("Introduza o mes da atração: \n"); scanf("%d", &atracao.dia_da_atracao.mes);
  printf("Introduza o ano da atração: \n"); scanf("%d", &atracao.dia_da_atracao.ano);

  //Defini o Horario de funcionamento, numero para mais informações e o valor do ingresso;
  printf("Introduza o horário de funcionamento: \n"); scanf("%d", &atracao.horario_de_funcionamento);
  printf("Introduza o numero para obter mais informações: \n"); scanf("%d", &atracao.numero_contato);
  printf("Introduza o valor do ingresso: \n"); scanf("%d", &atracao.valor_ingresso);

  fp = abrir_arquivo(TEATRO_INFANTIL, atracao.nome, fp);
  fputs(atracao.nome, fp);
  fputs(atracao.onde, fp);
  fprintf(fp, "%d %d %d %d %d %d",atracao.dia_da_atracao.dia,
    atracao.dia_da_atracao.mes, atracao.dia_da_atracao.ano, atracao.horario_de_funcionamento,
    atracao.numero_contato, atracao.valor_ingresso);//Aqui é para usar o fwriter.
  fputs(atracao.descricao, fp);
  fclose(fp);
}

void create_conteudo()
{
    struct Conteudo evento;
    FILE *fp;

    printf("\nIntroduza um nome: ");    gets(evento.nome_do_evento);

    printf("\nIntroduza o dia de inicio do evento: ");  scanf("%i", &evento.dia_de_inicio_evento.dia);
    printf("\nIntroduza o mes de inicio do evento: ");  scanf("%i", &evento.dia_de_inicio_evento.mes);
    printf("\nIntroduza o ano de inicio do evento: ");  scanf("%i", &evento.dia_de_inicio_evento.ano);

    printf("\nCaso seja um evento de dia unico, digite a mesma data\n");
    printf("\nIntroduza o dia final do evento: ");  scanf("%i", &evento.dia_fim_evento.dia);
    printf("\nIntroduza o mes final do evento: ");  scanf("%i", &evento.dia_fim_evento.mes);
    printf("\nIntroduza o ano final do evento: ");  scanf("%i", &evento.dia_fim_evento.ano);

    printf("\nIntroduza o local ou endereço do evento: ");   gets(evento.local_do_evento);

    printf("\nIntroduza o horario de inicio do evento: ");   scanf("%i %i", &evento.horario_inicial.hora, &evento.horario_inicial.minuto);
    printf("\nIntroduza o horario de termino do evento: ");    scanf("%i %i", &evento.horario_final.hora, &evento.horario_final.minuto);

    printf("\nIntroduza o numero e e-mail de contato: ");  scanf("%i", &evento.info_contato.numero_contato);
        gets(evento.info_contato.email_contato);

    printf("\nIntroduza o preço do ingresso/entrada: ");    scanf("%lf",&evento.preco_ingresso);

    printf("\nIntroduza as restricoes do evento, caso exista: ");   gets(evento.restricoes_do_evento);

    printf("\nIntroduza uma breve descricao do evento(max. 330 caracteres): ");  gets(evento.descricao);

    //gravar em arquivo

     fp= abrir_arquivo(CONTEUDO, evento.nome_do_evento, fp);
     //nome
     fputs(evento.nome_do_evento, fp);
     //info data
     fprintf(fp, "%d %d %d", evento.dia_de_inicio_evento.dia, evento.dia_de_inicio_evento.mes, evento.dia_de_inicio_evento.ano);
     fprintf(fp, "%d %d %d", evento.dia_fim_evento.dia, evento.dia_fim_evento.mes, evento.dia_fim_evento.ano);
     //info local
     fputs(evento.local_do_evento, fp);
     //info horario
     fprintf(fp, "%d %d", evento.horario_inicial.hora, evento.horario_inicial.minuto);
     fprintf(fp, "%d %d", evento.horario_final.hora, evento.horario_final.minuto);
     //info contato
     fprintf(fp, "%d", evento.info_contato.numero_contato);
     fputs(evento.info_contato.email_contato, fp);
     //info preço
     fprintf(fp, "%.2lf", evento.preco_ingresso);
     //info restricao e descricao
     fputs(evento.restricoes_do_evento, fp);    fputs(evento.descricao, fp);
     fclose(fp);
}

void create_pontos_turisticos()
{
    struct Pontos_turisticos pontoTuristico;
    FILE *fp;

    printf("\nIntroduza o nome:");gets(pontoTuristico.nome);__fpurge(stdin);
    printf("\nIntroduza a localizacao:");gets(pontoTuristico.localizacao);
    printf("\nIntroduza o horario de funcionamento:");

    printf("\nIntroduza a area do local:");scanf("%lf", &pontoTuristico.area);
    printf("\nIntroduza o telefone para contato:");scanf("%d", &pontoTuristico.numero_contato);

    printf("\nIntroduza as seguintes informacoes sobre o ponto turistico:\n1. Descricao Geral\n2.Valor da Entrada\n");
    printf("3.Informacoes sobre agendamento de Visita\n4.Telefones para contato\n5.Pontos de referencia\n6.Área do local");
     /* A área e o telefone solicitado devem ser incluidos nas informações. Caso necessário, o horário
     de funcionamento também pode ser incluído/*

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
