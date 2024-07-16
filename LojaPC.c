#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PCS 100

typedef struct {
    char nome[50];
    char cpu[50];
    char placaMae[50];
    char placaDeVideo[50];
    char fonte[50];
    char memoriaRam[50];
    char armazenamento[50];
    char gabinete[50];
} PC;

typedef struct {
    char nome[50];
    char cpf[12];
    char endereco[100];
    char descricao[100];
} ASSISTENCIA;

void cadastrarAssistencia(ASSISTENCIA assist[], int *quantidade) {
    if (*quantidade < MAX_PCS) {
        printf("\033[H\033[J");
        printf("Informe o NOME do cliente:\n");
        scanf("%49[^\n]", assist[*quantidade].nome);
        getchar();
        printf("\nInforme o CPF do Cliente:\n");
        scanf("%11[^\n]", assist[*quantidade].cpf);
        getchar();
        printf("\nInforme o ENDERECO(bairro, rua e numero) do cliente:\n");
        scanf("%99[^\n]", assist[*quantidade].endereco);
        getchar();
        printf("\nInforme a DESCRICAO do cliente sobre o defeito do PC:\n");
        scanf("%99[^\n]", assist[*quantidade].descricao);
        getchar();
        printf("PC cadastrado com sucesso na lista para Assistencia!\n");
        (*quantidade)++;
    } else {
        printf("Limite maximo de PC's para Assistencia!\n");
    }
}

void exibirAssistencia(ASSISTENCIA assist[], int quantidade) {
    printf("\033[H\033[J");
    printf("===== Clientes Cadastrados =====\n\n");

    for (int i = 0; i < quantidade; i++) {
        printf("--- Cliente %d ---\n\n", i + 1);
        printf("|| NOME - %s\n", assist[i].nome);
        printf("|| CPF - %s\n", assist[i].cpf);
        printf("|| ENDERECO - %s\n", assist[i].endereco);
        printf("|| DESCRICAO do Cliente - %s\n\n", assist[i].descricao);
    }
    printf("Pressione 'Enter' para voltar...\n");
    while (getchar() != '\n') {};
}

void pesquisarNomeAssistencia(ASSISTENCIA assist[], int quantidade) {
    char nome[50];
    printf("\033[H\033[J");
    printf("Digite o Nome do CLIENTE: \n");
    scanf(" %49[^\n]", nome);
    getchar();

    int encontrado = 0;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(assist[i].nome, nome) == 0) {
            printf("\033[H\033[J");
            printf("===== Registro encontrado =====\n");
            printf("|| CLIENTE - %d\n", i + 1);
            printf("|| NOME - %s\n", assist[i].nome);
            printf("|| CPF - %s\n", assist[i].cpf);
            printf("|| Endereco - %s\n", assist[i].endereco);
            printf("|| Descricao - %s\n", assist[i].descricao);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\nRegistro nao encontrado\n");
    }
    printf("Pressione 'Enter' para voltar...\n");
    while (getchar() != '\n') {};
}

void cadastrarPc(PC listaPc[], int *quantidade) {
    if (*quantidade < MAX_PCS) {
        printf("\033[H\033[J");
        printf("Cadastro do PC %d\n", *quantidade + 1);
        printf("\nInforme o nome do PC:\n");
        scanf(" %49[^\n]", listaPc[*quantidade].nome);
        getchar();
        printf("\nInforme Nome e Modelo do CPU:\n");
        scanf(" %49[^\n]", listaPc[*quantidade].cpu);
        getchar();
        printf("\nInforme Nome e Modelo da Placa Mae:\n");
        scanf(" %49[^\n]", listaPc[*quantidade].placaMae);
        getchar();
        printf("\nInforme Nome e Modelo da Placa de Video:\n");
        scanf(" %49[^\n]", listaPc[*quantidade].placaDeVideo);
        getchar();
        printf("\nInforme Nome, Potencia e Certificacao da Fonte:\n");
        scanf(" %49[^\n]", listaPc[*quantidade].fonte);
        getchar();
        printf("\nInforme Nome, Modelo, Capacidade e Velocidade da RAM:\n");
        scanf(" %49[^\n]", listaPc[*quantidade].memoriaRam);
        getchar();
        printf("\nInforme Nome, Capacidade e Velocidade do SSD/HD:\n");
        scanf(" %49[^\n]", listaPc[*quantidade].armazenamento);
        getchar();
        printf("\nInforme Nome e Modelo do Gabinete:\n");
        scanf(" %49[^\n]", listaPc[*quantidade].gabinete);
        getchar();
        printf("\033[H\033[J");
        printf("PC cadastrado com sucesso!\n");
        (*quantidade)++;
    } else {
        printf("Limite máximo de PCs cadastrados atingido.\n");
    }
}

void pesquisarPorNome(PC listaPc[], int quantidade) {
    char nome[50];
    printf("\033[H\033[J");
    printf("Digite o Nome do PC: \n");
    scanf(" %49[^\n]", nome);
    getchar();

    int encontrado = 0;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(listaPc[i].nome, nome) == 0) {
            printf("\033[H\033[J");
            printf("===== Registro encontrado =====\n\n");
            printf("|| NOME - %s\n", listaPc[i].nome);
            printf("|| PC - %d\n", i + 1);
            printf("|| CPU - %s\n", listaPc[i].cpu);
            printf("|| Placa Mae - %s\n", listaPc[i].placaMae);
            printf("|| Placa de Video - %s\n", listaPc[i].placaDeVideo);
            printf("|| Fonte - %s\n", listaPc[i].fonte);
            printf("|| RAM - %s\n", listaPc[i].memoriaRam);
            printf("|| Armazenamento - %s\n", listaPc[i].armazenamento);
            printf("|| Gabinete - %s\n", listaPc[i].gabinete);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Registro não encontrado\n");
    }
    printf("Pressione 'Enter' para voltar...\n");
    while (getchar() != '\n') {}
}

void deletarRegistro(PC listaPc[], int *quantidade) {
    char nome[50];
    int resposta;
    printf("Digite o Nome do PC: \n");
    scanf(" %49[^\n]", nome);
    getchar();

    int encontrado = 0;
    for (int i = 0; i < *quantidade; i++) {
        if (strcmp(listaPc[i].nome, nome) == 0) {
            printf("\033[H\033[J");
            printf("*** Registro encontrado ***\n\n");
            printf(" --- PC  %d ---\n", i + 1);
            printf("|| NOME - %s\n", listaPc[i].nome);
            printf("|| CPU - %s\n", listaPc[i].cpu);
            printf("|| Placa Mae - %s\n", listaPc[i].placaMae);
            printf("|| Placa de Video - %s\n", listaPc[i].placaDeVideo);
            printf("|| Fonte - %s\n", listaPc[i].fonte);
            printf("|| RAM - %s\n", listaPc[i].memoriaRam);
            printf("|| Armazenamento - %s\n", listaPc[i].armazenamento);
            printf("|| Gabinete - %s\n\n", listaPc[i].gabinete);
            encontrado = 1;
            printf("=== TEM CERTEZA QUE QUER DELETAR O REGISTRO? ===\n");
            printf("|| 1 - NAO\n");
            printf("|| 2 - SIM\n");
            scanf("%d", &resposta);
            if (resposta == 2) {
                for (int j = i; j < *quantidade - 1; j++) {
                    listaPc[j] = listaPc[j + 1];
                }
                (*quantidade)--;
                printf("*** Registro Deletado ***\n");
            } else {
                printf("Operacao CANCELADA\n");
            }
            break;
        }
    }
    if (!encontrado) {
        printf("PC com nome '%s' não encontrado.\n", nome);
    }
}

void exibirPcsCadastrados(PC listaPc[], int quantidade) {
    printf("\033[H\033[J");
    printf("===== PCs Cadastrados =====\n\n");

    for (int i = 0; i < quantidade; i++) {
        printf("\n--- PC %d ---\n\n", i + 1);
        printf("|| NOME - %s\n", listaPc[i].nome);
        printf("|| CPU - %s\n", listaPc[i].cpu);
        printf("|| Placa Mae - %s\n", listaPc[i].placaMae);
        printf("|| Placa de Video - %s\n", listaPc[i].placaDeVideo);
        printf("|| Fonte - %s\n", listaPc[i].fonte);
        printf("|| RAM - %s\n", listaPc[i].memoriaRam);
        printf("|| Armazenamento - %s\n", listaPc[i].armazenamento);
        printf("|| Gabinete - %s\n", listaPc[i].gabinete);
    }
    printf("\nPressione 'Enter' para voltar...\n");
    while (getchar() != '\n') {}
}

void menu() {
    printf("\033[H\033[J");
    printf("  ____                  __      ___           _       \n");
    printf(" |  _ \\                 \\ \\    / (_)         | |      \n");
    printf(" | |_) | ___ _ __ ___    \\ \\  / / _ _ __   __| | ___  \n");
    printf(" |  _ < / _ \\ '_ ` _ \\    \\ \\/ / | | '_ \\ / _` |/ _ \\ \n");
    printf(" | |_) |  __/ | | | | |    \\  /  | | | | | (_| | (_) |\n");
    printf(" |____/ \\___|_| |_| |_|     \\/   |_|_| |_|\\__,_|\\___/ \n\n");
    printf("| 1 | - Cadastrar PC\n");
    printf("| 2 | - Listar PCs Cadastrados\n");
    printf("| 3 | - Pesquisar PC por Nome\n");
    printf("| 4 | - Deletar Registro\n");
    printf("| 5 | - Assistencia Tecnica\n");
    printf("| 6 | - Sair\n\n");
    printf("*** Escolha uma das opcoes acima ***\n");
}

void menuAssist() {
    printf("\033[H\033[J");
    printf("                   _     _                  _       \n");
    printf("     /\\           (_)   | |                (_)      \n");
    printf("    /  \\   ___ ___ _ ___| |_ ___ _ __   ___ _  __ _ \n");
    printf("   / /\\ \\ / __/ __| / __| __/ _ \\ '_ \\ / __| |/ _` |\n");
    printf("  / ____ \\ __ \\__ \\ \\__ \\ ||  __/ | | | (__| | (_| |\n");
    printf(" /_/    \\_\\___/___/_|___/\\__\\___|_| |_|\\___|_|\\__,_|\n\n");
    printf("| 1 | - Cadastrar PC para Assistencia Tecnica\n");
    printf("| 2 | - Exibir Lista Assistencia Tecnica\n");
    printf("| 3 | - Pesquisar por Cliente Lista Assistencia\n");
    printf("| 4 | - Voltar ao Menu Principal\n");
}

int main() {
    int opcao;
    int opcao2;
    int quantidade = 0;
    PC listaPc[MAX_PCS];
    ASSISTENCIA assist[MAX_PCS];

    while (1) {
        menu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrarPc(listaPc, &quantidade);
                break;
            case 2:
                exibirPcsCadastrados(listaPc, quantidade);
                break;
            case 3:
                pesquisarPorNome(listaPc, quantidade);
                break;
            case 4:
                deletarRegistro(listaPc, &quantidade);
                break;
            case 5:
                opcao2 = 0; // Inicializa a opcao2 para entrar no loop do menu de assistência
                while (opcao2 != 4) {
                    printf("\033[H\033[J");
                    menuAssist();
                    scanf("%d", &opcao2);
                    getchar();
                    switch (opcao2) {
                        case 1:
                            cadastrarAssistencia(assist, &quantidade);
                            break;
                        case 2:
                            exibirAssistencia(assist, quantidade);
                            break;
                        case 3:
                            pesquisarNomeAssistencia(assist, quantidade);
                            break;
                        case 4:
                            printf("\033[H\033[J");
                            break;
                        default:
                            printf("Escolha uma opcao valida\n");
                            break;
                    }
                }
                break;
            case 6:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Escolha uma opcao valida!\n");
                break;
        }
    }
    return 0;
}
