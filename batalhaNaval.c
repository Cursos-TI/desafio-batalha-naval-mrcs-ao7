#include <stdio.h>

// Define os valores das linhas e colunas, tanto de fora como dentro do tabuleiro.
#define LINHA 10
#define COLUNA 10

int main(){
    char linha[LINHA];
    int coluna[COLUNA];
    int barcos[3] = {3, 3, 3};
    int tabuleiro[LINHA][COLUNA];

    printf("        "); // Detalhe estético
    printf("< BATALHA NAVAL >\n \n");

    for(int x = 0; x < LINHA; x++)
    {
        linha[x] = 'A' + x; // Imprime as letras de A a J 
        x != 0 ? printf("%c  ", linha[x]) : // Garante que as letras depois do A estejam propriamente colocadas.
                 printf("    %c  ", linha[x]); // Garante que o A esteja alinhado com o tabuleiro.
    }

    printf("\n"); // Pular linha depois de todas as letras serem imprimidas.


    for(int a = 0; a < LINHA; a++){ 
        coluna[a] = a + 1; // Garantindo os valores dos números fora do tabuleiro.

        for(int b = 0; b < COLUNA; b++){
            tabuleiro[a][b] = 0; // Garantindo que o tabuleiro seja imprimido com 0.
        }
    }

    tabuleiro[5][3] = barcos[0];
    tabuleiro[5][4] = barcos[1]; // "Colando" o Barco Horizontal no tabuleiro. 
    tabuleiro[5][5] = barcos[2];

    tabuleiro[0][8] = barcos[0];
    tabuleiro[1][8] = barcos[1]; // "Colando" o Barco Vertical no tabuleiro.
    tabuleiro[2][8] = barcos[2];

    //

    tabuleiro[7][0] = barcos[0];
    tabuleiro[8][1] = barcos[1]; // "Colando" o primeiro Barco Diagonal no tabuleiro. 
    tabuleiro[9][2] = barcos[2];

    tabuleiro[3][1] = barcos[0];
    tabuleiro[2][2] = barcos[1]; // "Colando" o segundo Barco Diagonal no tabuleiro.
    tabuleiro[1][3] = barcos[2];


    for(int i = 0; i < LINHA; i++){
        printf("%2d  ", coluna[i]); // Imprimindo os números de fora.

        for(int j = 0; j < COLUNA; j++){
            printf("%d  ", tabuleiro[i][j]);  // Imprimindo o tabuleiro
        }

        printf("\n"); // Pula linha no final de cada loop.
    }

    printf("\n"); // Detalhe estético.

    return 0;
}