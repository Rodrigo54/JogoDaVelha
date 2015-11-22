/**
 * @package Jogo da Velha
 * programa que atende os requisitos do
 * trabalho de Projeto e Análise de Algoritmos
 *
 * @author Rodrigo Alves Mesquita <rodrigo54mix@gmail.com>
 * @link http://www.github.com/rodrigo54
 * @version 1.5
 * @date 21 Nov 2015
 * @copyright 2015 by Rodrigo Alves Mesquita
 *
 * @file main.c
**/

#include <stdio.h>
#include <stdlib.h>
#define DIM 3

void ZerarJogo(char vet[DIM][DIM])
{
  int i, j;
  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++) {
      vet[i][j] = ' ';
    }
  }
}

void MostraJogo(char vet[DIM][DIM])
{
  printf("%c | %c | %c \n", vet[0][0], vet[0][1], vet[0][2]);
  printf("%c | %c | %c \n", vet[1][0], vet[1][1], vet[1][2]);
  printf("%c | %c | %c \n", vet[2][0], vet[2][1], vet[2][2]);
  printf("\n");
}

int ConfereDiagonal(char vet[DIM][DIM], char item)
{
  int i, dig1 = 0, dig2 = 0;

  for (i = 0; i < DIM; i++) {
    if (vet[i][i] == item) {
      dig1++;
    }
    if (vet[i][2-i] == item) {
      dig2++;
    }
  }
  if (dig1 == 3 || dig2 == 3) {
    return 1;
  }
  else return 0;
}

int ConfereLinha(char vet[DIM][DIM], char item) {
  int lin;
  for (int i = 0; i < DIM; i++) {
    lin = 0;
    for (int j = 0; j < DIM; j++) {
      if (vet[i][j] == item) {
        lin++;
      }
    }
    if (lin == 3) {
      return 1;
    }
  }
  return 0;
}

int ConfereColuna(char vet[DIM][DIM], char item) {
  int col;

  for (int i = 0; i < DIM; i++) {
    col = 0;
    for (int j = 0; j < DIM; j++) {
      if (vet[j][i] == item) {
        col++;
      }
    }
    if (col == 3) {
      return 1;
    }
  }
  return 0;
}

int ConfereJogo(char vet[DIM][DIM], char item) {
  int d, l, c;
  d = ConfereDiagonal(vet, item);
  l = ConfereLinha(vet, item);
  c = ConfereColuna(vet, item);
  if (d == 1 || l == 1 || c == 1) {
    return 1;
  }
  else return 0;
}

void InsereVelha(char vet[DIM][DIM], char item) {
  int linha, coluna;

  printf("Digite a Linha e a Coluna da jogada:\n");
  scanf("%d %d", &linha, &coluna);
  vet[linha - 1][coluna - 1] = item;
}

int main() {
  system("title JOGO DA VELHA");
  system("color 0e");
  /*CORES 1=FUNDO 2=TEXTO
    0 = Preto        8 = Cinza
    1 = Azul         9 = Azul claro
    2 = Verde        A = Verde claro
    3 = Verde-água   B = Verde-água claro
    4 = Vermelho     C = Vermelho claro
    5 = Roxo         D = Lilás
    6 = Amarelo      E = Amarelo claro
    7 = Branco       F = Branco brilhante
  */

  char velha[DIM][DIM], jogada;
  int GG = 0, player, jogs = 0, cont = 2;

  ZerarJogo(velha);
  MostraJogo(velha);

  do{
    player = cont % 2;
    if(player == 0) jogada = 'X';
    else jogada = 'O';

    InsereVelha(velha, jogada);
    system("clear || cls");
    MostraJogo(velha);
    GG = ConfereJogo(velha, jogada);
    if (GG == 1) {
      printf("O jogador %d venceu!\n", player+1);
      return 0;
    }
    cont++;
    jogs++;
  }while(jogs < 9);
  system("clear || cls");
  printf("O jogo terminou em empate.\n");
  MostraJogo(velha);
  return 0;
}
