int numeroInvalido(char* numero)
{
    int i, j;
    for (i = 0; numero[i] != '\0' ;i++)
    {
        if(!isdigit(numero[i])){
            return 1;
        }
    }
    return 0;
}

int stringEmBranco(char* informacao)
{
    int i;
    for (i = 0; informacao[i] != '\0' ;i++)
    {
        if(informacao[i] != ' ')
            return 0;
    }
    return 1;
}
