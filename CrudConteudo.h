#ifndef CRUD_CONTEUDO
#define CRUD_CONTEUDO

typedef struct conteudo
{
    char nome[100];
    char local[100];
    char numero_contato[100];
    char mais_info[500];
} tipo_Conteudo;

void adicionarCrudConteudo(char* nome_atracao, char* local, char* num_contato, char* mais_info);
void lerInfoCrudConteudo();
void listarCrudsConteudo();
void visualizarCrudConteudo();
void deletarCrudConteudo();
void atualizarCrudConteudo();

#endif
