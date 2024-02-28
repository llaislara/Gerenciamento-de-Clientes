#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CLIENTES 200
#define MAX_STRING_LENGTH 200

struct cadastro {
    char nome[MAX_STRING_LENGTH];
    char CPF[MAX_STRING_LENGTH];
    char telefone[MAX_STRING_LENGTH];
    char endereco[MAX_STRING_LENGTH];
    int cod;
    bool ocupado;
};

struct cadastro Cliente[MAX_CLIENTES];

int verifica_pos(void) {
    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (!Cliente[i].ocupado) {
            return i;
        }
    }
    return -1;
}

int verifica_cod(int cod) {
    if (cod < 1 || cod > 200) {
        return 0;
    }
    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (Cliente[i].cod == cod && Cliente[i].ocupado) {
            return 0;
        }
    }
    return 1;
}

void cadastroCliente() {
    int posicao = verifica_pos();
    if (posicao != -1) {
        printf("Entre com um código de 1 a 200 para seu cadastro: \n");
        int codaux;
        scanf("%d", &codaux);
        getchar(); // Limpa o buffer de entrada
        if (verifica_cod(codaux) == 1) {
            Cliente[posicao].cod = codaux;
            printf("\n");
            printf("Digite seu nome: ");
            fgets(Cliente[posicao].nome, MAX_STRING_LENGTH, stdin);
            Cliente[posicao].nome[strcspn(Cliente[posicao].nome, "\n")] = 0; // Remove newline
            printf("Digite seu CPF: ");
            fgets(Cliente[posicao].CPF, MAX_STRING_LENGTH, stdin);
            Cliente[posicao].CPF[strcspn(Cliente[posicao].CPF, "\n")] = 0; // Remove newline
            printf("Digite seu Endereço: ");
            fgets(Cliente[posicao].endereco, MAX_STRING_LENGTH, stdin);
            Cliente[posicao].endereco[strcspn(Cliente[posicao].endereco, "\n")] = 0; // Remove newline
            printf("Digite seu Telefone: ");
            fgets(Cliente[posicao].telefone, MAX_STRING_LENGTH, stdin);
            Cliente[posicao].telefone[strcspn(Cliente[posicao].telefone, "\n")] = 0; // Remove newline
            Cliente[posicao].ocupado = true;
            printf("\nCadastro realizado com sucesso!\n");
        } else {
            printf("\nCódigo já existente ou inválido. Tente novamente.\n");
        }
    } else {
        printf("\nNão é possível realizar mais cadastros!\n");
    }
}

void list() {
    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (Cliente[i].ocupado) {
            printf("Código: %d\n", Cliente[i].cod);
            printf("Nome: %s\n", Cliente[i].nome);
            printf("CPF: %s\n", Cliente[i].CPF);
            printf("Endereço: %s\n", Cliente[i].endereco);
            printf("Telefone: %s\n", Cliente[i].telefone);
            printf("\n");
        }
    }
}

void consultaCod(void) {
    int cod;
    printf("\nEntre com o código do cliente: ");
    scanf("%d", &cod);
    getchar(); // Limpa o buffer de entrada
    bool encontrado = false;
    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (Cliente[i].cod == cod && Cliente[i].ocupado) {
            printf("Código: %d\n", Cliente[i].cod);
            printf("Nome: %s\n", Cliente[i].nome);
            printf("CPF: %s\n", Cliente[i].CPF);
            printf("Endereço: %s\n", Cliente[i].endereco);
            printf("Telefone: %s\n", Cliente[i].telefone);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Cliente não encontrado!\n");
    }
}

void excluirCliente(void) {
    int cod;
    printf("\nEntre com o código do cliente que deseja excluir: ");
    scanf("%d", &cod);
    getchar(); // Limpa o buffer de entrada
    bool encontrado = false;
    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (Cliente[i].cod == cod && Cliente[i].ocupado) {
            Cliente[i].ocupado = false;
            memset(&Cliente[i], 0, sizeof(struct cadastro)); // Limpa os dados do cliente
            printf("Cliente com código %d excluído com sucesso!\n", cod);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Cliente não encontrado!\n");
    }
}

int main(void) {
    int Opcao;
    do {
        printf("\n");
        printf("1 - Cadastrar Novo Cliente\n");
        printf("2 - Listar Clientes\n");
        printf("3 - Consultar Cliente por Código\n");
        printf("4 - Excluir Cliente\n");
        printf("5 - Sair\n");
        printf("Selecione uma opção por favor: ");
        scanf("%d", &Opcao);
        getchar(); // Limpa o buffer de entrada

        switch (Opcao) {
            case 1:
                cadastroCliente();
                break;

            case 2:
                list();
                break;

            case 3:
                consultaCod();
                break;

            case 4:
                excluirCliente();
                break;

            case 5:
                printf("Encerrando o programa. Até mais!\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (Opcao != 5);
    return 0;
}
