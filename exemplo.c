#include <stdio.h>
typedef struct {int Dia,Mes,Ano;} DATA;
typedef struct pessoa
{
 char Nome[100];
 int Idade;
 int Salario;
 DATA Nasc;
} PESSOA;

void ler_pessoa(PESSOA *ptr)
{
  memset(ptr->Nome, '\0', sizeof(ptr->Nome));
 printf("Introduza o nome: "); scanf("%s", &ptr->Nome);
 printf("Introduza a idade: "); scanf("%d", &ptr->Idade);
 printf("Introduza o salario: "); scanf("%d", &ptr->Salario);
 printf("Introduza o dia nascimento: "); scanf("%d", &ptr->Nasc.Dia);
 printf("Introduza o mes nascimento: "); scanf("%d", &ptr->Nasc.Mes);
 printf("Introduza o ano nascimento: "); scanf("%d", &ptr->Nasc.Ano);
}
void Mostrar(struct pessoa x)
{
 printf("Nome        : %s \n",x.Nome);
 printf("Idade       : %d \n",x.Idade);
 printf("Salario     : %d \n",x.Salario);
 printf("Data Nasc.  : %d/%d/%d \n",x.Nasc.Dia,x.Nasc.Mes,x.Nasc.Ano);
}
void main(void)
{
   struct pessoa p;
   ler_pessoa(&p);
   Mostrar(p);
  //  abrir_fich(&p);
  //  getch();
}
