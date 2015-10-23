/*
  Especificação das funções de uso geral;
*/

//Retorna o valor correspondente ao CRUD.
int escolher_crud()
{
  int escolha;
  printf("Digite 1 para Teatro Infantil.\n");
  printf("Digite 2 para Conteúdo Infantil.\n");
  printf("Digite 3 para Turismo em Goiás.\n");
  printf("Digite 4 para Pontos Turisticos de Goiania.\n");
  scanf("%d", &escolha);
  return escolha;
}

void adicionar_crud()
{
  int escolha = escolher_crud();
  while(escolha < 1 || escolha > 4)
  {
    printf("Numero não corresponde a nenhum CRUD. Escolha novamente.\n");
    escolha = escolher_crud();
  }

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

//escolhe o DIRETORIO que será lido.
char* crud_para_ler()
{
  int escolha = escolher_crud();
  while(escolha < 1 || escolha > 4)
  {
    printf("Numero não corresponde a nenhum CRUD. Escolha novamente.\n");
    escolha = escolher_crud();
  }
  switch(escolha)
  {
    case 1:
      return TEATRO_INFANTIL;
      break;
    case 2:
      return CONTEUDO;
      break;
    case 3:
      return TURISMO_EM_GOIAS;
      break;
    case 4:
      return PONTOS_TURISTICOS_EM_GOIANIA;
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

void list_files_in_directory()
{
  DIR           *d;
  struct dirent *dir;
  d = opendir("./Teatro_Infantil/");

  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }

    (void) closedir(d);
  }
  else
  {
    perror ("Couldn't open the directory");
    exit(0);
  }
}
