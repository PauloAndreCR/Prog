#include <stdio.h>
#include <string.h>
// struct aluno{
//     char nome[50];
//     float nota1;
//     float nota2;
//     float nota3;
//     float media;
//     float soma;
// };
// int main(){
//     struct aluno al;
    
//     printf("digite seu nome: ");
//     fgets(al.nome,sizeof(al.nome),stdin);
//     printf("digite sua primeira nota: ");
//     scanf("%f",&al.nota1);
//     printf("digite sua segunda nota: ");
//     scanf("%f",&al.nota2);
//     printf("digite sua terceira nota: ");
//     scanf("%f",&al.nota3);

//     al.soma=al.nota1+al.nota2+al.nota3;
//     al.media=al.soma/3;

//     printf("sua média é: %2.f\n",al.media);
//     printf("sua nota 1 é: %2.f\n",al.nota1);
//     printf("sua nota 2 é: %2.f\n",al.nota2);
//     printf("sua nota 3 é: %2.f\n",al.nota3);
//     printf("seu nome é: %s\n",al.nome);
    
//     return 0;
// }



// struct tempo{
//     int horas;
//     int minutos;
// };

// typedef struct tempo temp;

// temp tempo_total(int numero){
//     temp resultado;
//     resultado.horas = numero / 60;
//     resultado.minutos = numero % 60;
//     return resultado;
// }

// int main(){
//     int numero;
//     printf("digite um numero para ver em horas e minutos:");
//     scanf("%d",&numero);
    
//     temp resultado=tempo_total(numero);
    
//     printf("seu numero em horas %d em minutos %d",resultado.horas,resultado.minutos);
    
//     return 0;
// }


struct endereco{
    char rua[50];
    char estado[50];
    char cidade[50];
};
typedef struct endereco endc;
struct pessoa{
    char nome[50];
    endc endereco;
};
typedef struct pessoa pes;
void inform(pes pessoa);

int main(){
    pes pessoa;
    
    printf("qual sua rua?:");
    fgets(pessoa.endereco.rua, 50, stdin);
    printf("qual sua cidade?:");
    fgets(pessoa.endereco.cidade, 50, stdin);
    printf("qual seu estado?:");
    fgets(pessoa.endereco.estado, 50, stdin);
    printf("qual seu nome?:");
    fgets(pessoa.nome, 50, stdin);
    
    inform(pessoa);
    
    return 0;
}
void inform(pes pessoa){
    printf("\n%s",pessoa.nome);
    printf("\n%s",pessoa.endereco.rua);
    printf("\n%s",pessoa.endereco.cidade);
    printf("\n%s",pessoa.endereco.estado);
}