#include <stdio.h>

#define barco 3

// Exibição do tabuleiro
void ExibirMatriz(int linha, int coluna, int matriz[linha][coluna]){ // Exibindo a matriz
    printf("\n  --------------------------------------------------------------------------------\n"); 

    printf("\t");

    for(char letra = 'A'; letra <= 'J'; letra++){ // Mostra as letras na parte superior do tabuleiro
        printf("%c\t",letra);
    }

    printf("\n  --------------------------------------------------------------------------------\n"); 

    for (int i = 0; i < linha; i++){// Loop que percorre as linhas
        printf("%d | \t", i); // Mostra o indice da linha

        for (int j = 0; j < coluna; j++){ // Loop percorre as colunas
            printf("%d\t", matriz[i][j]); // Mostra o valor na linha e coluna indicada

        }
        printf("\n"); // Quebra ao fim da linha
    }

}

void ExibeBarcos(int linha, int coluna, int tabuleiro[linha][coluna]) {
    // Barco vertical na coluna 5 (F), linhas 3,4,5
    for (int i = 3; i <= 5; i++) {
        tabuleiro[i][5] = barco;
    }

    // Barco horizontal na linha 7, colunas 2,3,4 (C, D, E)
    for (int j = 2; j <= 4; j++) {
        tabuleiro[7][j] = barco;
    }

    // Barco na diagonal principal (1,1), (2,2), (3,3)
    for (int k = 1; k <= 3; k++) {
        tabuleiro[k][k] = barco;
    }

    // Barco na diagonal i + j = 9 (6,3), (7,2), (8,1)
    for (int i = 6; i <= 8; i++) {
        tabuleiro[i][9 - i] = barco;
    }
}

// Ataque em forma de cone
void AtaqueCone(int linha, int coluna, int matriz[linha][coluna], int TabuleiroVisivel[linha][coluna]) {
    int MatrizCone[3][5] = {{0, 0, 5, 0, 0}, {0, 5, 5, 5, 0}, {5, 5, 5, 5, 5}}; // Matriz de área atacada
    int attck1, attck2; // Valores onde será atacado

    printf("Onde atacar (linha e coluna)? ");
    scanf("%d %d", &attck1, &attck2);

    // Validação das coordenadas
    if (attck1 < 0 || attck1 >= linha || attck2 < 0 || attck2 >= coluna) {
        printf("Coordenadas inválidas!\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int x = attck1 + i - 1; // Desloca a matriz do cone para o local de ataque
            int y = attck2 + j - 2;

            if (x >= 0 && x < linha && y >= 0 && y < coluna) { // Verifica se está dentro dos limites
                // Verifica primeiro se é parte do padrão de ataque
                if (MatrizCone[i][j] == 5) { 
                    if (matriz[x][y] == barco) { // Se o barco estiver no local
                        TabuleiroVisivel[x][y] = barco; // Mantém o Barco
                    } else {
                        TabuleiroVisivel[x][y] = 5;  // Ataque no restante do cone
                    }
                }
            }
        }
    }

    ExibirMatriz(linha, coluna, TabuleiroVisivel);
}

// Ataque em formto de cruz
void AtaqueCruz(int linha, int coluna, int matriz[linha][coluna], int TabuleiroVisivel[linha][coluna]){
    int MatrizCruz[3][5] = {{0, 0, 5, 0, 0}, {5, 5, 5, 5, 5}, {0, 0, 5, 0, 0}};
    int attck1, attck2;

    printf("Onde atacar (linha e coluna)? ");
    scanf("%d %d", &attck1, &attck2);

    // Validação das coordenadas
    if (attck1 < 0 || attck1 >= linha || attck2 < 0 || attck2 >= coluna) {
        printf("Coordenadas inválidas!\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int x = attck1 + i - 1; // Desloca a matriz do cone para o local de ataque
            int y = attck2 + j - 2;

            if (x >= 0 && x < linha && y >= 0 && y < coluna) { // Verifica se está dentro dos limites
                // Verifica primeiro se é parte do padrão de ataque
                if (MatrizCruz[i][j] == 5){ // Se o barco estiver no local
                    if (matriz[x][y] == barco){
                        TabuleiroVisivel[x][y] = barco; // Mantém o Barco
                    } else{
                        TabuleiroVisivel[x][y] = 5;
                    }
                }
            }
        }
    }

    ExibirMatriz(linha, coluna, TabuleiroVisivel);
}

// Ataque em forma de prisma
void AtaquePrisma(int linha, int coluna, int matriz[linha][coluna], int TabuleiroVisivel[linha][coluna]){
    int MatrizPrisma[3][5] = {{0, 0, 5, 0, 0}, {0, 5, 5, 5, 0}, {0, 0, 5, 0, 0}};
    int attck1, attck2;

    printf("Onde atacar (linha e coluna)? ");
    scanf("%d %d", &attck1, &attck2);

    // Validação das coordenadas
    if (attck1 < 0 || attck1 >= linha || attck2 < 0 || attck2 >= coluna) {
        printf("Coordenadas inválidas!\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int x = attck1 + i - 1; // Desloca a matriz do cone para o local de ataque
            int y = attck2 + j - 2;

            if (x >= 0 && x < linha && y >= 0 && y < coluna) { // Verifica se está dentro dos limites
                if (MatrizPrisma[i][j] == 5){ // Se o barco estiver no local
                    if (matriz[x][y] == barco){
                        TabuleiroVisivel[x][y] = barco; // Mantém o Barco
                    } else{
                        TabuleiroVisivel[x][y] = 5;
                    }
                }
            }
        }
    }

    ExibirMatriz(linha, coluna, TabuleiroVisivel);
}

int main(){   
    int tabuleiro[10][10] = { // Iniciando uma matriz que representa o tabuleiro
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int TabuleiroVisivel[10][10] = { // Iniciando uma matriz que representa o tabuleiro
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int opcao, sair = 1;
    ExibeBarcos(10, 10, tabuleiro); // Adiciona barcos ao tabuleiro principal

    printf("\n======= Batalha Naval =======\n");
    printf("    Barco = 3.\n");
    printf("    Área atacada = 5.\n");

    while(sair){
        // Opção de jogo
        printf("\n============================\n");
        printf("[1] - Ataque em Cone.\n");
        printf("[2] - Ataque em Cruz.\n");
        printf("[3] - Ataque em Prisma.\n");
        printf("[4] - Sair.\n");
        printf("\n Opção: ");
        scanf("%d", &opcao);
        printf("\n============================\n");

        switch (opcao){

            case 1:
                AtaqueCone(10, 10, tabuleiro, TabuleiroVisivel); // Ataque em forma de cone
                break;

            case 2:
                AtaqueCruz(10, 10, tabuleiro, TabuleiroVisivel); // Ataque em forma de cruz
                break;

            case 3:
                AtaquePrisma(10, 10, tabuleiro, TabuleiroVisivel); // Ataque em forma de Prisma
                break;

            case 4:
                sair = 0; // Encerra o jogo
                break;

            default:
                printf("Opção invalida!");
                break;
        }

    }


    return 0;
}
