/*
  Especificação das funções de uso geral;
*/

//Retorna o valor correspondente ao CRUD.
int escolher_crud()
{
  int true_or_false = TRUE;
  while(true_or_false)
  {
    int escolha;
    printf("Digite 1 para Teatro Infantil.\n");
    printf("Digite 2 para Conteúdo Infantil.\n");
    printf("Digite 3 para Turismo em Goiás.\n");
    printf("Digite 4 para Pontos Turisticos de Goiania.\n");
    scanf("%d", &escolha); __fpurge(stdin);
    switch(escolha)
    {
      case 1:
        true_or_false = FALSE;
        return 1;
        break;
      case 2:
        true_or_false = FALSE;
        return 2;
        break;
      case 3:
        true_or_false = FALSE;
        return 3;
        break;
      case 4:
        true_or_false = FALSE;
        return 4;
        break;
      default: true_or_false = TRUE;
    }
  }
}

//escolhe qual diretorio sera usado para salvar os arquivos.
void adicionar_crud()
{
  int escolha = escolher_crud();
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
    default : escolha = TRUE;
  }
}

//escolhe o DIRETORIO que será lido.
char* escolher_crud_para_ler()
{
  int escolha = escolher_crud();
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

//escolhe um arquivo dentro do diretorio passado como argumento.
char *escolher_arquivo_no_diretorio(char *nome_diretorio)
{
  DIR           *d;
  struct dirent *dir;
  char *nomes_arquivos[] = {};
  int i = 0, escolha;

  nome_diretorio = criar_caminho_diretorio(nome_diretorio);
  listar_arquivos_no_diretorio(nome_diretorio);
  if((d = opendir(nome_diretorio)) == NULL)//observe que está variável tem o seguinte formato: "./nome_do_diretorio/".
  {
    perror ("Couldn't open the directory");
    exit(0);
  }
  while ((dir = readdir(d)) != NULL)
  {
    if(!strcmp(dir->d_name, ".") || strcmp(dir->d_name, ".."));
    {
        continue; //próxima interação;
    }
    strcpy(nomes_arquivos[i], dir->d_name);
  }
  (void) closedir(d);

  for(i = 0; i < 5; i++)
  {
    printf("nome do arquivo: %s", nomes_arquivos[i]);
  }

    scanf("%d", &escolha);
    return nomes_arquivos[escolha];
}

/*abri ou cria arquivos no diretorio "nome_diretorio" com o nome "nome_diretorio"
e o endereço onde o arquivo será guardado.*/
FILE* abrir_arquivo(char *nome_diretorio, char *nome_arquivo, FILE *fp)
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

char* criar_caminho_diretorio(char *diretorio)
{
  char* caminho = (char*) calloc( (strlen(diretorio)+3), sizeof(char));
  int tamanho = (strlen(diretorio)+3);
  caminho[0] = '.';
  caminho[1] = '/';
  caminho[2] = '\0';
  strcat(caminho, diretorio);
  return caminho;
}

//Lista todos arquivos do diretorio passado como argumento.
void listar_arquivos_no_diretorio(char* diretorio/*parametro com o nome do diretorio passado como argumento.*/)
{
  DIR           *d;
  struct dirent *dir;
  int i = 0;
  printf("este é o nome do diretorio_função dentro da listar arquivos: %s\n", diretorio);

  if ((d = opendir(diretorio)) == NULL)
  {
    perror("Diretorio não pode ser aberto.");
    exit(0);
  }else
  {
    printf("entrou no else");
    while ((dir = readdir(d)) != NULL)
    {
      if(!strcmp(dir->d_name, ".") || strcmp(dir->d_name, ".."));
      {
          continue; //próxima interação;
      }
      printf("Digite %d para abrir o arquivo de nome: %s%s\n", ++i, diretorio, dir->d_name);
    }

    (void) closedir(d);
  }
}
