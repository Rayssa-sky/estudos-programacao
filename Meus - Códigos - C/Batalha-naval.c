#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 7
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0
#define EFEITO_HABILIDADE 5

int main() {
  
    int matriz_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matriz_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matriz_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    int centro = TAMANHO_HABILIDADE / 2;


    // 1. Represente o Tabuleiro: Matriz 10x10, inicializada com 0 (Água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {AGUA}; // Inicializa todos com 0
    
    // 2. Declare e inicialize dois vetores (arrays unidimensionais) para representar os navios
    // Ambos são preenchidos com o valor 3 (NAVIO)
    int navio_horizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO}; // {3, 3, 3}
    int navio_vertical[TAMANHO_NAVIO]   = {NAVIO, NAVIO, NAVIO};   // {3, 3, 3}

    
    // --- Posicionamento do Navio Horizontal (Início: Linha 2, Coluna 1) ---
    int linha_h = 2; 
    int coluna_h = 1; 
    
    // Loop para COPIAR o valor 3 de cada posição do vetor para o tabuleiro
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        // tabuleiro[Linha Fixa][Coluna Inicial + j] = valor do vetor navio_horizontal[j]
        tabuleiro[linha_h][coluna_h + j] = navio_horizontal[j];
    }

    
    // --- Posicionamento do Navio Vertical (Início: Linha 5, Coluna 6) ---
    int linha_v = 5; 
    int coluna_v = 6; 
    
    // Loop para COPIAR o valor 3 de cada posição do vetor para o tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        // tabuleiro[Linha Inicial + i][Coluna Fixa] = valor do vetor navio_vertical[i]
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

  // --- Posicionamento do Navio diagonal 1 (Início: linha 5, coluna 1)
     int linha_inicial_p = 5;
     int coluna_inicial_p = 1;
 // k representa o (deslocamento)
for (int k = 0; k < TAMANHO_NAVIO; k++) {
        int i = linha_inicial_p + k;
        int j = coluna_inicial_p + k;
        
        // Colocamos uma checagem simples de limite para garantir que funcione
        if (i < TAMANHO_TABULEIRO && j < TAMANHO_TABULEIRO) {
            tabuleiro[i][j] = NAVIO; 
        }
    }

      // --- Posicionamento do Navio diagonal 2 (Início: linha 0, coluna 7)

    int linha_inicial_s = 0;
    int coluna_inicial_s = 7; 
    
    // k representa o (deslocamento)
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        int i = linha_inicial_s + k; // A linha aumenta
        int j = coluna_inicial_s - k; // A coluna diminui
        
        // Colocamos uma checagem simples de limite para garantir que funcione
        if (i < TAMANHO_TABULEIRO && j >= 0) {
            tabuleiro[i][j] = NAVIO; 
        }
     }

// --- Construção e Aplicação da Habilidade: CONE ---

printf("\n ===== Aplicando Habilidade Cone ===== \n");
int linha_origem_cone = 2; //topo do cone
int coluna_origem_cone = 6;

//matriz de habilidade: CONE
for(int i = 0; i < TAMANHO_HABILIDADE; i++){
    for(int j = 0; j < TAMANHO_HABILIDADE; j++){
        matriz_cone[i][j] = 0; //INICIALIZA
        //Condicional de FORMA
        if( j >= centro - i && j <= centro + i && i <= centro){
            matriz_cone[i][j] = 1;
        }
    }
}
// Aplica a Matriz ao Tabuleiro (sobreposição)
for(int i = 0; i < TAMANHO_HABILIDADE; i++){
    for(int j = 0; j < TAMANHO_HABILIDADE; j++){

        if(matriz_cone[i][j] == 1){

         int tab_i, tab_j;
         // Mapeamento para o Tabuleiro (Origem é o TOPO)
         tab_i = linha_origem_cone + i;
         tab_j = coluna_origem_cone + j;
         // Condicional de LIMITE
         if(tab_i >= 0 && tab_i < TAMANHO_TABULEIRO && tab_j >= 0 && tab_j < TAMANHO_TABULEIRO){
          // Condicional de SOBREPOSIÇÃO
          if(tabuleiro[tab_i][tab_j] != NAVIO){
            tabuleiro[tab_i][tab_j] = EFEITO_HABILIDADE;
          }
         }

        }
    }
}
// --- Construção e Aplicação da Habilidade: CRUZ ---
printf("--- Aplicando Habilidade: CRUZ ---\n");
    int linha_origem_cruz = 6; // Centro da cruz
    int coluna_origem_cruz = 1;

    // 1. Constrói a Matriz de Habilidade (matriz_cruz)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz_cruz[i][j] = 0; // Inicializa
            
            // Condicional de FORMA: Cruz (Linha ou Coluna Central)
            if (i == centro || j == centro) {
                matriz_cruz[i][j] = 1;
            }
        }
    }

    // 2. Aplica a Matriz ao Tabuleiro (sobreposição)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            if (matriz_cruz[i][j] == 1) {
                
                int tab_i, tab_j;
                
                // Mapeamento para o Tabuleiro (Origem é o CENTRO)
                tab_i = linha_origem_cruz - centro + i;
                tab_j = coluna_origem_cruz - centro + j;

                // Condicional de LIMITE (Obrigatória)
                if (tab_i >= 0 && tab_i < TAMANHO_TABULEIRO && tab_j >= 0 && tab_j < TAMANHO_TABULEIRO) {
                    
                    // Condicional de SOBREPOSIÇÃO (Não afeta Navios)
                    if (tabuleiro[tab_i][tab_j] != NAVIO) {
                        tabuleiro[tab_i][tab_j] = EFEITO_HABILIDADE;
                    }
                }
            }
        }
    }

    
    // -Construção e Aplicação da Habilidade: OCTAEDRO (Losango)
    printf("--- Aplicando Habilidade: OCTAEDRO ---\n");
    int linha_origem_octa = 5; // Centro do losango
    int coluna_origem_octa = 4;
    
    // 1. Constrói a Matriz de Habilidade (matriz_octaedro)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz_octaedro[i][j] = 0; // Inicializa
            
            int dist_h = j > centro ? j - centro : centro - j;
            int dist_v = i > centro ? i - centro : centro - i;
            int dist_manhattan = dist_h + dist_v;
            
            // Condicional de FORMA: Octaedro/Losango (Distância de Manhattan)
            if (dist_manhattan <= centro) {
                matriz_octaedro[i][j] = 1;
            }
        }
    }

    // 2. Aplica a Matriz ao Tabuleiro (sobreposição)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            if (matriz_octaedro[i][j] == 1) {
                
                int tab_i, tab_j;
                
                // Mapeamento para o Tabuleiro (Origem é o CENTRO)
                tab_i = linha_origem_octa - centro + i;
                tab_j = coluna_origem_octa - centro + j;

                // Condicional de LIMITE (Obrigatória)
                if (tab_i >= 0 && tab_i < TAMANHO_TABULEIRO && tab_j >= 0 && tab_j < TAMANHO_TABULEIRO) {
                    
                    // Condicional de SOBREPOSIÇÃO (Não afeta Navios)
                    if (tabuleiro[tab_i][tab_j] != NAVIO) {
                        tabuleiro[tab_i][tab_j] = EFEITO_HABILIDADE;
                    }
                }
            }
        }
    }

    // --- Exibir o Tabuleiro Final ---
    printf("\n--- TABULEIRO FINAL ---\n");
    printf("~=Agua | N=Navio | X=Area Afetada\n");
    
    // Cabeçalho das Colunas
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf(" %d", j);
    }
    printf("\n  +--------------------\n");
    
    // Corpo do Tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d |", i); 
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            
            if (tabuleiro[i][j] == NAVIO) {
                printf(" N"); // Navio
            } else if (tabuleiro[i][j] == EFEITO_HABILIDADE) {
                printf(" X"); // Área Afetada (Efeito de Habilidade)
            } else {
                printf(" ~"); // Água
            }
        }
        printf("\n"); 
    }
    
    return 0;
}
