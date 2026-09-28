#include <stdio.h>
#include <stdlib.h> // Necessário para a função system("pause")

int main() {
    // Variáveis para a Carta 1
    char estado1[2];
    char codigo1[5]; 
    char nome_cidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float Densidade_pop1;
    float pib_per1;

    // Variáveis para a Carta 2
    char estado2[2];
    char codigo2[5]; 
    char nome_cidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float Densidade_pop2;
    float pib_per2;

    
    
    // ---------------- ENTRADA DE DADOS ----------------
    
    printf("--- Cadastro de Cartas Super Trunfo ---\n\n");

    // CARTA 1
    printf("--- DADOS DA CARTA 1 ---\n");
    printf("Estado (Letra 'A' a 'H'): ");
    scanf("%1s", estado1);
    
    printf("Codigo da Carta (ex: A01): ");
    scanf("%4s", codigo1);
    
    printf("Nome da Cidade (UMA PALAVRA): ");
    scanf(" %s", nome_cidade1); // O espaco antes do %s ajuda a evitar o '\n'
    
    printf("Populacao (habitantes): ");
    scanf(" %d", &populacao1);
    
    printf("Area (km2): ");
    scanf(" %f", &area1);
    
    printf("PIB (bilhoes de reais): ");
    scanf(" %f", &pib1);
    
    printf("Numero de Pontos Turisticos: ");
    scanf(" %d", &pontos_turisticos1);


    // CARTA 2
    printf("\n--- DADOS DA CARTA 2 ---\n");
    printf("Estado (Letra 'A' a 'H'): ");
    scanf("%1s", estado2);
    
    printf("Codigo da Carta (ex: A01): ");
    scanf("%4s", codigo2);
    
    printf("Nome da Cidade (UMA PALAVRA): ");
    scanf(" %s", nome_cidade2); // O espaco antes do %s ajuda a evitar o '\n'
    
    printf("Populacao (habitantes): ");
    scanf("%d", &populacao2);
    
    printf("Area (km2): ");
    scanf("%f", &area2);
    
    printf("PIB (bilhoes de reais): ");
    scanf("%f", &pib2);
    
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos2);


    //CÁLCULOS DA CARTA 1//

    Densidade_pop1 = (populacao1) / (area1);
    pib_per1 = (pib1 * 1000000000.0) / populacao1;

    //CÁLCULOS DA CARTA 2//

    Densidade_pop2 = (populacao2) / (area2);
    pib_per2 = (pib2 * 1000000000.0) / populacao2;



    // ---------------- EXIBIÇÃO DE DADOS ----------------//
    
    printf("\n\n--- INFORMACOES DAS CARTAS ---\n");
    
    // CARTA 1
    printf("\n--- CARTA 1 (%s) ---\n", codigo1);
    printf("Estado: %s\n", estado1);
    printf("Codigo da Carta: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nome_cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", Densidade_pop1);
    printf("PIB per Capita: %.2f Reais\n", pib_per1);

    // CARTA 2
    printf("\n--- CARTA 2 (%s) ---\n", codigo2);
    printf("Estado: %s\n", estado2);
    printf("Codigo da Carta: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nome_cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", Densidade_pop2);
    printf("PIB per Capita: %.2f Reais\n", pib_per2);
    
    // PAUSA O PROGRAMA PARA EXIBIR OS RESULTADOS
    printf("\n\nPressione ENTER para fechar a janela...");
    system("pause"); 

    return 0;
}

