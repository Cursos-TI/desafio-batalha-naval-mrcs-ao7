#include <stdio.h>

int main(){
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coluna[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int barcoH[3] = {3, 3, 3};
    int barcoV[3] = {3, 3, 3};
    int tabuleiro[10][10] = {
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

    printf("\n       "); // Detalhe estético
    printf("< BATALHA NAVAL >\n \n");

    for(int letras = 0; letras <= 9; letras++) // As letras de cima.
    {
        // Alinhar as letras de cima com o tabuleiro.
        letras <= 0 ? printf("    %c  ", linha[letras]) : // Alinhando "A".
                      printf("%c  ", linha[letras]); // O resto não precisa desse alinhamento.
    }

    printf("\n"); // Pular linha depois de todas as letras serem imprimidas.

    tabuleiro[5][3] = barcoH[0];
    tabuleiro[5][4] = barcoH[1]; // "Colando" o Barco Horizontal no tabuleiro. 
    tabuleiro[5][5] = barcoH[2];

    tabuleiro[0][8] = barcoV[0];
    tabuleiro[1][8] = barcoV[1]; // "Colando" o Barco Vertical no tabuleiro.
    tabuleiro[2][8] = barcoV[2];

    for(int linhaM = 0; linhaM <= 9; linhaM++) // Linhas - - -
    {
        printf("%2d  ", coluna[linhaM]); // Imprime os números de fora do tabuleiro.

        for(int colunaM = 0; colunaM <= 9; colunaM++) // Colunas | | |
        {
            printf("%d  ", tabuleiro[linhaM][colunaM]); // O tabuleiro.
        }

        printf("\n"); // Pular linha no final de cada loop.
    }

    printf("\n"); // Detalhe estético.
   
    return 0;
}
