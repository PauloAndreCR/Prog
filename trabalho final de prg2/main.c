#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
// Enzo Ribas|19|M|120|40|5|12:34
// NOME| IDADE | SEXO | VALOR-VENDA | QTD | HORARIO DE COMPRA

struct Cliente {
    char nome[100];
    char sexo;
    int idade;
};

typedef struct Cliente cliente;

struct Venda {
    struct Cliente cliente;
    float valorVenda;
    int qtd;
    int hora;
    int minuto;
};

typedef struct Venda venda;

void cadastrar_vendas();
void informacao_venda_especifica();
void informacao_vendas();

int main(void) {
    int opcao = -1;

    do{
        printf("\n\033[1;36m----------==== MENU ====----------\033[0;m\n");
        printf("\033[30m1- \033[32mCadastrar nova(s) venda(s)\033[m\n");
        printf("\033[30m2- \033[32mVer informacoes de uma venda especifica\033[m\n");
        printf("\033[30m3- \033[32mVer informacoes de todas as vendas\033[m\n");
        printf("\033[30m4- \033[32mEncerrar programa\033[m\n");
        printf("\033[1;36m-> \033[0m");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\n\033[1;31mOpcao invalida, tente novamente!\033[0;m\n\n"); 
            while(getchar() != '\n');
            continue;
        }
        getchar();
        printf("\033[1;36m----------------------------------\033[0;m\n");
        switch(opcao) {
            case 1: 
                cadastrar_vendas();
                break;
            
            case 2: 
                informacao_venda_especifica();
                break;
            
            case 3: 
                informacao_vendas();
                break;
            
            case 4: 
                printf("Saindo do programa...\n");
                break;

            default:
                printf("\033[1;31mOpcao invalida, tente novamente!\033[0;m\n");
        }
    } while (opcao != 4);

    return 0;
}

//! cadastro vendas
void cadastrar_vendas() {
    int qtdVendas = 0;
    char continuarCadastrando, voltarAoMenu;
    FILE *file = fopen("registro.txt", "a");

    if (file == NULL) {
        printf("\033[1;31mErro ao abrir o arquivo.\033[0m\n");
        return;
    }
    
    printf("Quantas vendas deseja cadastrar? ");
    scanf("%d", &qtdVendas);
    getchar();

    cliente *venda = (cliente*) malloc (qtdVendas * sizeof(cliente));

    if (venda == NULL) {
        printf("\033[1;31mERRO! Memoria insuficiente!\033[m\n");
        return;
    }

    // Enzo Ribas|19|M|120|40|5|12:34
    // NOME| IDADE | SEXO | VALOR-VENDA | QTD | HORARIO DE COMPRA

    char nome[50], sexo;
    int idade = 0, qtdItensVendas = 0, hora, minuto;
    float valorVenda = 0;

    for (int i = 0; i < qtdVendas; i++) {
        printf("Nome do cliente: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0'; //? Para tirar o "\n" do final da string

        //! Cadastro idade do cliente
        do {
            printf("Idade do cliente: ");
            if (scanf("%d", &idade) != 1 || idade < 0) {
                printf("\033[1;31mERRO! Digite um valor valido!\033[0m\n");
                while(getchar() != '\n');
                idade = -1;
            }
        } while (idade < 0);

        
        //! Cadastro sexo do cliente
        do {
            printf("Sexo do cliente: ");
            scanf(" %c", &sexo);
            if (sexo != 'm' && sexo != 'M' && sexo != 'f' && sexo != 'F' && sexo != 'n' && sexo != 'N') {
                printf("\033[1;31mDigite um valor valido.\033[0;m\n");
                while(getchar() != '\n'); //? Pegar todas os caracteres 
            }
        } while (sexo != 'm' && sexo != 'M' && sexo != 'f' && sexo != 'F' && sexo != 'n' && sexo != 'N');
        
        //! Cadastro valor da venda
        do {        
            printf("Valor da venda: ");
            scanf("%f", &valorVenda);
            if(valorVenda < 0) {
                printf("\033[1;31mERRO! Valor invalido!\033[0m\n");
                while(getchar() != '\n');
            }
        } while(valorVenda < 0);
        getchar();
        
        //! Cadastro quantidade dee itens
        do{
            printf("Quantidade de itens: ");
            if(scanf("%d", &qtdItensVendas) != 1){
                printf("\033[1;31mERRO! Digite um valor valido!\033[m");
                while(getchar() != '\n');
            }
            if(qtdItensVendas < 0){
                printf("\033[1;31mERRO! Valor invalido!\033[0m\n");
                while(getchar() != '\n');
            }
        } while(qtdItensVendas < 0);
        getchar();

        //! Cadastro horário da compra
        do {
            printf("Horario da compra (hora:minuto): ");
            if (scanf("%d:%d", &hora, &minuto) != 2 || hora < 0 || hora >= 24 || minuto < 0 || minuto >= 60) {
                printf("\033[1;31mERRO! Digite um valor valido!\033[0m\n");
                while(getchar() != '\n');
                hora = -1;
                minuto = -1;
            }
        } while (hora < 0 || hora >= 24 || minuto < 0 || minuto >= 60);
        getchar();

        printf("\033[33mVenda cadastrada com sucesso!\033[m\n");
        fprintf(file, "%s|%d|%c|%.2f|%d|%02d:%02d\n", nome, idade, sexo, valorVenda, qtdItensVendas, hora, minuto);
    }
    do{
        printf("Vendas finalizadas. Deseja continuar cadastrando(s/n)?");
        scanf(" %c", &continuarCadastrando);
    } while(continuarCadastrando != 's' || continuarCadastrando != 'S' || continuarCadastrando != 'n' || continuarCadastrando != 'N');

    if(continuarCadastrando == 's' || continuarCadastrando == 'S'){
        cadastrar_vendas();
    } else{
        do{
            printf("Deseja voltar ao menu(s/n)?");
            scanf(" %c", &voltarAoMenu);
        } while(voltarAoMenu != 's' || voltarAoMenu != 'S' || voltarAoMenu != 'n' || voltarAoMenu != 'N');

        if(voltarAoMenu == 's' || voltarAoMenu == 'S'){
            main();
        } else{
            fclose(file);
        }
    }
    free(venda);
}

void informacao_venda_especifica() {
    char opcao;
    do {
        char nome[100], linha[200];
        int encontrou = 0;
        float totalVendas = 0;
        float mediaValorClienteEspecifico = 0;
        int qtdItensClienteEspecifico = 0;
        int qtdVendasCliente = 0;

        FILE *file = fopen("registro.txt", "r");
        if (file == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        printf("Nome do cliente: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        printf("Vendas para o cliente: %s:\n\n", nome);
        while (fgets(linha, sizeof(linha), file)) {
            if (strstr(linha, nome)) {
                encontrou = 1;
                struct Venda venda;
                sscanf(linha, "%[^|]|%d|%c|%f|%d|%d:%d",
                    venda.cliente.nome, &venda.cliente.idade, &venda.cliente.sexo,
                    &venda.valorVenda, &venda.qtd, &venda.hora, &venda.minuto);
        
                printf("\033[35m---------------------------------\033[m\n");
                printf("\033[4;32mCliente: \033[30m%s\n", venda.cliente.nome);
                printf("\033[4;32mIdade: \033[30m%d\n", venda.cliente.idade);
                printf("\033[4;32mSexo: \033[30m%c\n", venda.cliente.sexo);
                printf("\033[4;32mValor da Venda: \033[30mR$ %.2f\n", venda.valorVenda);
                printf("\033[4;32mQuantidade de Itens: \033[30m%d\n", venda.qtd);
                printf("\033[4;32mHorario da Compra: \033[30m%02d:%02d\033[m\n", venda.hora, venda.minuto);
                
                totalVendas += venda.valorVenda;
                qtdItensClienteEspecifico += venda.qtd;
                qtdVendasCliente++;
            }
        }

        if(encontrou){
            mediaValorClienteEspecifico = totalVendas / qtdItensClienteEspecifico;
            printf("\nMedia do valor das vendas para o cliente %s: R$ %.2f\n",nome, mediaValorClienteEspecifico);
        } else{
            printf("\033[1;31mNenhuma venda encontrada para o cliente %s.\033[0m\n", nome);
        }

        fclose(file);
        

        do{
            printf("\nDeseja pesquisar outra venda(s/n)?");
            scanf(" %c", &opcao);
            getchar();
        }while (opcao != 's' && opcao != 'n');
    } while (opcao == 's');
    return;

    
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void informacao_vendas() {
    float valorVenda = 0, valorEspecifico = 0, maiorValorVenda = 0;
    float valorTotalH = 0, valorTotal = 0, mediaValoresCompras = 0;
    int maiorIdade = 0, qtdAcimaValor = 0, qtdVendaExata = 0, qtdVendaAposMeioDia = 0;
    int qtdClienteF = 0, qtdTotaldeItens = 0, qtdItens = 0, idade = 0, hora = 0, minuto = 0;
    char menorNome[50] = "", nomeMaisVelho[50] = "", resposta[3], nome[50], linha[200], sexo;
    
    FILE* file = fopen("registro.txt", "r");
    if (file == NULL) {
        printf("\033[1;31mErro ao abrir o arquivo.\033[0m\n");
        return;
    }

    printf("Digite um valor para ver as vendas acima: ");
    scanf("%f", &valorEspecifico);

    // Loop para ler cada linha do arquivo
    while (fscanf(file, "%49[^|]|%d|%c|%f|%d|%d:%d\n", nome, &idade, &sexo, &valorVenda, &qtdItens, &hora, &minuto) == 7) {
        valorTotal += valorVenda;
        qtdTotaldeItens += qtdItens;

        if (valorVenda > maiorValorVenda) {
            maiorValorVenda = valorVenda;
        }

        if (valorVenda > valorEspecifico) {
            qtdAcimaValor++;
        }

        if (strlen(nome) < strlen(menorNome) || strlen(menorNome) == 0) {
            strcpy(menorNome, nome);
        }

        if (idade > maiorIdade) {
            maiorIdade = idade;
            strcpy(nomeMaisVelho, nome);
        }

        if (hora >= 12) {
            qtdVendaAposMeioDia++;
        }

        if (sexo == 'F' || sexo == 'f') {
            qtdClienteF++;
        }

        if (sexo == 'M' || sexo == 'm') {
            valorTotalH += valorVenda;
        }

        if (qtdItens == 2) {
            qtdVendaExata++;
        }
    }

    mediaValoresCompras = valorTotal / qtdTotaldeItens;

    printf("\33[4;32m\nQuantidade de vendas acima do valor (\033[4;33mR$ %.2f\33[4;32m):\033[0;30m %d\n", valorEspecifico, qtdAcimaValor);
    printf("\33[4;32mQuantidade de venda com exatamente\033[4;33m 2\033[4;32m itens:\033[0;30m %d\n", qtdVendaExata);
    printf("\33[4;32mQuantidade de vendas apos 12:00:\033[0;30m %d\n", qtdVendaAposMeioDia);
    printf("\33[4;32mQuantidade de clientes mulheres:\033[0;30m %d\n", qtdClienteF);
    printf("\33[4;32mValor total comprado por homens:\033[0;30m R$ %.2f\n", valorTotalH);
    printf("\33[4;32mQuantidade total de itens vendidos:\033[0;30m %d\n", qtdTotaldeItens);
    printf("\33[4;32mValor total das vendas:\033[0;30m R$ %.2f\n", valorTotal);
    printf("\33[4;32mMedia dos valores das compras:\033[0;30m R$ %.2f\n", mediaValoresCompras);
    printf("\33[4;32mMaior compra realizada:\033[0;30m R$ %.2f\n", maiorValorVenda);

    rewind(file);

    printf("\n\033[1;36mCompras do cliente com menor nome:\033[0m\n");
    while (fgets(linha, sizeof(linha), file)) {
        if (strstr(linha, menorNome) || strstr(linha, nomeMaisVelho)) {
            sscanf(linha, "%49[^|]|%d|%c|%f|%d|%d:%d", nome, &idade, &sexo, &valorVenda, &qtdItens, &hora, &minuto);

            if (strcmp(nome, menorNome) == 0) {
                printf("\033[4;32mCliente:\033[0;30m %s\n", nome);
                printf("\033[4;32mIdade:\033[0;30m %d\n", idade);
                printf("\033[4;32mSexo:\033[0;30m %c\n", sexo);
                printf("\033[4;32mValor da Venda:\033[0;30m R$ %.2f\n", valorVenda);
                printf("\033[4;32mQuantidade de Itens:\033[0;30m %d \n", qtdItens);
                printf("\033[4;32mHorario da Compra:\033[0;30m %02d:%02d\n", hora, minuto);
                printf("\033[0;36m---------------------------------\033[m\n");
            }
        }
    }
    
    rewind(file);
    printf("\n\033[1;36mCompras do cliente mais velho:\033[0m\n");
    while (fgets(linha, sizeof(linha), file)) {
        if (strstr(linha, menorNome) || strstr(linha, nomeMaisVelho)) {
            sscanf(linha, "%49[^|]|%d|%c|%f|%d|%d:%d", nome, &idade, &sexo, &valorVenda, &qtdItens, &hora, &minuto);
            if (strcmp(nome, nomeMaisVelho) == 0) {
                printf("\033[4;32mCliente:\033[0;30m %s\n", nome);
                printf("\033[4;32mIdade:\033[0;30m %d\n", idade);
                printf("\033[4;32mSexo:\033[0;30m %c\n", sexo);
                printf("\033[4;32mValor da Venda:\033[0;30m R$ %.2f\n", valorVenda);
                printf("\033[4;32mQuantidade de Itens:\033[0;30m %d\n", qtdItens);
                printf("\033[4;32mHorario da Compra:\033[0;30m %02d:%02d\n", hora, minuto);
                printf("\033[0;36---------------------------------\033[m\n");
            }
        }
    }

    printf("\033[32mDeseja retornar ao menu principal?\033[30m sim \033[32mou\033[30m nao \033[32m?\033[m");
    scanf("%s", resposta);
    if (strcmp(resposta, "sim") == 0) {
        fclose(file);
        return;
    }
    
    fclose(file);
    exit(0);
}