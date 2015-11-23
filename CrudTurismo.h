#ifndef CRUD_TURISMO
#define CRUD_TURISMO

typedef struct turismo
{
    char nome[100];
    char local[100];
    char numero_contato[100];//numero para mais informações.
    char mais_info[500];
} tipo_Turismo;

void adicionarCrudGoias(char* nome_atracao, char* local, char* num_contato, char* mais_info);
void lerInfoCrudGoias();
void listarCrudsGoias();
void visualizarCrudGoias();
void deletarCrudGoias();
void atualizarCrudGoias();

#endif
