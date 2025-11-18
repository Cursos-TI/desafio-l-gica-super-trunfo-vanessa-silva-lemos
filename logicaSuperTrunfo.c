#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    char estado1, estado2;
    char codigo1[5], codigo2[5];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos1, pontos2;
    float densidade1, densidade2;
    float pibPerCapita1, PibPerCapita2;

    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio
    
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o estado (A-H): ");
    scanf("%c", &estado1);

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


    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    // Cálculo das variáveis adicionais
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    PibPerCapita2 = (pib2 * 1000000000) / populacao2;


    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }


    //==========================================
    // MENU INTERATIVO
    //==========================================


    int opcao;
    printf("\n==== MENU DE COMPARAÇÃO ====\n");
    printf("Escolha um atributo para comparar: \n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao);


    printf("\n==== COMPARAÇÂO ENTRE AS CARTAS ====\n");

    switch (opcao)
    {
    case 1: //população
        printf("Atributo escolhido: População\n");
        printf("%s: %lu\n", cidade1, populacao1);
        printf("%s: %lu\n", cidade2, populacao2);

        if(populacao1 > populacao2)
            printf("Vencedora:%s\n", cidade1);
        else if (populacao2 > populacao1)
            printf("Vencedora: %s\n", cidade2);
        else
            printf("Empate!\n");

        break;
    
    case 2: //Area
        printf("Atributo escolhido: Área (km²)\n");
        printf("%s: %.2f\n", cidade1, area1);
        printf("%s: %.2f\n", cidade2, area2);

        if (area1 > area2)
            printf("Vencedora: %s\n", cidade1);
        else if (area2 > area1)
            printf("Vencedora: %s\n", cidade2);
        else
            printf("Empate!\n");

        break;

    case 3: //PIB
        printf("Atributo escolhido: PIB\n");
        printf("%s: %.2f bilhões\n",cidade1, pib1);
        printf("%s: %.2f bilhões\n", cidade2, pib2);

        if (pib1 > pib2)
            printf("Vencedora: %s\n", cidade1);
        else if (pib2 > pib1)
            printf("Vencedora: %s\n", cidade2);
        else
            printf("Empate!\n");

        break;

    case 4: //Pontos Turisticos
        printf("Atributo escolhido: Pontos Turisticos\n");
        printf("%s: %d\n", cidade1, pontos1);
        printf("%s: %d\n", cidade2, pontos2);

        if (pontos1 > pontos2)
            printf("Vencedora: %s\n", cidade1);
        else if (pontos2 > pontos1)
            printf("Vencedora: %s\n", cidade2);
        else
            printf("Empate!\n");
        
        break;

    case 5: //Densidade (regra invertida)
        printf("Atributo escolhido: Densidade Demográfica\n");
        printf("%s: %.2f hab/knm²\n", cidade1, densidade1);
        printf("%s: %.2f hab/km²\n", cidade2, densidade2);

        if (densidade1 < densidade2)
            printf("Vencedora (menor densidade): %s\n", cidade1);
        else if (densidade2 < densidade1)
            printf("Vencedora (menor densidade): %s\n", cidade2);
        else
            printf("Empate!\n");

        break;

    case 6: //PIB per Capita
        printf("Atributo escolhido: PIB per Capita\n");
        printf("%s: %.2f\n", cidade1, pibPerCapita1);
        printf("%s: %.2f\n", cidade2, PibPerCapita2);

        if (pibPerCapita1 > PibPerCapita2)
            printf("Vencedora: %s\n", cidade1);
        else if (PibPerCapita2 > pibPerCapita1)
            printf("Vencedora: %s\n", cidade2);
        else
            printf("Empate!\n");

        break;

    
    default:
        printf("Opção inválida! Tente novamente.\n");
        break;
    }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

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
    printf("PIB per Capita: %.2f\n", PibPerCapita2);



    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}
