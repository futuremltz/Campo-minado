#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Linhas 9
#define Colunas 9
#define total_bombas 10

int tela[Linhas][Colunas];
int visao_jogador[Linhas][Colunas];

void inicializaTela(){
  int bombas = 0;
  int linhas_sorteada, colunas_sorteada;

  for (int i = 0; i < Linhas; i++)
  {
    for (int j = 0; j < Colunas; j++)
    {
      tela[i][j] = 0;
    }
  }

  while (bombas < total_bombas)
  {
    linhas_sorteada = rand() % Linhas;
    colunas_sorteada = rand() % Colunas;

    if (tela[linhas_sorteada][colunas_sorteada] != -1) {
            tela[linhas_sorteada][colunas_sorteada] = -1;
            bombas++;
        }
  }

  for (int i = 0; i < Linhas; i++) {
      for (int j = 0; j < Colunas; j++) {
          
          if (tela[i][j] != -1) {
              
              int conta_bombas = 0;

              for (int linha_vizinha = i - 1; linha_vizinha <= i + 1; linha_vizinha++) {
                  
                  for (int coluna_vizinha = j - 1; coluna_vizinha <= j + 1; coluna_vizinha++) {
                      
                      if (linha_vizinha >= 0 && linha_vizinha < Linhas && coluna_vizinha >= 0 && coluna_vizinha < Colunas) {
                          
                          if (tela[linha_vizinha][coluna_vizinha] == -1) {
                              conta_bombas++;
                          }
                      }
                  }
              }
              
              tela[i][j] = conta_bombas;
          }
      }
  }
}

void imprimeTelaJogador() {
    for (int i = 0; i < Linhas; i++){
        for (int j = 0; j < Colunas; j++){
            if (visao_jogador[i][j] == 0){
                printf(" X ");
            } else {
                printf("%2d ", tela[i][j]);
            }
        }
        printf("\n");

    }
    printf("\n");
}

void imprimeTelaOriginal(){
    for (int i = 0; i < Linhas; i++){
        for (int j = 0; j < Colunas; j++){
            printf("%2d ", tela[i][j]);
        }
        printf("\n");
    }
}

void posicaoEscolhida(int linha, int coluna){
   if (linha < 0 || linha >= Linhas || coluna < 0 || coluna >= Colunas) {
        return;
    }

    if (visao_jogador[linha][coluna] == 1) {
        return;
    }

    visao_jogador[linha][coluna] = 1; 

    if (tela[linha][coluna] == 0) {
        for (int i = linha - 1; i <= linha + 1; i++) {
            for (int j = coluna - 1; j <= coluna + 1; j++) {
                posicaoEscolhida(i, j);
            }
        }
    }
    

}


int main() {
    srand(time(NULL));
    int menu = 1, coluna, linha;
    
    inicializaTela();
    while (menu){
        imprimeTelaJogador();

        printf("Digite a linha (0 a %d): ", Linhas - 1);
        scanf("%d", &linha);
        printf("Digite a coluna (0 a %d): ", Colunas - 1);
        scanf("%d", &coluna);

        while (linha < 0 || linha >= Linhas || coluna < 0 || coluna >= Colunas) {
        printf("Coordenada invalida! Tente novamente.\n");
        printf("Digite a linha (0 a %d): ", Linhas - 1);
        scanf("%d", &linha);
        printf("Digite a coluna (0 a %d): ", Colunas - 1);
        scanf("%d", &coluna);
        }
        posicaoEscolhida(linha, coluna);

        if (tela[linha][coluna] == -1){
            imprimeTelaOriginal();
            printf("voce perdeu");
            menu = 0;
        }else{
            int aberto = 0;
            for (int i = 0; i < Linhas; i++){
                for (int j = 0; j < Colunas; j++){
                    if (visao_jogador[i][j] == 1){
                        aberto++;
                    }
                }
            }
            if (aberto == (Linhas * Colunas) - total_bombas) {
                imprimeTelaJogador();
                printf("Voce ganhou!\n");
                menu = 0;
            }
        }
        
    }
  return 0;
}