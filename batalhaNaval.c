#include <stdio.h>

// Define os valores das linhas e colunas.

#define LINHA 10
#define COLUNA 10
// Valores de fora e dentro do tabuleiro.

#define HLINHA 3
#define HCOLUNA 5
// Valores das habilidades.

void habilidadeCone(int arrH[HLINHA][HCOLUNA], int arrT[LINHA][COLUNA]){
    int target1 = 2, target2 = 2; // Coloca um "limite" da area do cone.

    for(int i = 0; i < HLINHA; i++){
        for(int j = 0; j < HCOLUNA; j++) // Loops para preencher a area total do cone.
        {
            arrH[i][j] = 0; // Preenche a area total do cone com '0'

            if(j >= target1 && j <= target2){ // Aplica a lógica para formar o cone.

                arrH[i][j] = 1; // Área do cone preenchido com '1'.
            }

            if(arrH[i][j] == 1) arrH[i][j] = 4; // A área '1' era preenchida com '4'.
            arrT[i + 7][j + 5] = arrH[i][j]; // "Cola" a matriz do cone no tabuleiro
        }

        // // Ao fim de cada loop, aumenta o limite em cada lado, até formar o cone.
        target1--;
        target2++;
    }
}

// A lógica se repete nas habilidades da cruz e octaedro.

void habilidadeCruz(int arrH[HLINHA][HCOLUNA], int arrT[LINHA][COLUNA]){
    int target1 = 2, target2 = 2;

    for(int i = 0; i < HLINHA; i++){
        for(int j = 0; j < HCOLUNA; j++)
        {
            arrH[i][j] = 0;

            if(j >= target1 && j <= target2){
                arrH[i][j] = 1;
            }

            if(arrH[i][j] == 1) arrH[i][j] = 1;
            arrT[i + 1][j + 3] = arrH[i][j];
        }

        // Quando o loop chegar na segunda linha, será adicionado dois numeros para formar a cruz.
        // Qaundo o loop já tiver passado pela segunda linha, o limite reseta aotamanho inicial, formando a cruz.

        if(i == 1){ 
            target1 = 2;
            target2 = 2;
        } 
        
        else {
            target1 -= 2;
            target2 += 2;
        }
    }
}

void habilidadeOctaedro(int arrH[HLINHA][HLINHA], int arrT[LINHA][COLUNA]){
    int target1 = 1, target2 = 1;

    for(int i = 0; i < HLINHA; i++){
        for(int j = 0; j < HLINHA; j++)
        {
            arrH[i][j] = 0;

            if(j >= target1 && j <= target2){
                arrH[i][j] = 1;
            }

            if(arrH[i][j] == 1) arrH[i][j] = 8;
            arrT[i + 5][j + 0] = arrH[i][j];
        }

        // Quando o loop chegar na segunda linha, será adicionado um numero para formar o octaedro.
        // Qaundo o loop já tiver passado pela segunda linha, o limite reseta ao tamanho inicial, formando o octaedro.

        if(i == 1){
            target1 = 1;
            target2 = 1;
        }

        else{
            target1--;
            target2++;
        }
    }
}

int main(){
    char linha[LINHA];
    int coluna[COLUNA];
    int tabuleiro[LINHA][COLUNA];

    int barcos = 3;

    int cone[HLINHA][HCOLUNA];
    int cruz[HLINHA][HCOLUNA];
    int octaedro[HLINHA][HLINHA];

    printf("\n       "); // Detalhe estético
    printf("< BATALHA NAVAL >\n \n");

    for(int a = 0; a < LINHA; a++)
    {
        linha[a] = 'A' + a; // Imprime as letras de A a J 
        a != 0 ? printf("%c  ", linha[a]) : // Garante que as letras depois do A estejam propriamente colocadas.
                 printf("    %c  ", linha[a]); // Garante que o A esteja alinhado com o tabuleiro.
    }

    printf("\n"); // Pular linha depois de todas as letras serem imprimidas.


    for(int b = 0; b < LINHA; b++){ 
        coluna[b] = b + 1; // Garantindo os valores dos números fora do tabuleiro.

        for(int c = 0; c < COLUNA; c++){
            tabuleiro[b][c] = 0; // Garantindo que o tabuleiro seja imprimido com 0.
        }
    }

    tabuleiro[5][3] = barcos;
    tabuleiro[5][4] = barcos; // "Colando" o Barco Horizontal no tabuleiro. 
    tabuleiro[5][5] = barcos;

    tabuleiro[0][8] = barcos;
    tabuleiro[1][8] = barcos; // "Colando" o Barco Vertical no tabuleiro.
    tabuleiro[2][8] = barcos;

    //

    tabuleiro[7][0] = barcos;
    tabuleiro[8][1] = barcos; // "Colando" o primeiro Barco Diagonal no tabuleiro. 
    tabuleiro[9][2] = barcos;

    tabuleiro[3][1] = barcos;
    tabuleiro[2][2] = barcos; // "Colando" o segundo Barco Diagonal no tabuleiro.
    tabuleiro[1][3] = barcos;

    habilidadeCone(cone, tabuleiro);
    habilidadeCruz(cruz, tabuleiro);
    habilidadeOctaedro(octaedro, tabuleiro);

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