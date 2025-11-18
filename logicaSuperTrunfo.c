#include <stdio.h>

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    char estado1, estado2;
    char codigo1[5], codigo2[5];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos1, pontos2;
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

    printf("=== CADASTRO DA CARTA 1 ===\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o código da carta (ex:A01): \n");
    scanf("%s", codigo1);

    printf("Digite o nome da cidade: \n");
    scanf(" %[^\n]", cidade1);

    printf("Digite a população: \n");
    scanf("%lu", &populacao1);

    printf("Digite a área (km²): \n");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões): \n");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turisticos: \n");
    scanf("%d", &pontos1);

    // Carta 2

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o codigo da carta (ex: A02): \n");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade: \n");
    scanf(" %[^\n]", cidade2);

    printf("Digite a população: \n");
    scanf("%lu", &populacao2);

    printf("Digite a área (km²): \n");
    scanf("%f", &area2);

    printf("Digite o PIB (em Bilhões): \n");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turisticos: \n");
    scanf("%d", &pontos2);

    // Cálculo das variáveis adicionais
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;



    //==========================================
    // MENU INTERATIVO
    //==========================================

    int opcao1 = 0, opcao2 = 0;
    int atributos_usados[7] = {0};

    // Primeiro Atributo
    do{
        printf("\n==== MENU DE COMPARAÇÃO ====\n");
        printf("Escolha o primeiro atributo: \n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turisticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("6 - PIB per Capita\n");
        printf("Digite a primeira opção: ");
        scanf("%d", &opcao1);
        if (opcao1 <  1 || opcao1 > 6) {
            printf("Opção inválida: Tente Novamente.\n");
        }
    } while (opcao1 < 1 || opcao1 > 6);

    atributos_usados[opcao1] = 1;

    // Segundo atributo 
    do {
        printf("\n==== MENU COMPARAÇÃO ===\n");
        printf("Escolha o segundo atributo: \n");
        for (int i =1; i <= 6; i++) {
            if (!atributos_usados[i]) {
                switch(i) {
                    case 1: printf("1 - População\n"); break;
                    case 2: printf("2 - Área\n"); break;
                    case 3: printf("3 - PIB\n"); break;
                    case 4: printf("4 - Pontos Turisticos\n"); break;
                    case 5: printf("5 - Densidade Demográfica\n"); break;
                    case 6: printf("6 - PIB per Capita\n"); break;
                }
            }
        }
        printf("Digite a segunda opção (Diferente da primeira): ");
        scanf("%d", &opcao2);
        if (opcao2 < 1 || opcao2 > 6 || atributos_usados[opcao2]) {
            printf("Opção inválida! Tente novamente.\n");
        } 
    } while (opcao2 < 1 || opcao2 > 6 || atributos_usados[opcao2]);

    //Função para pegar valores dos atributos
    float valor1c1 = 0, valor2c1 = 0, valor1c2 = 0, valor2c2 = 0;
    char nome_atrib1[40], nome_atrib2[40]; //para mostrar nomes dos atributos


    //Primeira escolha
    switch(opcao1){
        case 1: valor1c1 = populacao1; valor1c2 = populacao2; sprintf(nome_atrib1,"População"); break;
        case 2: valor1c1 = area1; valor1c2 = area2; sprintf(nome_atrib1, "àrea"); break;
        case 3: valor1c1 = pib1; valor1c2 = pib2; sprintf(nome_atrib1, "PIB"); break;
        case 4: valor1c1 = pontos1; valor1c2 = pontos2; sprintf(nome_atrib1, "Pontos Turisticos"); break;
        case 5: valor1c1 = densidade1; valor1c2 = densidade2; sprintf(nome_atrib1, "Densidade Demográfica"); break;
        case 6: valor1c1 = pibPerCapita1; valor1c2 = pibPerCapita2; sprintf(nome_atrib1, "PIB per Capita"); break;
    }

    //Segunda Escolha
    switch(opcao2){
        case 1: valor2c1 = populacao1, valor2c2 = populacao2; sprintf(nome_atrib2, "População"); break;
        case 2: valor2c1 = area1, valor2c2 = area2; sprintf(nome_atrib2, "Área"); break;
        case 3: valor2c1 = pib1; valor2c2 = pib2; sprintf(nome_atrib2, "PIB"); break;
        case 4: valor2c1 = pontos1; valor2c2 = pontos2; sprintf(nome_atrib2, "Pontos Turisticos"); break;
        case 5: valor2c1 = densidade1; valor2c2 = densidade2; sprintf(nome_atrib2, "Densidade Demográfica"); break;
        case 6: valor2c1 = pibPerCapita1; valor2c2 = pibPerCapita2; sprintf(nome_atrib2, "PIB per Capita"); break;
    }
    
    
    //Comparação individual
    int vitorias_carta1 = 0, vitorias_carta2 = 0;
    printf("\n=== COMPARAÇÂO ATRIBUTOS ===\n");
    printf("\nAtributo 1: %s\n", nome_atrib1);
    printf("%s: %.2f\n", cidade1, valor1c1);
    printf("%s: %.2f\n", cidade2, valor1c2);
    if (opcao1 == 5) {
        if (valor1c1 < valor1c2) { printf("Vencedora: %s\n", cidade1); vitorias_carta1++; }
        else if (valor1c2 < valor1c1) { printf("Vencedora: %s\n", cidade2); vitorias_carta2++; }
        else { printf("Empate!\n"); }
    } else {
        if (valor1c1 > valor1c2) { printf("Vencedora: %s\n", cidade1); vitorias_carta1++; }
        else if (valor1c2 > valor1c1) { printf("Vencedora: %s\n", cidade2); vitorias_carta2++; }
        else { printf("Empate!\n"); }
    }

    printf("\nAtributos 2: %s\n", nome_atrib2);
    printf("%s: %.2f\n", cidade1, valor2c1);
    printf("%s: %.2f\n", cidade2, valor2c2);
    if (opcao2 == 5) {
        if (valor2c1 < valor2c2) { printf("Vencedora: %s\n", cidade1); vitorias_carta1++; }
        else if (valor2c2 < valor2c1) { printf("Vencedora: %s\n", cidade2); vitorias_carta2++; }
        else { printf("Empate!\n"); }
    } else {
        if (valor2c1 > valor2c2) { printf("Vencedora: %s\n", cidade1); vitorias_carta1++; }
        else if (valor2c2 > valor2c1) { printf("Vencedora: %s\n", cidade2); vitorias_carta2++; }
        else { printf("Empate!\n"); }
    }

    //SOMA DOS ATRIBUTOS E RESULTADO FINAL
    float soma1 = valor1c1 + valor2c1;
    float soma2 = valor1c2 + valor2c2;
    printf("\n === SOMA DOS ATRIBUTOS ===\n");
    printf("%s: %.2f\n", cidade1, soma1);
    printf("%s: %.2f\n", cidade2, soma2);

    printf("\n==== RESULTADO DA RODADA ====\n");
    if (soma1 > soma2) {
        printf("A carta Vencedora é: %s\n", cidade1);
    } else if (soma2 > soma1) {
        printf("A carta vencedora é: %s\n", cidade2);
    } else {
        printf("Empate!\n");
    }
     


 
    printf("\n==== DADOS COMPLETOS DAS CARTAS ====\n");

    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", pib1);
    printf("Pontos turisticos: %d\n", pontos1);
    printf("Densidade populacional: %.2f hab/km²\n", densidade1);
    printf("Pib per Capita: %.2f\n", pibPerCapita1);

    printf("\n--- CARTA 2 ---\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões\n", pib2);
    printf("Pontos Turisticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f\n", pibPerCapita2);


    return 0;
}
