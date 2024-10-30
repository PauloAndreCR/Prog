#include <stdio.h>

//Questão 1

// int main(){
//     float media=0;
//     int soma=0;
//     float matriz[3][3];

//         for(int i=0; i<3;i++){
//             for(int j=0;j<3;j++){
//                 printf("prencha a matriz com os numeros: ");
//                 scanf("%f",&matriz[i][j]);
//             }
//         }
        
//         for(int i=0; i<3;i++){
//             for(int j=0;j<3;j++){
//                 printf("[%.2f]",matriz[i][j]);
//             }
//         printf("\n");
//         }
//         printf("\n");
//         printf("\n");
//         for(int i=0;i<3;i++){
//             for(int j=0;j<3;j++){
//                 if(i+j == (3 - 1)){
//                     soma=matriz[i][j]+soma;
//                     printf("[%.2f]",matriz[i][j]);
//                 }else{
//                     printf("[*]");
//                 }
//             }
//         printf("\n");
//         }
//         printf("\n");
//         media=soma/3;
//         printf("a soma da diagonal secundária da matriz é: %.2f",media);
// }

//Questão 2

void pesopessoas(float *pesos, float *maiorpeso);
int main(){
    float pesos[4];
    float maiorpeso=0;
    
    for(int i=0;i<4;i++){
        printf("qual seu peso? ");
        scanf("%f",&pesos[i]);
    pesopessoas(pesos,&maiorpeso);
    }
    
    printf("o maior peso e: %.2f",maiorpeso);
    return 0;
}
void pesopessoas(float*pesos, float *maiorpeso){
    if(*pesos>*maiorpeso){
         *maiorpeso = *pesos;
    }
}