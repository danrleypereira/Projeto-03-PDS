#ifndef CRUD_TEATRO
#define CRUD_TEATRO

#define nome_arquivo_teatro "./Teatro_Infantil/Atracoes.bin"

typedef struct teatro
{
    char nome[100];
    char local[100];
    char numero_contato[100];//numero para mais informações.
    char mais_info[500];
    char ingresso[4];
} tipo_Teatro;

void adicionarCrudTeatro(char* nome_atracao, char* local, char* num_contato, char* mais_info, char* ingresso);
void lerInfoCrudTeatro();
void listarCrudsTeatro();
void visualizarCrudTeatro();
void deletarCrudTeatro();
void atualizarCrudTeatro();

#endif
