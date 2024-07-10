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



void cadastrarPc(PC listaPc[], int *quantidade) {
    if (*quantidade < MAX_PCS) { 
        printf("Cadastro do PC %d\n", *quantidade + 1);
        printf("Informe o nome do PC:\n");
        scanf(" %49[^\n]", listaPc[*quantidade].nome);
        getchar(); 
        printf("\nInforme Nome e Modelo do CPU:\n");
        scanf(" %49[^\n]", listaPc[*quantidade].cpu);
        getchar();
        printf("\nInforme Nome e Modelo da Placa Mãe:\n");
        scanf(" %49[^\n]", listaPc[*quantidade].placaMae);
        getchar();
        printf("\nInforme Nome e Modelo da Placa de Vídeo:\n");
        scanf(" %49[^\n]", listaPc[*quantidade].placaDeVideo);
        getchar();
        printf("\nInforme Nome, Potência e Certificação da Fonte:\n");
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
        printf("\nPC cadastrado com sucesso!\n");
        (*quantidade)++;
    } else {
        printf("Limite máximo de PCs cadastrados atingido.\n");
    }
}   

void pesquisarPorNome(PC listaPc[], int quantidade) {
    char nome[50];
    printf("Digite o Nome do PC: \n");
    scanf("%29[^\n]", nome); 
    getchar(); 
    
    int encontrado = 0;
    for(int i = 0; i < quantidade; i++) {
        if(strcmp(listaPc[i].nome, nome) == 0) {
            printf("\033[H\033[J");
            printf("\n--- Registro encontrado ---\n");
            printf("PC %d:\n\n", i + 1);
            printf("NOME: %s\n", listaPc[i].nome);
            printf("CPU: %s\n", listaPc[i].cpu);
            printf("Placa Mãe: %s\n", listaPc[i].placaMae);
            printf("Placa de Video: %s\n", listaPc[i].placaDeVideo);
            printf("Fonte: %s\n", listaPc[i].fonte);
            printf("RAM: %s\n", listaPc[i].memoriaRam);
            printf("Armazenamento: %s\n", listaPc[i].armazenamento);
            printf("Gabinete: %s\n", listaPc[i].gabinete);
            encontrado = 1;
            break; // Se encontrou, sai do loop
        }
    }
    
    if (!encontrado) {
        printf("Registro não encontrado\n");
    }
}

void exibirPcsCadastrados(PC listaPc[], int quantidade) {
    printf("--- PCs Cadastrados ---\n");
    
    for (int i = 0; i < quantidade; i++) {
        printf("PC %d:\n", i + 1);
        printf("NOME: %s\n", listaPc[i].nome);
        printf("CPU: %s\n", listaPc[i].cpu);
        printf("Placa Mãe: %s\n", listaPc[i].placaMae);
        printf("Placa de Vídeo: %s\n", listaPc[i].placaDeVideo);
        printf("Fonte: %s\n", listaPc[i].fonte);
        printf("RAM: %s\n", listaPc[i].memoriaRam);
        printf("Armazenamento: %s\n", listaPc[i].armazenamento);
        printf("Gabinete: %s\n", listaPc[i].gabinete);
        printf("\n");
    }
}

void menu() {
    printf("\n=== Bem-vindo ao CRUD de PC's ===\n\n");
    printf("1 - Cadastrar PC\n");
    printf("2 - Listar PCs Cadastrados\n");
    printf("3 - Pesquisar PC por Nome:\n");
    printf("4 - Sair\n\n");
    printf("*** Escolha uma das opcoes acima ***\n");
}

int main() {
    int opcao;
    int quantidade = 0;
    PC listaPc[MAX_PCS];

    while (1) {
        menu();
        scanf("%d", &opcao);
        printf("\033[H\033[J");
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
                printf("Saindo...\n");
                return 0;
            default:
                printf("Escolha uma opcao valida!\n");
                break;
        }
    }
    
    return 0;
}
