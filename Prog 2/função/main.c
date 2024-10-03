#include <stdio.h>
//--------------------------------------------------------------------------------------------------------------------
// int cubo(int entrada){ //super importante!!!!!

//     int main(){
//         int x = 2
//         printf("x é %d\n",x);
//         x = cubo(x);
//         printf("x agora é %d\n", x);

//     return 0;
//     }
    
//     int cubo(int entrada){
//         int saida = entrada * entrada * entrada;
//         return saida;
//     }
// }
//-------------------------------------------------------------------------------------------------------------------
// int maior(int x, int y){
//     if(x>y){
//         return x;
//     }
//     else{
//         return y;
//     }
// }
//-----------------------------------------------------------------------------------------------------------------------
//MULTIPLICAR !!!!!!!!!!!!!!!

// float multiplicacao(float x , float y);

// int main(){
//     float n1 , n2, total = 0;
//     printf("digite um numero:\n");
//     scanf("%f", &n1);    
//     printf("digite o segundo numero:\n");
//     scanf("%f", &n2);
//     total = multiplicacao(n1, n2);
//     printf("total: %.2f", total);
//     return 0;
// }
// float multiplicacao(float x, float y){
//     float t = x * y;
//     return t;
// }
//--------------------------------------------------------------------------------------------------------------------------
// exercicio 2

// void votar(int a){
//     if(a >= 18 && a <= 70){
//         printf("Voto obrigatório");
//     }
//     else{
//         printf("Não precisa votar");
//     }
// }

// int main(){

//     int idade = 0;

//     printf("Digite sua idade:");
//     scanf("%d", &idade);
//     votar(idade);

//     return 0;
// }
//--------------------------------------------------------------------------------------------------------------
//Exercicio 3
// int anos(int x, int y, int z){
//     return x*365 + y*30 + z;
// }

// int main(){

//     int idade, mes, dias;
//     printf("Quantos anos vc tem:");
//     scanf("%d", &idade);
//     printf("Quantos meses de vida vc tem:");
//     scanf("%d", &mes);
//     printf("Quantos dias de vida vc tem:");
//     scanf("%d", &dias);
//     printf("%d", anos(idade, mes, dias));

//     return 0;
// }
//-----------------------------------------------------------------------------------------------------------------------------
//exercicio
// float total(char s, char t);

// int main(){
//     char sexo, tam;

//     printf("digite seu sexo [ M / F ]: ");
//     scanf(" %c", &sexo);
//     printf("digite seu tamanho [P / M / G]: ");
//     scanf(" %c", &tam);
//     printf("valor total %.2f", total(sexo, tam));

// }


// float total(char s, char t){
//     switch(s){
//         case 'M':
//         case 'm':
//             switch(t){
//                 case'P':
//                 case'p':
//                     return 22.25;

//                 case'M':
//                 case'm':            
//                     return 27.15;

//                 case'G':
//                 case'g':
//                     return 40.00;
//             }
//         case 'F':
//         case 'f':
//             switch(t){
//                 case'P':
//                 case'p':
//                     return 28.75;

//                 case'M':
//                 case'm':            
//                     return 39.99;

//                 case'G':
//                 case'g':
//                     return 51.00;
//         }
//     }
// }
