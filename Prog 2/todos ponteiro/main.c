/*#include <stdio.h>


void trocar(int *pa, int *pb);

int main(void) {
    int a = 10, b = 20;
    trocar(&a, &b);
    printf("a = %d, b = %d", a, b);
    return 0;
}

void trocar(int *pa, int *pb) {
    int tmp = *pb;
    *pb = *pa;
    *pa = tmp;
}

int main(void) {
    int a[5] = {1,2,3,4,5};
    int b = 10;
    int *pa;
    int *pb;

    printf("%d\n", *a);
    printf("%d\n", *(a + 1));
    printf("%d\n", *(a + 2));
    printf("%d\n", *(a + 3));
    printf("%d", *(a + 4));
    return 0;
}*/

// #include <stdio.h> //! EXERCÍCIO EM AULA

// int duplicar(int *array);

// int main(void) {
//     int valores[5] = {1,2,3,4,5};
//     duplicar(valores);
//     for (int i = 0; i < 5; i++) {
//         printf("%d ", valores[i]);
//     }
    
// }

// int duplicar(int *array) {
//     for (int i = 0; i < sizeof(array); i++) {
//         *(array + i) *= 2;
//     }
// }

// #include <stdio.h> //! EXERCÍCIO 1

// void menorMaiorValor(int array[], int *ptrMaior, int *ptrMenor);

// int main(void) {
//     int valores[4], maior = 0, menor = 0;

//     for (int i = 0; i < 4; i++) {
//         printf("Digite o %d valor:", i+1);
//         scanf("%d", &valores[i]);
//     }
//     menorMaiorValor(valores, &maior, &menor);
//     printf("\nMaior: %d\nMenor: %d\n", maior, menor);
//     return 0;
// }

// void menorMaiorValor(int valores[], int *ptrMaior, int *ptrMenor) {
//     for (int i = 0; i < 4   ; i++) {    
//         if (*(valores + i) > *ptrMaior) {
//             *ptrMaior = *(valores + i);
//         }
//         if (*(valores + i) < *ptrMenor || i == 0) {
//             *ptrMenor = *(valores + i);
//         }
//     }
// }

// #include <stdio.h> // EXERCÍCIO 2

// void calcularMedia(float valores[], float *ptrMedia);

// int main(void) {
//     float valores[5], media = 0;
//     for (int i = 0; i < 5; i++) {
//         printf("Digite o %d valor:", i+1);
//         scanf("%f", &valores[i]);
//     }
//     calcularMedia(valores, &media);
//     printf("A media dos valores digitados ficou em %.2f", media);
//     return 0;
// }

// void calcularMedia(float valores[], float *ptrMedia) {
//     float soma = 0;
//     for (int i = 0; i < 5; i++) {
//         soma += *(valores + i);
//     }
//     *ptrMedia = soma / 5;
// }

/*#include <stdio.h>
#include <string.h>

void contarCaracteres(char *str, int *numCaracteres);

int main(void) {
    char string[50];
    printf("Digite o seu nome:");
    fgets(string, sizeof(string), stdin);
    int tam = strlen(string);
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ' ' || string[i] == '\n') {
            tam--;
        }
    }
    printf("%d\n", tam);
    return 0;
}

void contarCaracteres(char *str, int *numCaracteres) {
    
}*/

//#include<stdio.h>
//#include<stdlib.h>

/*int main()
{
    int *p

    p = (int*)malloc(5 * sizeof(int))

    for(int i = 0;i<5;i++){
        *(p+i)=i+1;
    }
    for(int i=0;i<5;i++){
        printf("%d\n",*(p+1))
    }
    printf("\n")

    p=realloc(p,3*sizeof(int));

    for(int i=0;i<3;i++){
        printf("%d",(p+i));
    }
    
    return 0;
}*/

// matriz aloc

// int main() {
//     int linha = 3;
//     int coluna = 2;
//     int numero = 0;
//     int maiorn;
//     int menorn;

//     int **mat = (int **)malloc(linha * sizeof(int *));
//     for (int i = 0; i < linha; i++) {
//         mat[i] = (int *)malloc(coluna * sizeof(int));
//     }

    
//     int i, j;
//     for (i = 0; i < linha; i++) {
//         for (j = 0; j < coluna; j++) {
//         printf("Digite um número: ");
//         scanf("%d", &numero);
    
//     mat[i][j] = numero;
//         }
//     }
    
//     maiorn = mat[0][0];
//     menorn = mat[0][0];

//     for (int i = 0; i < linha; i++) {
//         for (int j = 0; j < coluna; j++) {
//             if (mat[i][j] > maiorn) {
//                 maiorn = mat[i][j];
//             }
//             if (mat[i][j] < menorn) {
//                 menorn = mat[i][j];
//             }
//         }
//     }
    
//     for (i = 0; i < linha; i++) {
//         for (j = 0; j < coluna; j++) {
//             printf("[%d] ", mat[i][j]);
//         }
//         printf("\n");
//     }
    
    
//         printf("o maior numero é %d",maiorn);
//         printf("\no menor numero é %d",menorn);
    
//     free(mat);

//     return 0;
// }

//#include <stdio.h>

/*void maiormenor(int vetor[],int *maior,int *menor);

int main()
{
    int numeros[4];
    int maior=0;
    int menor=0;

    for(int i=0;i<4;i++){
    printf("Digite 4 numeros: ");
    scanf("%d",&numeros[i]);
    }

    maiormenor(numeros,&maior,&menor);

    printf("o maior numero C: %d\n",maior);
    printf("o menor numero C: %d\n",menor);


    return 0;
}
void maiormenor(int vetor[],int *maior,int *menor){

    *maior=*vetor;
    *menor=*vetor;

    for(int i=0;i<4;i++){
        if(*(vetor+i) > *maior){
            maior=(vetor+i);
        }
        if(*(vetor+i) < *menor){
            menor=(vetor+i);
        }
    }
}*/


#include<stdio.h>
#include<stdlib.h>

void maiormenor(int vetor[],int *soma,float *media);

int main()
{
	int numeros[5];
	int soma=0;
	float media;

	for(int i=0; i<5; i++) {
		printf("Digite 5 numeros: ");
		scanf("%d",&numeros[i]);
	}

	maiormenor(numeros,&soma,&media);

    printf("a media dos numeros é: %2.f\n",media);

	       return 0;
}
void maiormenor(int vetor[],int *soma,float *media) {
	*soma=0;

	for(int i=0; i<5; i++) {
		*soma += vetor[i];
	}
	*media=*soma/5;
}