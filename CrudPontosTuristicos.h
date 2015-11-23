#ifndef CRUD_PONTOS_TURISTICOS
#define CRUD_PONTOS_TURISTICOS


typedef struct Pontos_turisticos
  {
    char nome[100];
    char localizacao[100];
    char numero_contato[10];
    char informacoes[300];/*descri��o geral do ponto tur�stico, pre�o, informa��es sobre agendamento de visita,horario de funcionamento,
    telefones para contato,pontos de referencia e a �rea do local.*/

  }tipo_PontosTuristicos;

void adicionarCrudTuristicos(char* nome, char* localizacao , char* numero_contato, char* informacoes);
void lerInfoCrudTuristicos();
void listarCrudsTuristicos();
void visualizarCrudTuristicos();
void deletarCrudTuristicos();


#endif
