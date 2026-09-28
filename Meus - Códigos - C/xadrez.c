#include <stdio.h>

// --- Funções Recursivas para Torre, Bispo e Rainha ---

// 1. Torre (Recursividade)
// Simula o movimento da Torre em uma única direção (por exemplo, Direita)
void moverTorreRecursivo(int casasRestantes) {
    if (casasRestantes <= 0) {
        return; // Caso base: parou o movimento
    }
    printf("Torre: Move para DIREITA\n");
    
    moverTorreRecursivo(casasRestantes - 1);
}

// 2. Bispo (Recursividade e Loops Aninhados)
// Simula o movimento do Bispo na diagonal (Cima e Direita)
void moverBispoRecursivo(int casasRestantes) {
    if (casasRestantes <= 0) {
        return; 
    }

// 2. Bispo (Recursividade e Loops Aninhados)
// Simula o movimento do Bispo na diagonal (Cima e Direita)
void moverBispoRecursivo(int casasRestantes) {
   
    int i, j; 

    if (casasRestantes <= 0) {
        return; 
    }

    // Estrutura de Loops Aninhados para o Bispo (Vertical -> Horizontal)
    // O loop mais externo (i) controla o movimento vertical
    for (i = 0; i < 1; i++) {
        // O loop mais interno (j) controla o movimento horizontal
        for (j = 0; j < 1; j++) {
            printf("Bispo: Move CIMA, Direita (Casa %d)\n", casasRestantes);
        }
    }
}  
    
    moverBispoRecursivo(casasRestantes - 1);
}  

// 3. Rainha (Recursividade)
// Simula o movimento da Rainha (por exemplo, em linha reta para a Esquerda)
void moverRainhaRecursivo(int casasRestantes) {
    if (casasRestantes <= 0) {
        return; // Caso base: parou o movimento
    }
    printf("Rainha: Move para ESQUERDA\n");
   
    moverRainhaRecursivo(casasRestantes - 1);
}

// --- Função Principal ---

int main() {
    int casas_Torre = 5;
    int casas_Bispo = 5;
    int casas_Rainha = 8;
    int passos_vertical, passos_horizontal;

    // 1. Movimento da Torre (Recursividade)
    printf("--- Movimento da Torre (Recursividade) ---\n");
    moverTorreRecursivo(casas_Torre);
    printf("Movimento da Torre Completo.\n\n");

    // 2. Movimento do Bispo (Recursividade com Loops Aninhados)
    printf("--- Movimento do Bispo (Recursividade + Loops Aninhados) ---\n");
    moverBispoRecursivo(casas_Bispo);
    printf("Movimento do Bispo Completo.\n\n");

    // 3. Movimento da Rainha (Recursividade)
    printf("--- Movimento da Rainha (Recursividade) ---\n");
    moverRainhaRecursivo(casas_Rainha);
    printf("Movimento da Rainha Completo.\n\n");

    // 4. Movimento do Cavalo (Loops Complexos)
    // Movimento: Duas casas para CIMA e uma para a DIREITA, usando 'continue' e 'break'.
    printf("--- Movimento do Cavalo (Loops Complexos: 2 Cima, 1 Direita) ---\n");

    // Loop externo: Controla os dois passos verticais (CIMA)
    for (passos_vertical = 1; passos_vertical <= 3; passos_vertical++) {

        if (passos_vertical == 3) {
            // Usa 'break' para sair do loop vertical após os 2 passos (para não afetar o horizontal)
            break;
        }

        printf("Passo %d: Move para CIMA\n", passos_vertical);

        // Loop aninhado: Controla o passo horizontal (DIREITA)
        // Só queremos 1 passo horizontal (passos_vertical == 2)
        for (passos_horizontal = 1; passos_horizontal <= 2; passos_horizontal++) {
            // Múltiplas condições: O passo horizontal só acontece DEPOIS dos dois passos verticais.
            if (passos_vertical == 2 && passos_horizontal == 1) {
                printf("Passo 3: Move para DIREITA\n");
            } else {
                // Usa 'continue' para pular a iteração desnecessária do passo horizontal
                continue;
            }
            }
       }
}
