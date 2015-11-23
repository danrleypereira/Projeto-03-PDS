void conteudo()
{
    system("clear");
    printf("\"Conteudo Infantil\"\n");
    printf("Desenvolvedores: Andre de Sousa Costa Filho e Matheus Batista Silva\n\n\n");

    int opcao;

    do //menu
    {
        printf("O que deseja fazer:\nDigite 1 para Adicionar atracao\nDigite 2 para Visualizar uma atracao\nDigite 3 para Atualizar uma atracao\nDigite 4 para Deletar uma atracao\n");
        printf("Digite 5 para sair\n\n");

        scanf("%d", &opcao);    __fpurge(stdin);

        switch (opcao)
        {
            case 1:
                lerInfoCrudConteudo();
                break;
            case 2:
                listarCrudsConteudo();
                visualizarCrudConteudo();
                break;
            case 3:
                listarCrudsConteudo();
                atualizarCrudConteudo();
                break;
            case 4:
                listarCrudsConteudo();
                deletarCrudConteudo();
                break;
            default:
                system("clear");
                break;
        }
    } while (opcao != 5);
}
