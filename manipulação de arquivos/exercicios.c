#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    //1111111111111111111111
    
    // int numeros[5];
    
    //  FILE *arquivo=fopen("registro.txt","w");
    
    //  if (arquivo == NULL) {
    //      printf("Erro ao abrir o arquivo.");
    //  return 1;
    //  }

    // for(int i=0;i<5;i++){
    //     fscanf(arquivo,"%d",&numeros[i]);
    // }
    
    // for(int i=0;i<5;i++){
    //     printf("escolha um numero!");
    //     scanf("%d", &numeros[i]);
    //     fprintf(arquivo,"%d\n",numeros[i]);
    // }
    
    // for(int i=0;i<5;i++){
    //     printf("numero: %d",numeros[i]);
    // }
    
    // fclose(arquivo);
    // return 0;
    
    
    
    
    // 22222222222222222222
    
    // FILE *arquivo=fopen("Registro.txt","r");
    
    // if(arquivo == NULL){
    //      printf("Erro ao abrir o arquivo.");
    //  return 1;
    //  }
     
    //  int cont=0;
    //  char ch;
     
    //  while(ch != EOF){
    //      ch = getc(arquivo);
    //      if(ch >= 0 && ch <= 127 && ch != ' '){
    //             cont++;
    //         }
    //     }
        
    //     printf("o numero de caracteres escrito é: %d\n",cont);
        
    // fclose(arquivo);
    
    
    
    
    //3333333333333333333333333333
    
    
    char frase[50];
    int qtdLinhas=0;
    int qtdPalavras=0;
    
    FILE*arquivo=fopen("Registro.txt","r");
    
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.");
    return 1;
    }
    
    while(fgets(frase,sizeof(frase),arquivo)!=NULL){
        qtdLinhas++;
        char *palavra = strtok(frase," \t\n");
        while(palavra!=NULL){
        qtdPalavras++;
        palavra = strtok(NULL," \t\n");
        }
    }
    printf("qtd de palavras %d\n",qtdPalavras);
    printf("qtd de qtdLinhas %d",qtdLinhas);
    
    fclose(arquivo);
}