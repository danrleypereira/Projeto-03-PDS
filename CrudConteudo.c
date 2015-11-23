void adicionarCrudConteudo(char *nome_atracao, char *local, char *num_contato, char *mais_info)
{
    system("clear");
    char nome_arquivo[] = "./Conteudo_Infantil/Conteudo.bin";
    //Alocar espaço
    tipo_Conteudo *crud_conteudo = (tipo_Conteudo*)malloc(sizeof(tipo_Conteudo));
    //Copiar informacoes
    strcpy(crud_conteudo->nome, nome_atracao);
    strcpy(crud_conteudo->local, local);
    strcpy(crud_conteudo->mais_info, mais_info);
    strcpy(crud_conteudo->numero_contato, num_contato);
    //escreve no arquivo
    FILE* fp = fopen(nome_arquivo,"ab+"); //append binary
    fwrite(crud_conteudo, sizeof(tipo_Conteudo), 1, fp);
    fclose(fp);
    //mensagem de conclusão
    printf("Atracao cadastrada !\n\n\n");
    printf("Digite qualquer tecla para continuar...\n"); __fpurge(stdin);
    getchar();
    system("clear");
}


void lerInfoCrudConteudo()
{
    system("clear");
    char nome_atracao[100], local[100], mais_info[500], num_contato[50];/*numero para mais informações.*/
    int nomeEmBranco, localEmBranco, mais_infoEmBranco, contato_invalido;

    //Introduzir nome do arquivo valido
    system("clear");
    do{
        nomeEmBranco = 0;
        printf("Introduza o nome: \n");     scanf("%[^\n]s", nome_atracao);  __fpurge(stdin);
        if(stringEmBranco(nome_atracao))
        {
            system("clear");
            nomeEmBranco = 1;
            printf("Campo em Branco !!!\nPor favor digite novamente:\n\n\n");
        }
    }while(nomeEmBranco);//variavel que define nome em branco

    //Introduzir endereço(local) valido
    system("clear");
    do{
        localEmBranco = 0;
        printf("Introduza o endereco: \n");     scanf("%[^\n]s", local);  __fpurge(stdin);
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
        printf("Introduza a descrição da atracao contendo as seguintes informacoes:\n1. Informacoes gerais sobre a atracao;\n2. Restricoes como idade minima;\n3.Como chegar;\n4.Preco do ingresso (caso exista);\n");  scanf("%[^\n]s", mais_info);
            __fpurge(stdin);

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
        printf("Introduza o numero para obter mais informacoes: \n"); scanf("%[^\n]s", num_contato);  __fpurge(stdin);
        if(numeroInvalido(num_contato))
        {
            system("clear");
            contato_invalido = 1;
            printf("Numero Invalido !!!\nPor favor digite novamente:\n\n\n");
        }
    }while(contato_invalido);

    adicionarCrudConteudo(nome_atracao, local, num_contato, mais_info);
}

void atualizarCrudConteudo()
{
    system("clear");
    int n, contador = 0;
    int nomeEmBranco, localEmBranco, mais_infoEmBranco, contato_invalido;
    int opcao;
    char nome_crud[100];
    printf("Digite o nome da atracao que deseja atualizar: (Nao escrever o \".bin\" !!!)\n");

    scanf("%[^\n]s", nome_crud);        __fpurge(stdin);

    tipo_Conteudo *crud = (tipo_Conteudo*)malloc(sizeof(tipo_Conteudo) * 50);

    FILE* fp = fopen("./Conteudo_Infantil/Conteudo.bin", "rb");

    n = fread(crud, sizeof(tipo_Conteudo), 50, fp); //le uma parte determinada do arquivo

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
    printf("Digite qualquer tecla para continuar...\n");    __fpurge(stdin);
    getchar();
    system("clear");

    do{
        system("clear");
        printf("O que deseja alterar:\nDigite 1 para alterar o nome da atraao\nDigite 2 para alterar local da atracao\n");
        printf("Digite 3 para alterar numero para contato\nDigite 4 para alterar mais informacoes\nDigite 5 para voltar ao menu inicial\n");
        scanf("%d", &opcao); __fpurge(stdin);
        switch(opcao)
        {
            system("clear");
            case 1:
                system("clear");
                __fpurge(stdin);
                do{
                    nomeEmBranco = 0;
                    printf("Digite o novo nome da atracao:\n");
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
                    printf("Digite o novo local da atracao:\n");
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
                    printf("Digite as novas informacoes:\n");
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

    fp = fopen("./Conteudo_Infantil/Conteudo.bin","wb+");
    fwrite(crud, sizeof(tipo_Conteudo), n, fp);
    fclose(fp);     free(crud);

    printf("Atracao atualizada !\n\n\n");
    printf("Digite qualquer tecla para continuar...\n"); __fpurge(stdin);
    getchar();
    system("clear");
}


void deletarCrudConteudo()
{
    system("clear");
    int i = 0, n;
    tipo_Conteudo *crud = (tipo_Conteudo*) malloc(sizeof(tipo_Conteudo) * 50);

    char nome_crud[100];

    printf("Digite o nome da atracao que deseja deletar: (Nao escrever o \".bin\" !!!)\n");

    scanf("%[^\n]s", nome_crud);    __fpurge(stdin);

    FILE* fp = fopen("./Conteudo_Infantil/Conteudo.bin", "rb");
    n = fread(crud, sizeof(tipo_Conteudo), 50, fp);
    fclose(fp);

    remove("./Conteudo_Infantil/Conteudo.bin");

    fp = fopen("./Conteudo_Infantil/Conteudo.bin", "wb");

    while(i < n)
    {
        if (strcmp(crud[i].nome, nome_crud) == 0)
            i++;
        else
        {
            fwrite(&crud[i], sizeof(tipo_Conteudo), 1, fp);
            i++;
        }
    }
    fclose(fp);    free(crud);

    printf("Atracao deletada com sucesso !\n\n\n");
    printf("Digite qualquer tecla para continuar...\n");    __fpurge(stdin);
    getchar();
    system("clear");
}


void listarCrudsConteudo()
{
    system("clear");
    int n;

    tipo_Conteudo* crud = (tipo_Conteudo*) malloc(sizeof(tipo_Conteudo));;

    FILE *fp = fopen("./Conteudo_Infantil/Conteudo.bin", "rb");

    printf("Atracoes cadastradas:\n");
    while(1)
    {
        n = fread(crud, sizeof(tipo_Conteudo), 1, fp);
        if(n == 1)
            printf("%s\n", crud->nome);
        else
            break;
    }

    printf("\n");   free(crud);

    fclose(fp);

    printf("Digite qualquer tecla para continuar...\n\n");  __fpurge(stdin);
    getchar();
}


void visualizarCrudConteudo()
{
    system("clear");
    int n;
    int flag = 0;

    tipo_Conteudo* crud = (tipo_Conteudo*) malloc(sizeof(tipo_Conteudo));

    char nome_crud[100];

    printf("Digite o nome da atracao que deseja visualizar: (Nao escrever o \".bin\" !!!)\n");

    scanf("%[^\n]s", nome_crud); __fpurge(stdin);

    FILE *fp = fopen("./Conteudo_Infantil/Conteudo.bin", "rb");
    while(1)
    {
        n = fread(crud, sizeof(tipo_Conteudo), 1, fp);
        if(n == 1)
        {
            if (strcmp(crud->nome, nome_crud) == 0)
            {
                flag = 1;
                printf("\n");
                printf("Nome da atracao -----> %s\n", crud->nome);
                printf("Local da atracao ----> %s\n", crud->local);
                printf("Numero para contato -> %s\n", crud->numero_contato);
                printf("Mais informacoes ----> %s\n", crud->mais_info);
                printf("\n\n");
                break;
            }
        }
        else
            break;
    }

    free(crud);    fclose(fp);

    if(flag == 0)
        printf("\nNome invalido\n\n");

    printf("Digite qualquer tecla para continuar...\n");     __fpurge(stdin);
    getchar();
    system("clear");
}
