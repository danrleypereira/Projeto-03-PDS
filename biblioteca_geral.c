/*
  Especificação das funções de uso geral;
*/
void adicionar_crud()
{
  printf("Digite 1 para Teatro Infantil.\n");
  printf("Digite 2 para Conteúdo Infantil.\n");
  printf("Digite 3 para Turismo em Goiás.\n");
  printf("Digite 4 para Pontos Turisticos de Goiania.\n");

  int escolha;
  do
  {
    scanf("%d",&escolha);
  }while(escolha < 1 || escolha > 4);

  switch(escolha)
  {
    case 1:
      create_teatro_infantil();
      break;
    case 2:
      create_conteudo();
      break;
    case 3:
      create_turismo_em_goias();
      break;
    case 4:
      create_pontos_turisticos();
      break;
  }
}

/*abri ou cria arquivos no diretorio "nome_diretorio" com o nome "nome_diretorio"
e o endereço onde o arquivo será guardado.*/
FILE* abrir_arquivo(char* nome_diretorio, char* nome_arquivo, FILE* fp)
{
  char* string_caminho_arquivo = alocar_memoria(strlen(nome_diretorio)+strlen(nome_arquivo)+1);//string com o caminho para o arquivo.
  strcpy(string_caminho_arquivo, nome_diretorio);//copia o nome do diretorio em p.
  strcat(string_caminho_arquivo, nome_arquivo);//concatena o nome do arquivo no final de p.
  //abri o arquivo (se não existe arquivo com esse nome a função cria o arquivo) para ler e escrever.
  fp = fopen(string_caminho_arquivo, "w+");
  if(fp == NULL)
  {
    perror("Error: ");
    printf("Programa finalizado.");
    exit(0);
  }
  return fp;//retorna o ponteiro para o arquivo;
}

//alocar o memoria com "tamanho".
char* alocar_memoria(const int tamanho)
{
  char* p = (char*) malloc( tamanho * sizeof(char));
  return p;
}
