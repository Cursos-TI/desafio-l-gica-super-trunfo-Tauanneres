#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    int codigo;
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

void cadastrarCarta(Carta *carta) {
    printf("Digite o código da carta: ");
    scanf("%d", &carta->codigo);
    printf("Digite o nome da cidade: ");
    getchar();
    fgets(carta->cidade, 50, stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = '\0';
    printf("Digite o estado: ");
    fgets(carta->estado, 50, stdin);
    carta->estado[strcspn(carta->estado, "\n")] = '\0';
    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);
    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

void compararCartas(Carta carta1, Carta carta2) {
    int escolha1, escolha2;

    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\nEscolha: ");
    scanf("%d", &escolha1);

    printf("\nEscolha o segundo atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\nEscolha: ");
    scanf("%d", &escolha2);

    switch (escolha1) {
        case 1: printf("Comparando pela população...\n"); break;
        case 2: printf("Comparando pela área...\n"); break;
        case 3: printf("Comparando pelo PIB...\n"); break;
        case 4: printf("Comparando pelos pontos turísticos...\n"); break;
        default: printf("Opção inválida.\n"); return;
    }

    switch (escolha2) {
        case 1: printf("Comparando pelo segundo atributo: População\n"); break;
        case 2: printf("Comparando pelo segundo atributo: Área\n"); break;
        case 3: printf("Comparando pelo segundo atributo: PIB\n"); break;
        case 4: printf("Comparando pelo segundo atributo: Pontos turísticos\n"); break;
        default: printf("Opção inválida.\n"); return;
    }

    if (escolha1 == 1 && escolha2 == 2) {
        printf("Resultado: ");
        if (carta1.populacao > carta2.populacao && carta1.area > carta2.area)
            printf("A cidade %s venceu!\n", carta1.cidade);
        else if (carta1.populacao < carta2.populacao && carta1.area < carta2.area)
            printf("A cidade %s venceu!\n", carta2.cidade);
        else
            printf("Empate!\n");
    }

    // Exemplo adicional de comparação entre outros atributos
    if (escolha1 == 3 && escolha2 == 4) {
        printf("Resultado: ");
        if (carta1.pib > carta2.pib && carta1.pontos_turisticos > carta2.pontos_turisticos)
            printf("A cidade %s venceu!\n", carta1.cidade);
        else if (carta1.pib < carta2.pib && carta1.pontos_turisticos < carta2.pontos_turisticos)
            printf("A cidade %s venceu!\n", carta2.cidade);
        else
            printf("Empate!\n");
    }
}

int main() {
    Carta carta1, carta2;

    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&carta1);
    
    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&carta2);

    printf("\nCartas cadastradas:\n");
    printf("Carta 1 - Cidade: %s, Estado: %s, População: %d, Área: %.2f, PIB: %.2f, Pontos turísticos: %d\n", 
        carta1.cidade, carta1.estado, carta1.populacao, carta1.area, carta1.pib, carta1.pontos_turisticos);
    printf("Carta 2 - Cidade: %s, Estado: %s, População: %d, Área: %.2f, PIB: %.2f, Pontos turísticos: %d\n", 
        carta2.cidade, carta2.estado, carta2.populacao, carta2.area, carta2.pib, carta2.pontos_turisticos);

    compararCartas(carta1, carta2);

    return 0;
}