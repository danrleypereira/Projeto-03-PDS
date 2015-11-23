void adicionarCrudTeatro(char* nome_atracao, char* local, char* num_contato, char* mais_info, char* preco_ingresso)
{
  system("clear");
    char nome_arquivo[] = nome_arquivo_teatro;
    //Alocar espaço
    tipo_Teatro* crud_teatro = (tipo_Teatro*)malloc(sizeof(tipo_Teatro));
    //Copiar informacoes
    strcpy(crud_teatro->nome, nome_atracao);
    strcpy(crud_teatro->local, local);
    strcpy(crud_teatro->mais_info, mais_info);
    strcpy(crud_teatro->numero_contato, num_contato);
    strcpy(crud_teatro->ingresso, preco_ingresso);

    FILE* fp = fopen(nome_arquivo,"ab+");
    if(fp == NULL)
    {
      printf("\nNão foi possível cadastrar atração.\n");
      exit(0);
    }
    fwrite(crud_teatro, sizeof(tipo_Teatro), 1, fp);
    fclose(fp);
    printf("Atração cadastrada !\n\n");
    printf("Digite qualquer tecla para continuar...\n"); __fpurge(stdin);
    getchar();
    system("clear");
}

void lerInfoCrudTeatro()
{
  system("clear");
    char nome_atracao[100], local[100], mais_info[500], num_contato[50], preco_ingresso[4];/*numero para mais informações.*/
    int nomeEmBranco, localEmBranco, mais_infoEmBranco, contato_invalido, ingresso_invalido;
    //Introduzir nome do arquivo valido
    do{
        nomeEmBranco = 0;
        printf("Introduza o nome: \n"); scanf("%[^\n]s", nome_atracao);  __fpurge(stdin);
        if(stringEmBranco(nome_atracao))
        {
          system("clear");
            nomeEmBranco = 1;
            printf("Campo em Branco !!!\n Por favor digite novamente\n");
        }
    }while(nomeEmBranco);
    //Introduzir endereço(local) valido
    system("clear");
    do{
        localEmBranco = 0;
        printf("Introduza o endereço: \n"); scanf("%[^\n]s", local);  __fpurge(stdin);
        if(stringEmBranco(local))
        {
          system("clear");
            localEmBranco = 1;
            printf("Campo em Branco !!!\n Por favor digite novamente\n");
        }
      }while(localEmBranco);
    //Introduzir mais informações validas
    system("clear");
    do{
        mais_infoEmBranco = 0;
        printf("Introduza a descrição da atração contendo as seguintes informações:\n1. Informações gerais sobre as atrações;\n2. Distancia;\n3.Como chegar;\n4.Acessos;\n5.O que fazer;\n");  scanf("%[^\n]s", mais_info);   __fpurge(stdin);
        if(stringEmBranco(mais_info))
        {
          system("clear");
            mais_infoEmBranco = 1;
            printf("Campo em Branco !!!\n Por favor digite novamente\n");
        }
      }while(mais_infoEmBranco);
    //Introduzir numero para contato valido
    system("clear");
    do{
        contato_invalido = 0;
        printf("Introduza o numero para obter mais informações: \n"); scanf("%[^\n]s", num_contato);  __fpurge(stdin);
        if(numeroInvalido(num_contato))
        {
          system("clear");
            contato_invalido = 1;
            printf("Numero Invalido !!!\n Por favor digite novamente\n");
        }
    }while(contato_invalido);
    //Introduzir preço para ingresso valido
    system("clear");
    do{
        ingresso_invalido = 0;
        printf("Introduza o preço do ingresso: \n"); scanf("%[^\n]s", preco_ingresso);  __fpurge(stdin);
        if(numeroInvalido(preco_ingresso))
        {
          system("clear");
            contato_invalido = 1;
            printf("Preço Invalido !!!\n Por favor digite novamente\n");
        }
    }while(contato_invalido);

    adicionarCrudTeatro(nome_atracao, local, num_contato, mais_info, preco_ingresso);
}

void atualizarCrudTeatro()
{
  system("clear");
    int n, contador = 0;
    int nomeEmBranco, localEmBranco, mais_infoEmBranco, contato_invalido, ingresso_invalido;
    int opcao;
    char nome_crud[100];
    printf("Digite o nome da atração que deseja atualizar:\n");
    scanf("%[^\n]s", nome_crud); __fpurge(stdin);
    tipo_Teatro* crud = (tipo_Teatro*)malloc(sizeof(tipo_Teatro)*50);
    FILE* fp = fopen(nome_arquivo_teatro, "rb");
    if (!fp){
        printf("Não é possível acessar!!\n");
        return;
    }
    n = fread(crud, sizeof(tipo_Teatro), 50, fp);
    fclose(fp);
   while(contador < n)
   {
       if (strcmp(crud[contador].nome, nome_crud) == 0)
       {
           printf("\n");
           printf("Nome da atracao -----> %s\n", crud->nome);
           printf("Local da atracao ----> %s\n", crud->local);
           printf("Numero para contato -> %s\n", crud->numero_contato);
           printf("Mais informações ----> %s\n", crud->mais_info);
           printf("Preço do Ingresso ---> %s\n", crud->ingresso);
           printf("\n\n\n");
           break;
       }
       contador++;
   }
   printf("Digite qualquer tecla para continuar...\n"); __fpurge(stdin);
   getchar();
   system("clear");

   do{
        system("clear");
        printf("O que deseja alterar:\nDigite 1 para alterar o nome da atração\nDigite 2 para alterar local da atração\n");
        printf("Digite 3 para alterar número para contato\nDigite 4 para alterar mais informações\nDigite 5 para alterar o preço do ingresso.\nDigite 6 para voltar ao menu inicial\n");
        scanf("%d", &opcao); __fpurge(stdin);
        switch(opcao)
        {
            system("clear");
            case 1:
                system("clear");
                __fpurge(stdin);
                do{
                    nomeEmBranco = 0;
                    printf("Digite o novo nome da atração:\n");
                    scanf("%[^\n]s", crud[contador].nome); __fpurge(stdin);
                    if(stringEmBranco(crud[contador].nome))
                        {
                            system("clear");
                            nomeEmBranco = 1;
                            printf("Campo em Branco !!!\nPor favor digite novamente:\n\n\n");
                        }
                }while(nomeEmBranco);
                break;
            system("clear");
            case 2:
                system("clear");
                __fpurge(stdin);
                do{
                    localEmBranco = 0;
                    printf("Digite o novo local da atração:\n");
                    scanf("%[^\n]s", crud[contador].local); __fpurge(stdin);
                    if(stringEmBranco(crud[contador].local))
                        {
                            system("clear");
                            localEmBranco = 1;
                            printf("Campo em Branco !!!\nPor favor digite novamente:\n\n\n");
                        }
                }while(localEmBranco);
                break;
                system("clear");
            case 3:
                system("clear");
                __fpurge(stdin);
                do{
                    contato_invalido = 0;
                    printf("Digite o novo numero para contato:\n");
                    scanf("%[^\n]s", crud[contador].numero_contato); __fpurge(stdin);
                    if(numeroInvalido(crud[contador].numero_contato))
                        {
                            system("clear");
                            contato_invalido = 1;
                            printf("Numero Invalido !!!\nPor favor digite novamente:\n\n\n");
                        }
                }while(contato_invalido);
                break;
                system("clear");
            case 4:
                system("clear");
                __fpurge(stdin);
                do{
                    mais_infoEmBranco = 0;
                    printf("Digite as novas informações:\n");
                    scanf("%[^\n]s", crud[contador].mais_info); __fpurge(stdin);
                    if(stringEmBranco(crud[contador].mais_info))
                        {
                            system("clear");
                            mais_infoEmBranco = 1;
                            printf("Campo em Branco !!!\nPor favor digite novamente:\n\n\n");
                        }
                }while(mais_infoEmBranco);
                break;
                system("clear");
            case 5:
            system("clear");
                __fpurge(stdin);
                do{
                    ingresso_invalido = 0;
                    printf("Digite o preço atual do ingresso:\n");
                    scanf("%[^\n]s", crud[contador].ingresso); __fpurge(stdin);
                    if(numeroInvalido(crud[contador].ingresso))
                        {
                            system("clear");
                            ingresso_invalido = 1;
                            printf("Dados inválidos !!!\n Por favor digite novamente\n");
                        }
                }while(ingresso_invalido);
            default:
                system("clear");
                break;
        }
    }while(opcao != 6);

    fp = fopen(nome_arquivo_teatro, "wb+");
    fwrite(crud, sizeof(tipo_Teatro), n, fp);
    fclose(fp);
    free(crud);
    printf("Atração atualizada !\n\n\n");
    printf("Digite qualquer tecla para continuar...\n"); __fpurge(stdin);
    getchar();
    system("clear");
}

void deletarCrudTeatro()
{
    system("clear");
    int i = 0, n;
    tipo_Teatro* crud = (tipo_Teatro*)malloc(sizeof(tipo_Teatro)*50);
    char nome_crud[100];
    printf("Digite o nome da atração que deseja deletar:\n");
    scanf("%[^\n]s", nome_crud); __fpurge(stdin);
    FILE* fp = fopen(nome_arquivo_teatro, "rb");
    n = fread(crud, sizeof(tipo_Teatro), 50, fp);
    fclose(fp);
    remove(nome_arquivo_teatro);
    fp = fopen(nome_arquivo_teatro, "wb");
    while(i < n)
    {
        if (strcmp(crud[i].nome, nome_crud) == 0)
            i++;
        else
        {
            fwrite(&crud[i], sizeof(tipo_Teatro), 1, fp);
            i++;
        }
    }
    fclose(fp);
    free(crud);
    printf("Atração deletada !\n\n\n");
    printf("Digite qualquer tecla para continuar...\n"); __fpurge(stdin);
    getchar();
    system("clear");
}

void listarCrudsTeatro()
{
    system("clear");
    int n;
    tipo_Teatro* crud = (tipo_Teatro*)malloc(sizeof(tipo_Teatro));;
    FILE* fp = fopen(nome_arquivo_teatro, "rb");
    printf("Atrações cadastradas:\n");
    while(1)
    {
        n = fread(crud, sizeof(tipo_Teatro), 1, fp);
        if(n == 1)
            printf("%s\n", crud->nome);
        else
            break;
    }
    printf("\n");
    free(crud);
    fclose(fp);
    printf("Digite qualquer tecla para continuar...\n\n"); __fpurge(stdin);
    getchar(); __fpurge(stdin);
}

void visualizarCrudTeatro()
{
    system("clear");
    int n;
    int flag = 0;
    tipo_Teatro* crud = (tipo_Teatro*)malloc(sizeof(tipo_Teatro));
    char nome_crud[100];
    printf("Digite o nome da atração que deseja visualizar:\n");
    scanf("%[^\n]s", nome_crud); __fpurge(stdin);
    FILE* fp = fopen(nome_arquivo_teatro, "rb");
    while(1)
    {
        n = fread(crud, sizeof(tipo_Teatro), 1, fp);
        if(n == 1)
        {
            if (strcmp(crud->nome, nome_crud) == 0)
            {
                flag = 1;
                printf("\n");
                printf("Nome da atracao -----> %s\n", crud->nome);
                printf("Local da atracao ----> %s\n", crud->local);
                printf("Numero para contato -> %s\n", crud->numero_contato);
                printf("Mais informações ----> %s\n", crud->mais_info);
                printf("Preço do Ingresso ---> %s\n", crud->ingresso);
                printf("\n\n");
                break;
            }
        }
        else
            break;
    }
    free(crud);
    fclose(fp);
    if(flag == 0)
        printf("\nNome invalido\n\n");
    printf("Digite qualquer tecla para continuar...\n"); __fpurge(stdin);
    getchar(); __fpurge(stdin);
    system("clear");
}
