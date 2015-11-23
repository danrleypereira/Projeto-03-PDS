void turismo()
{
    system("clear");
    printf("\"Turismo em Goiás\"\n");
    printf("Desenvolvedores: Luis Gustavo Avelino de Lima Jacinto e Alexsandro Silva Novais\n\n\n");
    int opcao;
    do
    {
        printf("O que deseja fazer:\nDigite 1 para Adicionar atração\nDigite 2 para Visualizar uma atração\nDigite 3 para Atualizar uma atração\nDigite 4 para Deletar uma atração\n");
        printf("Digite 5 para sair\n\n");
        scanf("%d", &opcao); __fpurge(stdin);
        switch (opcao)
        {
            case 1:
                lerInfoCrudGoias();
                break;
            case 2:
                listarCrudsGoias();
                visualizarCrudGoias();
                break;
            case 3:
                listarCrudsGoias();
                atualizarCrudGoias();
                break;
            case 4:
                listarCrudsGoias();
                deletarCrudGoias();
                break;
            default:
                system("clear");
                break;
        }
    } while (opcao != 5);
}
