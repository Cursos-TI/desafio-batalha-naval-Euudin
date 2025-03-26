#include <stdio.h>

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

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Exibindo o tabuleiro ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

    printf("\t");

    for(char letra = 'A'; letra <= 'J'; letra++){ // Mostra as letras na parte superior do tabuleiro
        printf("%c\t",letra);
    }

    printf("\n  --------------------------------------------------------------------------------\n"); 

    for (int i = 0; i < 10; i++){ // Loop que percorre as linhas
        printf("%d | \t", i); // Mostra o indice da linha

        for (int j = 0; j < 10; j++){ // Loop percorre as colunas
            printf("%d\t", tabuleiro[i][j]); // Mostra o valor na linha e coluna indicada
        }

        printf("\n"); // Quebra ao fim da linha
    }

    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n") ;

    for (int i = 0; i < 10; i++){ // Adicionando o Barco vertical no tabuleiro
        for (int j = 0; j < 10; j++){
            if (j == 5){ // Barco será adiconado na coluna 5 
                tabuleiro[3][j] = 1;
                tabuleiro[4][j] = 1;
                tabuleiro[5][j] = 1;
            }
            else if (i == 7){ // Barco será adicionado na linha 7
                tabuleiro[i][2] = 1;
                tabuleiro[i][3] = 1;
                tabuleiro[i][4] = 1;
            }
            else if (i == j){ // Barco Adicionado na diagonal Linha == Coluna
                tabuleiro[2][2] = 1;
                tabuleiro[3][3] = 1;
                tabuleiro[4][4] = 1;
            }
            else if ( i + j == 9){ // Barco Adicionado na outra diagonal
                tabuleiro[7][8] = 1;
                tabuleiro[8][7] = 1;
                tabuleiro[9][6] = 1;
            }
            else{
                continue;
            }
        }
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Exibindo o tabuleiro ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

    printf("\t");

    for(char letra = 'A'; letra <= 'J'; letra++){ // Mostra as letras na parte superior do tabuleiro
        printf("%c\t",letra);
    }

    printf("\n  --------------------------------------------------------------------------------\n"); 

    for (int i = 0; i < 10; i++){ // Loop que percorre as linhas
        printf("%d | \t", i); // Mostra o indice da linha

        for (int j = 0; j < 10; j++){ // Loop percorre as colunas
            printf("%d\t", tabuleiro[i][j]); // Mostra o valor na linha e coluna indicada
        }

        printf("\n"); // Quebra ao fim da linha
    }


    return 0;
}