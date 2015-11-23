void pontos()
{

    system("cls");
    printf("\"Pontos Turísticos em Goiânia\"\n");
    printf("Desenvolvedores: Gabriela Alves da Gama e Cecília Dib\n\n\n");
    int opcao;
    do
    {
        printf("O que deseja fazer:\nDigite 1 para Adicionar Ponto Turistico\nDigite 2 para Visualizar um Ponto Turistico\nDigite 3 para Atualizar um Ponto Turistico\nDigite 4 para Deletar um Ponto Turistico\n");
        printf("\nDigite 5 para sair\n\n");
        scanf("%d", &opcao); __fpurge(stdin);
        switch (opcao)
        {
            case 1:
                lerInfoCrudTuristicos();
                break;
            case 2:
                listarCrudsTuristicos();
                visualizarCrudTuristicos();
                break;
            case 3:
                listarCrudsTuristicos();
                atualizarCrudTuristicos();
                break;
            case 4:
                listarCrudsTuristicos();
                deletarCrudTuristicos();
                break;
            default:
                system("cls");
                break;
        }
    } while (opcao != 5);
}
