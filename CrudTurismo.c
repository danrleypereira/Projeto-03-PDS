void adicionarCrudGoias(char* nome_atracao, char* local, char* num_contato, char* mais_info)
{
    system("clear");
    char nome_arquivo[] = "./Turismo_em_Goias/Turismo_Goias.bin";
    //Alocar espaço
    tipo_Turismo* crud_turismo = (tipo_Turismo*)malloc(sizeof(tipo_Turismo));
    //Copiar informacoes
    strcpy(crud_turismo->nome, nome_atracao);
    strcpy(crud_turismo->local, local);
    strcpy(crud_turismo->mais_info, mais_info);
    strcpy(crud_turismo->numero_contato, num_contato);
    //
    FILE* fp = fopen(nome_arquivo,"ab+");
    fwrite(crud_turismo, sizeof(tipo_Turismo), 1, fp);
    fclose(fp);
    printf("Atração cadastrada !\n\n\n");
    printf("Digite qualquer tecla para continuar...\n"); __fpurge(stdin);
    getchar();
    system("clear");
}

//sem alterações
void lerInfoCrudGoias()
{
    system("clear");
    char nome_atracao[100], local[100], mais_info[500], num_contato[50];/*numero para mais informações.*/
    int nomeEmBranco, localEmBranco, mais_infoEmBranco, contato_invalido;
    //Introduzir nome do arquivo valido
    system("clear");
    do{
        nomeEmBranco = 0;
        printf("Introduza o nome: \n"); scanf("%[^\n]s", nome_atracao);  __fpurge(stdin);
        if(stringEmBranco(nome_atracao))
        {
            system("clear");
            nomeEmBranco = 1;
            printf("Campo em Branco !!!\nPor favor digite novamente:\n\n\n");
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
            printf("Campo em Branco !!!\nPor favor digite novamente:\n\n\n");
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
            printf("Campo em Branco !!!\nPor favor digite novamente:\n\n\n");
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
            printf("Numero Invalido !!!\nPor favor digite novamente:\n\n\n");
        }
    }while(contato_invalido);

    adicionarCrudGoias(nome_atracao, local, num_contato, mais_info);
}

//pronta(15/11)
void atualizarCrudGoias()
{
    system("clear");
    int n, contador = 0;
    int nomeEmBranco, localEmBranco, mais_infoEmBranco, contato_invalido;
    int opcao;
    char nome_crud[100];
    printf("Digite o nome da atração que deseja atualizar: (Não escrever o \".bin\" !!!)\n");
    scanf("%[^\n]s", nome_crud); __fpurge(stdin);
    tipo_Turismo* crud = (tipo_Turismo*)malloc(sizeof(tipo_Turismo)*50);
    FILE* fp = fopen("./Turismo_em_Goias/Turismo_Goias.bin", "rb");
    n = fread(crud, sizeof(tipo_Turismo), 50, fp);
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
        printf("Digite 3 para alterar número para contato\nDigite 4 para alterar mais informações\nDigite 5 para voltar ao menu inicial\n");
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
            default:
                system("clear");
                break;
        }
    }while(opcao != 5);

    fp = fopen("./Turismo_em_Goias/Turismo_Goias.bin","wb+");
    fwrite(crud, sizeof(tipo_Turismo), n, fp);
    fclose(fp);
    free(crud);
    printf("Atração atualizada !\n\n\n");
    printf("Digite qualquer tecla para continuar...\n"); __fpurge(stdin);
    getchar();
    system("clear");
}

//pronta(13/11)
void deletarCrudGoias()
{
    system("clear");
    int i = 0, n;
    tipo_Turismo* crud = (tipo_Turismo*)malloc(sizeof(tipo_Turismo)*50);
    char nome_crud[100];
    printf("Digite o nome da atração que deseja deletar: (Não escrever o \".bin\" !!!)\n");
    scanf("%[^\n]s", nome_crud); __fpurge(stdin);
    FILE* fp = fopen("./Turismo_em_Goias/Turismo_Goias.bin", "rb");
    n = fread(crud, sizeof(tipo_Turismo), 50, fp);
    fclose(fp);
    remove("./Turismo_em_Goias/Turismo_Goias.bin");
    fp = fopen("./Turismo_em_Goias/Turismo_Goias.bin", "wb");
    while(i < n)
    {
        if (strcmp(crud[i].nome, nome_crud) == 0)
            i++;
        else
        {
            fwrite(&crud[i], sizeof(tipo_Turismo), 1, fp);
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

//pronta(12/11)
void listarCrudsGoias()
{
    system("clear");
    int n;
    tipo_Turismo* crud = (tipo_Turismo*)malloc(sizeof(tipo_Turismo));;
    FILE* fp = fopen("./Turismo_em_Goias/Turismo_Goias.bin", "rb");
    printf("Atrações cadastradas:\n");
    while(1)
    {
        n = fread(crud, sizeof(tipo_Turismo), 1, fp);
        if(n == 1)
            printf("%s\n", crud->nome);
        else
            break;
    }
    printf("\n");
    free(crud);
    fclose(fp);
    printf("Digite qualquer tecla para continuar...\n\n"); __fpurge(stdin);
    getchar();
}

//pronta(13/11)
void visualizarCrudGoias()
{
    system("clear");
    int n;
    int flag = 0;
    tipo_Turismo* crud = (tipo_Turismo*)malloc(sizeof(tipo_Turismo));
    char nome_crud[100];
    printf("Digite o nome da atração que deseja visualizar: (Não escrever o \".bin\" !!!)\n");
    scanf("%[^\n]s", nome_crud); __fpurge(stdin);
    FILE* fp = fopen("./Turismo_em_Goias/Turismo_Goias.bin", "rb");
    while(1)
    {
        n = fread(crud, sizeof(tipo_Turismo), 1, fp);
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
    getchar();
    system("clear");
}
