#include <stdio.h>
#include <string.h>

int main() {
  char vendas[5][5];
  float valortotalvendas[5];
  int quantidadedecamisavendidas[5];
  int codigodevenda[5];
  char tamanhocamisa[5];
  int tipodevenda[5];
  int parada = 0;
  char menucontinuar;
  int menucodigo = 0;
  int menu = 0;
  float valortotalp = 0;
  float valortotal = 0;
  float mediavalor = 0;
  int qtdtotalcamisas = 0;
  float maior = 0;
  int tipodevendamaisvendido = 0;
  int maiorcontagem = -1;
  int contadortipovenda[5] = {0};
  float valorperg = 0;
  int contadorvalorabaixo = 0;
  int contadoracimacem = 0;
  int contadorg = 0;
  char voltamenu2;

  for (int i = 0; i < 5; i++) {
    printf("-------------------------------------------------------------------"
           "--------------------\n");
    do {
      printf("Venda %d\nQual o valor total da venda: ", i + 1);
      scanf("%f", &valortotalvendas[i]);
      if (valortotalvendas[i] < 0) {
        printf("O valor total da venda não pode ser negativo.\n");
      }
    } while (valortotalvendas[i] < 0);
    do {
      printf("Quantidade de camisas: ");
      scanf("%d", &quantidadedecamisavendidas[i]);
      if (quantidadedecamisavendidas[i] < 0) {
        printf("A quantidade de camisas não pode ser negativa.\n");
      }
    } while (quantidadedecamisavendidas[i] < 0);
    do {
      printf("Código de venda: ");
      scanf("%d", &codigodevenda[i]);
      parada = 0;
      for (int j = 0; j < i; j++) {
        if (codigodevenda[i] == codigodevenda[j]) {
          printf("O código de venda não pode ser o mesmo que uma venda "
                 "anterior. Por favor, tente novamente.\n");
          parada++;
        }
      }
      if (codigodevenda[i] < 0) {
        printf("O código de venda não pode ser negativo.\n");
      }
      if (codigodevenda[i] > 5) {
        printf("O código de venda não pode ser maior que 5.\n");
      }
    } while (parada == 1 || codigodevenda[i] < 0 || codigodevenda[i] > 5);

    do {
      printf("Tamanho da camisa P, M ou G: ");
      scanf(" %c", &tamanhocamisa[i]);
      if (tamanhocamisa[i] != 'm' && tamanhocamisa[i] != 'M' &&
          tamanhocamisa[i] != 'g' && tamanhocamisa[i] != 'G' &&
          tamanhocamisa[i] != 'p' && tamanhocamisa[i] != 'P') {
        printf("Tamanho da camisa inválido. Tente novamente.\n");
      }
    } while (tamanhocamisa[i] != 'm' && tamanhocamisa[i] != 'M' &&
             tamanhocamisa[i] != 'g' && tamanhocamisa[i] != 'G' &&
             tamanhocamisa[i] != 'p' && tamanhocamisa[i] != 'P');

    do {
      printf("Tipo de venda: ");
      scanf("%d", &tipodevenda[i]);
      if (tipodevenda[i] == 1) {
        contadortipovenda[i]++;
      }

      if (tipodevenda[i] < 0) {
        printf("O tipo de venda não pode ser negativo.\n");
      }
      if (tipodevenda[i] > 5) {
        printf("O tipo de venda não pode ser maior que 5.\n");
      }
    } while (tipodevenda[i] < 0 || tipodevenda[i] > 5);
  }

  do {
    printf("-------------------------------------------Menu--------------------"
           "------------------------\n");
    printf("Desejo ver informações das vendas baseado no código [1].\nDesejo "
           "ver informações de todos os pedidos cadastrados [2].\nDesejo ter "
           "informações sobre a venda[3].\nDesejo "
           "sair do menu [4].\nCodigo: ");
    scanf("%d", &menu);
    printf("\n-----------------------------------------------------------------"
           "----------------------\n");
    if (menu == 1) {
      printf("Codigo de venda: ");
      scanf("%d", &menucodigo);
      int codigoEncontrado = 0;
      char voltamenu;
      for (int j = 0; j < 5; j++) {
        if (menucodigo == codigodevenda[j]) {
          printf("-------------------------------------------------------------"
                 "--------------------------\n");
          printf("Venda %d\n", j + 1);
          printf("Valor total: %.2f\n", valortotalvendas[j]);
          printf("Quantidade de camisas: %d\n", quantidadedecamisavendidas[j]);
          printf("Código de venda: %d\n", codigodevenda[j]);
          printf("Tamanho da camisa: %c\n", tamanhocamisa[j]);
          printf("Tipo de venda: %d\n", tipodevenda[j]);
          printf("-------------------------------------------------------------"
                 "--------------------------\n");
          codigoEncontrado = 1;
          printf("Deseja voltar para o menu [S][N]: ");
          scanf(" %c", &voltamenu);
          if (voltamenu == 'S' || voltamenu == 's') {
            printf("Voltando ao menu...\n");
          } else {
            menu = 4;
          }
          break;
        }
      }
      if (!codigoEncontrado) {
        printf("O código de venda não existe, tente novamente.\n");
      }
    }
    if (menu == 2) {
      for (int i = 0; i < 5; i++) {
        printf("---------------------------------------------------------------"
               "------------------------\n");
        printf("Venda %d\n", i + 1);
        printf("Valor total: %.2f\n", valortotalvendas[i]);
        printf("Quantidade de camisas: %d\n", quantidadedecamisavendidas[i]);
        printf("Código de venda: %d\n", codigodevenda[i]);
        printf("Tamanho da camisa: %c\n", tamanhocamisa[i]);
        printf("Tipo de venda: %d\n", tipodevenda[i]);
        printf("---------------------------------------------------------------"
               "------------------------\n");
      }
    }
    if (menu == 3) {
      printf("Digite um valor(Será exibido a quantidade de vendas abaixo deste "
             "valor): ");
      scanf("%f", &valorperg);
      for (int i = 0; i < 5; i++) {
        if (valorperg > valortotalvendas[i]) {
          contadorvalorabaixo++;
        }
        if (valortotalvendas[i] > 100) {
          contadoracimacem++;
        }
        if (tamanhocamisa[i] == 'g' || tamanhocamisa[i] == 'G') {
          contadorg = contadorg + quantidadedecamisavendidas[i];
        }
        if (tamanhocamisa[i] == 'p' || tamanhocamisa[i] == 'P') {
          valortotalp = valortotalvendas[i] + valortotalp;
        }
        valortotal = valortotal + valortotalvendas[i];
        qtdtotalcamisas = qtdtotalcamisas + quantidadedecamisavendidas[i];
        contadortipovenda[tipodevenda[i] - 1]++;

        if (tipodevenda[i] == 1 || tipodevenda[i] == 3 || tipodevenda[i] == 5) {
          printf("-------------------------------------------------------------"
                 "--------------------------\n");
          printf("O valor total da venda quando o tipo de venda é impar, a "
                 "venda de número %d é de %.2f.\n",
                 i + 1, valortotalvendas[i]);
        }
      }
      for (int i = 0; i < 5; i++) {
        if (contadortipovenda[i] > maiorcontagem) {
          maiorcontagem = contadortipovenda[i];
          tipodevendamaisvendido = i + 1;
        }
      }

      printf("-----------------------------------------------------------------"
             "----------------------\n");
      printf("A quantidade de vendas abaixo deste valor é %d.\n",
             contadorvalorabaixo);
      printf("-----------------------------------------------------------------"
             "----------------------\n");
      printf("A quantidade de vendas acima de 100 reais é %d.\n",
             contadoracimacem);
      printf("-----------------------------------------------------------------"
             "----------------------\n");
      printf("A quantidade vendida de camisas do tamanho G é %d.\n", contadorg);
      printf("-----------------------------------------------------------------"
             "----------------------\n");
      printf("O valor total vendido de camisa P é %.2f\n", valortotalp);
      printf("-----------------------------------------------------------------"
             "----------------------\n");
      printf("A quantidade de camisas vendidas é %d\n", qtdtotalcamisas);
      mediavalor = valortotal / 5;
      printf("-----------------------------------------------------------------"
             "----------------------\n");
      printf("O valor medio de uma venda é %.2f\n", mediavalor);
      printf("-----------------------------------------------------------------"
             "----------------------\n");
      printf("O tipo de venda que foi mais vendido é o tipo %d.\n",
             tipodevendamaisvendido);
      printf("-----------------------------------------------------------------"
             "----------------------\n");
      printf("Deseja voltar para o menu [S][N]: ");
      scanf(" %c", &voltamenu2);
      printf("-----------------------------------------------------------------"
             "----------------------\n");
      if (voltamenu2 == 'S' || voltamenu2 == 's') {
        printf("Voltando ao menu...\n");
      } else {
        menu = 4;
      }
    }
    if (menu == 4) {
      printf("Saindo do menu.");
      break;
    }
  } while (menu != 4);

  return 0;
}