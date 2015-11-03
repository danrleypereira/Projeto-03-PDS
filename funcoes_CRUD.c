//Especificação das funções de Criar, Ler, Atualizar e Deletar informações.

// Introduzir todas as informações;
void create_teatro_infantil()
{
  struct Teatro_infantil atracao;
  FILE *fp;

  //coloca o caractere '/0' em todos os indices;
  memset(atracao.nome, '\0', sizeof(atracao.nome));
  memset(atracao.onde, '\0', sizeof(atracao.onde));
  memset(atracao.descricao, '\0', sizeof(atracao.descricao));

  //Defini Nome, Endereço e Status;
  printf("Introduza o nome: \n"); scanf("%100[^\n]", &atracao.nome); __fpurge(stdin);
  printf("Introduza o endereço: \n"); scanf("%100[^\n]", &atracao.onde); __fpurge(stdin);
  printf("Introduza a descrição contendo as seguintes informações:\n1. Informações gerais sobre a atração;\n2. Pontos de vendas. \n");
  scanf("%300[^\n]", &atracao.descricao); __fpurge(stdin);

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

  evento.info_contato.numero_contato = 0;
  evento.preco_ingresso = 0;

  do{
      printf("\nIntroduza um nome para o evento: ");    gets(evento.nome_do_evento);    fflush(stdin);
        if(evento.nome_do_evento[0]=='\0'){
          printf("\nInsira um nome valido!\n");
        }
      }while( evento.nome_do_evento[0] ==  '\0');

  do{
      printf("\nIntroduza o dia de inicio do evento: ");  scanf("%i", &evento.dia_de_inicio_evento.dia);  fflush(stdin);
      printf("\nIntroduza o mes de inicio do evento: ");  scanf("%i", &evento.dia_de_inicio_evento.mes);  fflush(stdin);
      printf("\nIntroduza o ano de inicio do evento: ");  scanf("%i", &evento.dia_de_inicio_evento.ano);  fflush(stdin);
    if(evento.dia_de_inicio_evento.dia == 0 || evento.dia_de_inicio_evento.mes == 0 || evento.dia_de_inicio_evento.ano == 0)
      {
        printf("\nIntroduza novamente a data\n");
      }
  }while(evento.dia_de_inicio_evento.dia == 0 || evento.dia_de_inicio_evento.mes == 0 || evento.dia_de_inicio_evento.ano == 0);

  printf("\nCaso seja um evento de dia unico, digite a mesma data\n");
  do{
      printf("\nIntroduza o dia final do evento: ");  scanf("%i", &evento.dia_fim_evento.dia);    fflush(stdin);
      printf("\nIntroduza o mes final do evento: ");  scanf("%i", &evento.dia_fim_evento.mes);    fflush(stdin);
      printf("\nIntroduza o ano final do evento: ");  scanf("%i", &evento.dia_fim_evento.ano);    fflush(stdin);
      if(evento.dia_fim_evento.dia == 0 || evento.dia_fim_evento.mes == 0 || evento.dia_fim_evento.ano == 0)
      {
        printf("\nIntroduza novamente a data\n");
      }
  }while(evento.dia_fim_evento.dia == 0 || evento.dia_fim_evento.mes == 0 || evento.dia_fim_evento.ano == 0);

  do{
      printf("\nIntroduza o local ou endereco do evento: ");   gets(evento.local_do_evento);  fflush(stdin);
      if(evento.local_do_evento[0] == '\0')   printf("\nInsira um Local ou Endereco valido\n");
    }while(evento.local_do_evento[0] == '\0');

    do{
      printf("\nIntroduza o horario de inicio do evento: ");   scanf("%i %i", &evento.horario_inicial.hora, &evento.horario_inicial.minuto);
      printf("\nIntroduza o horario de termino do evento: ");    scanf("%i %i", &evento.horario_final.hora, &evento.horario_final.minuto);
      fflush(stdin);
    if(evento.horario_inicial.hora == evento.horario_final.hora && evento.horario_inicial.minuto == evento.horario_final.minuto)
      {
        printf("\nInsira horarios diferentes\n");
      }
    }while(evento.horario_inicial.hora == evento.horario_final.hora && evento.horario_inicial.minuto == evento.horario_final.minuto);

    do{
      printf("\nIntroduza o numero e e-mail de contato (e-mail opcional): ");  scanf("%li", &evento.info_contato.numero_contato);    fflush(stdin);
      gets(evento.info_contato.email_contato);    fflush(stdin);
      if(evento.info_contato.numero_contato == 0) {printf("\nIntroduza um numero de contato valido!\n");}
    }while(evento.info_contato.numero_contato == 0);

    printf("\nIntroduza o pre�o do ingresso/entrada (se for entrada franca digite 0): R$");    scanf("%lf",&evento.preco_ingresso);    fflush(stdin);


    printf("\nIntroduza as restricoes do evento, caso exista: ");   gets(evento.restricoes_do_evento);  fflush(stdin);

    do{
      printf("\nIntroduza uma breve descricao do evento(max. 330 caracteres): ");  gets(evento.descricao);    fflush(stdin);
      if(evento.descricao[0] == '\0') {printf("\nIntroduza uma descricao valida!\n");}
    }while(evento.descricao[0] == '\0');

    //gravar em arquivo

    fp= abrir_arquivo(CONTEUDO, evento.nome_do_evento, fp);
    //nome
    fputs(evento.nome_do_evento, fp);
    //info data
    fprintf(fp, " %2d/ %2d/ %2d ", evento.dia_de_inicio_evento.dia, evento.dia_de_inicio_evento.mes, evento.dia_de_inicio_evento.ano);
    fprintf(fp, " %2d/ %2d/ %2d ", evento.dia_fim_evento.dia, evento.dia_fim_evento.mes, evento.dia_fim_evento.ano);
    //info local
    fputs(evento.local_do_evento, fp);
    //info horario]
    fprintf(fp, " %2d:%2d ", evento.horario_inicial.hora, evento.horario_inicial.minuto);
    fprintf(fp, " %2d:%2d ", evento.horario_final.hora, evento.horario_final.minuto);
    //info contato
    fprintf(fp, " %d ", evento.info_contato.numero_contato);
    fputs(evento.info_contato.email_contato, fp);
    //info pre�o
    fprintf(fp, " R$: %.2lf ", evento.preco_ingresso);
    //info restricao e descricao
    fputs(evento.restricoes_do_evento, fp);    fprintf(fp," ");    fputs(evento.descricao, fp);

    fclose(fp);
}

void create_pontos_turisticos()
{
        struct Pontos_turisticos pontoTuristico;
        FILE *fp;

     memset(pontoTuristico.nome, '\0', sizeof(pontoTuristico.nome));
     memset(pontoTuristico.localizacao, '\0', sizeof(pontoTuristico.localizacao));
     memset(pontoTuristico.informacoes, '\0', sizeof(pontoTuristico.informacoes));

    printf("\nIntroduza o nome:");scanf("%20[^\n]", &pontoTuristico.nome); __fpurge(stdin);
    printf("\nIntroduza a localizacao:");scanf("%100[^\n]", &pontoTuristico.localizacao); __fpurge(stdin);
    printf("\nIntroduza o horario de funcionamento:");scanf("%d", &pontoTuristico.horario_de_funcionamento);

    printf("\nIntroduza a area do local:");scanf("%lf", &pontoTuristico.area);
    printf("\nIntroduza o telefone para contato:");scanf("%d", &pontoTuristico.numero_contato);

    printf("\nIntroduza as seguintes informacoes sobre o ponto turistico:\n1. Descricao Geral\n2.Valor da Entrada\n");
    printf("3.Informacoes sobre agendamento de Visita\n4.Telefones para contato\n5.Pontos de referencia\n6.Area do local");
    scanf("%300[^\n]", &pontoTuristico.informacoes); __fpurge(stdin);

     /* A área e o telefone solicitado devem ser incluidos nas informações. Caso necessário, o horário
     de funcionamento também pode ser incluído*/

     fp = abrir_arquivo(PONTOS_TURISTICOS_EM_GOIANIA, pontoTuristico.nome, fp);
     fputs(pontoTuristico.nome, fp);
     fputs(pontoTuristico.localizacao, fp);
     fprintf(fp, "%d %d %d",pontoTuristico.area,pontoTuristico.horario_de_funcionamento,pontoTuristico.numero_contato);
     fputs(pontoTuristico.informacoes, fp);
     fclose(fp);
}

void create_turismo_em_goias()
{

}

void ler(void)
{
  char ch;
  FILE* fp;
  char* nome_diretorio = escolher_crud_para_ler();
  printf("este é o nome do diretorio: %s\n", nome_diretorio);

  char* nome_arquivo = escolher_arquivo_no_diretorio(nome_diretorio);
  printf("este é o nome do arquivo: %s\n", nome_arquivo);


  fp = abrir_arquivo(nome_diretorio, nome_arquivo, fp);

  ch = getc(fp); //Ler um caractere.

  while(ch != EOF)
  {
    putchar(ch); // Imprime na tela.
    ch = getc(fp);
  }
}

void atualizar()
{
  //usar o modo "r+" que sobrescreve os dados do arquivo;
    struct Pontos_turisticos pontoTuristico;
    char nomeDoArquivo[20];

    printf("Introduza o nome do CRUD que deseja atualizar: "); scanf("%s",nomeDoArquivo);

    memset(pontoTuristico.nome, '\0', sizeof(pontoTuristico.nome));
    memset(pontoTuristico.localizacao, '\0', sizeof(pontoTuristico.localizacao));
    memset(pontoTuristico.informacoes, '\0', sizeof(pontoTuristico.informacoes));

    printf("\nIntroduza o novo nome:");scanf("%20[^\n]", &pontoTuristico.nome); __fpurge(stdin);
    printf("\nIntroduza a nova localizacao:");scanf("%100[^\n]", &pontoTuristico.localizacao); __fpurge(stdin);
    printf("\nIntroduza o novo horario de funcionamento:");scanf("%d", &pontoTuristico.horario_de_funcionamento);

    printf("\nIntroduza a nova area do local:");scanf("%lf", &pontoTuristico.area);
    printf("\nIntroduza o novo telefone para contato:");scanf("%d", &pontoTuristico.numero_contato);

    printf("\nIntroduza as seguintes informacoes sobre o ponto turistico:\n1. Noma descricao Geral\n2.Novo valor da Entrada\n");
    printf("3.Novas informacoes sobre agendamento de Visita\n4.Novos telefones para contato\n5.Novos pontos de referencia\n6.Nova area do local");
    scanf("%300[^\n]", &pontoTuristico.informacoes); __fpurge(stdin);

    FILE *fp = fopen(nomeDoArquivo,"+r");
    fputs(pontoTuristico.nome, fp);
    fputs(pontoTuristico.localizacao, fp);
    fprintf(fp, "%d %d %d",pontoTuristico.area,pontoTuristico.horario_de_funcionamento,pontoTuristico.numero_contato);
    fputs(pontoTuristico.informacoes, fp);
    fclose(fp);

}

void deletar()
{
    char nomeDoArquivo[20];

    printf("Insira o nome do CRUD que deseja deletar: "); scanf("%s",nomeDoArquivo);

    remove(nomeDoArquivo);
}
