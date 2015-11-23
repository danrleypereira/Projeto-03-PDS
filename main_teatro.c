void teatro()
{
  system("clear");
    printf("\"Teatro Infantil\"\n");
    printf("Desenvolvedores: Danrley Willyan e Vitor Gomes\n\n\n");
    int opcao;
    do
    {
        printf("O que deseja fazer:\nDigite 1 para Adicionar atração\nDigite 2 para Visualizar uma atração\nDigite 3 para Atualizar uma atração\nDigite 4 para Deletar uma atração\n");
        printf("\nDigite -1 para sair\n\n");
        scanf("%d", &opcao); __fpurge(stdin);
        switch (opcao)
        {
            case 1:
                lerInfoCrudTeatro();
                break;
            case 2:
                listarCrudsTeatro();
                visualizarCrudTeatro();
                break;
            case 3:
                listarCrudsTeatro();
                atualizarCrudTeatro();
                break;
            case 4:
                listarCrudsTeatro();
                deletarCrudTeatro();
                break;
            default:
                break;
        }
    } while (opcao != -1);
}
