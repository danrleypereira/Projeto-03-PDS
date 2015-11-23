void adicionarCrudTuristicos(char* nome, char* localizacao, char* numero_contato, char* informacoes)
{
    system("cls");
    char nome_arquivo[] = "./Pontos_Turisticos/Pontos_Turisticos.bin";

    //Alocar espa�o
    tipo_PontosTuristicos* crud_pontosTuristicos = (tipo_PontosTuristicos*)malloc(sizeof(tipo_PontosTuristicos));
    //Copiar informacoes
    strcpy(crud_pontosTuristicos->nome, nome);
    strcpy(crud_pontosTuristicos->localizacao, localizacao);
    strcpy(crud_pontosTuristicos->numero_contato, numero_contato);
    strcpy(crud_pontosTuristicos->informacoes, informacoes);

    FILE* fp = fopen(nome_arquivo,"wb+");
    fwrite(crud_pontosTuristicos, sizeof(tipo_PontosTuristicos), 1, fp);
    fclose(fp);
    printf("Ponto Turistico cadastrado !\n\n");
    printf("Digite qualquer tecla para continuar...\n"); __fpurge(stdin);
    getchar();
    system("cls");
}

void lerInfoCrudTuristicos()
{

    system("cls");
    char nome[100],localizacao[100],numero_contato[10],informacoes[300];
    int nomeEmBranco, localizacaoEmBranco, informacoesEmBranco, contato_invalido;

    //Introduzir nome do arquivo valido
     system("cls");
    do{
        nomeEmBranco = 0;
        printf("Digite o nome: \n"); scanf("%[^\n]s", nome);  __fpurge(stdin);
        if(stringEmBranco(nome))
        {
            system("cls");
            nomeEmBranco = 1;
            printf("Campo em Branco !!!\n Por favor, digite novamente:\n");
        }
    }while(nomeEmBranco);
    //Introduzir endere�o(localizacao) valido
    system("cls");
    do{
        localizacaoEmBranco = 0;
        printf("Digite o endereco (Localizacao): \n"); scanf("%[^\n]s", localizacao);  __fpurge(stdin);
        if(stringEmBranco(localizacao))
        {
            system("cls");
            localizacaoEmBranco = 1;
            printf("Campo em Branco !!!\n Por favor, digite novamente:\n");
        }
      }while(localizacaoEmBranco);
    //Introduzir mais informa��es validas
    system("cls");
    do{
        informacoesEmBranco = 0;
        printf("\nDigite as seguintes informacoes sobre o ponto turistico:\n1. Descricao Geral\n2.Valor da Entrada\n3.Horario de Funcionamento");
        printf("\n4.Informacoes sobre agendamento de Visita\n5.Telefones para contato\n6.Pontos de referencia\n7.Area do local\n");scanf("%[^\n]s", informacoes); __fpurge(stdin);
        if(stringEmBranco(informacoes))
        {
            system("cls");
            informacoesEmBranco = 1;
            printf("Campo em Branco !!!\n Por favor, digite novamente:\n");
        }
      }while(informacoesEmBranco);
    //Introduzir numero para numero_contato valido
   system("cls");
   do{
        contato_invalido = 0;
        printf("Digite o numero para obter mais informacoes: \n"); scanf("%[^\n]s", numero_contato); __fpurge(stdin);
        if(numeroInvalido(numero_contato))
        {
            system("cls");
            contato_invalido = 1;
            printf("Numero Invalido !!!\n Por favor, digite novamente:\n");
        }
    }while(contato_invalido);


    adicionarCrudTuristicos(nome, localizacao, numero_contato, informacoes);
}

void atualizarCrudTuristicos()
{
    system("cls");
    int n, contador = 0;
    int nomeEmBranco, localizacaoEmBranco, informacoesEmBranco, contato_invalido;
    int opcao;
    char nome_crud[100];
    printf("Digite o nome do Ponto Tur�stico que deseja atualizar: (N�o escrever o \".bin\" !!!)\n");
    scanf("%[^\n]s", nome_crud); __fpurge(stdin);
    tipo_PontosTuristicos* crud = (tipo_PontosTuristicos*)malloc(sizeof(tipo_PontosTuristicos)*50);
    FILE* fp = fopen("./Pontos_Turisticos/Pontos_Turisticos.bin", "rb");
    n = fread(crud, sizeof(tipo_PontosTuristicos), 50, fp);
    fclose(fp);
   while(contador < n)
    {
        if (strcmp(crud[contador].nome, nome_crud) == 0)
        {
           printf("\n");
           printf("Nome do Ponto Turistico -----> %s\n", crud->nome);
           printf("Localizacao do Ponto Turistico----> %s\n", crud->localizacao);
           printf("Numero para Contato -> %s\n", crud->numero_contato);
           printf("Mais informacoes ----> %s\n", crud->informacoes);
           printf("\n\n\n");
            break;
        }
        contador++;
    }

    printf("Digite qualquer tecla para continuar...\n"); __fpurge(stdin);
    getchar();
    system("cls");

    do{
        system("cls");
        printf("\n\nO que deseja alterar:\n1.Nome do Ponto Turistico\n2.Localizacao do Ponto Turistico\n");
        printf("3.N�mero para Contato\n4.Mais informa��es\n\nDigite -1 para voltar ao menu inicial\n");
        scanf("%d", &opcao); __fpurge(stdin);
        switch(opcao)
        {
            system("cls");
            case 1:
                system("cls");
                __fpurge(stdin);
                do{
                    nomeEmBranco = 0;
                    printf("Digite o novo nome do Ponto Turisico:\n");
                    scanf("%[^\n]s", crud[contador].nome); __fpurge(stdin);
                    if(stringEmBranco(crud[contador].nome))
                        {
                            system("cls");
                            nomeEmBranco = 1;
                            printf("Campo em Branco !!!\n Por favor, digite novamente:\n");
                        }
                }while(nomeEmBranco);
                break;
            system("cls");

            case 2:
                system("cls");
                __fpurge(stdin);
                do{
                    localizacaoEmBranco = 0;
                    printf("Digite a nova localizacao:\n");
                    scanf("%[^\n]s", crud[contador].localizacao); __fpurge(stdin);
                    if(stringEmBranco(crud[contador].localizacao))
                        {
                            system("cls");
                            localizacaoEmBranco = 1;
                            printf("Campo em Branco !!!\n Por favor, digite novamente:\n");
                        }
                }while(localizacaoEmBranco);
                break;
                system("cls");

            case 3:
                system("cls");
                __fpurge(stdin);
                do{
                    contato_invalido = 0;
                    printf("Digite o novo numero para contato:\n");
                    scanf("%[^\n]s", crud[contador].numero_contato); __fpurge(stdin);
                    if(numeroInvalido(crud[contador].numero_contato))
                        {
                            system("cls");
                            contato_invalido = 1;
                            printf("Numero Invalido !!!\n Por favor, digite novamente:\n");
                        }
                }while(contato_invalido);
                break;
                system("cls");

            case 4:
                system("cls");
                __fpurge(stdin);
                do{
                    informacoesEmBranco = 0;
                    printf("Digite as novas informacoes:\n");
                    scanf("%[^\n]s", crud[contador].informacoes); __fpurge(stdin);
                    if(stringEmBranco(crud[contador].informacoes))
                        {
                            system("cls");
                            informacoesEmBranco = 1;
                            printf("Campo em Branco !!!\n Por favor, digite novamente:\n");
                        }
                }while(informacoesEmBranco);
                break;
                system("cls");

            default:
                system("cls");
                break;
        }
    }while(opcao != 5);


    fp = fopen("./Pontos_Turisticos/Pontos_Turisticos.bin","wb+");
    fwrite(crud, sizeof(tipo_PontosTuristicos), n, fp);
    fclose(fp);
    free(crud);
    printf("Ponto Turistico atualizado !\n\n\n");
    printf("Digite qualquer tecla para continuar...\n"); __fpurge(stdin);
    getchar();
    system("cls");
}

void deletarCrudTuristicos()
{
    system("cls");
    int i = 0, n;
    char nome_crud[100];
    tipo_PontosTuristicos* crud = (tipo_PontosTuristicos*)malloc(sizeof(tipo_PontosTuristicos)*50);
    printf("Digite o nome do ponto turistico que deseja deletar: (N�o escrever o \".bin\" !!!)\n");
    scanf("%[^\n]s", nome_crud); __fpurge(stdin);
    FILE* fp = fopen("./Pontos_Turisticos/Pontos_Turisticos.bin", "rb");
    n = fread(crud, sizeof(tipo_PontosTuristicos), 50, fp);
    fclose(fp);
    remove("./Pontos_Turisticos/Pontos_Turisticos.bin");
    fp = fopen("./Pontos_Turisticos/Pontos_Turisticos.bin", "wb");
    while(i < n)
    {
        if (strcmp(crud[i].nome, nome_crud) == 0)
            i++;
        else
        {
            fwrite(&crud[i], sizeof(tipo_PontosTuristicos), 1, fp);
            i++;
        }
    }
    fclose(fp);
    free(crud);
    printf("Ponto Turistico deletado !\n\n\n");
    printf("Digite qualquer tecla para continuar...\n"); __fpurge(stdin);
    getchar();
    system("cls");
}

void listarCrudsTuristicos()
{

    system("cls");
    int n;
    tipo_PontosTuristicos* crud = (tipo_PontosTuristicos*)malloc(sizeof(tipo_PontosTuristicos));;
    FILE* fp = fopen("./Pontos_Turisticos/Pontos_Turisticos.bin", "rb");
    printf("Pontos Turisticos cadastrados:\n");;
    while(1)
    {
        n = fread(crud, sizeof(tipo_PontosTuristicos), 1, fp);
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

void visualizarCrudTuristicos()
{
    system("cls");
    int n;
    int flag = 0;
    tipo_PontosTuristicos* crud = (tipo_PontosTuristicos*)malloc(sizeof(tipo_PontosTuristicos));
    char nome_crud[100];
    printf("Digite o nome do ponto turistico que deseja visualizar: (N�o escrever o \".bin\" !!!)\n");
    scanf("%[^\n]s", nome_crud);__fpurge(stdin);
    FILE* fp = fopen("./Pontos_Turisticos/Pontos_Turisticos.bin", "rb");
    while(1)
    {
        n = fread(crud, sizeof(tipo_PontosTuristicos), 1, fp);
        if(n == 1)
        {
            if (strcmp(crud->nome, nome_crud) == 0)
            {
                flag = 1;
                printf("\n");
                printf("Nome do Ponto Turistico -----> %s\n", crud->nome);
                printf("Localizacao do Ponto Turistico----> %s\n", crud->localizacao);
                printf("Numero para Contato -> %s\n", crud->numero_contato);
                printf("Mais informacoes ----> %s\n", crud->informacoes);
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
    system("cls");
}
