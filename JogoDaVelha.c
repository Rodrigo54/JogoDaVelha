/**
 * @package Jogo da Velha
 *
 * @author Rodrigo Alves Mesquita <rodrigo54mix@gmail.com>
 * @link http://www.github.com/rodrigo54
 * @version 0.4
 * @date 21 Nov 2015
 * @copyright 2015 by Rodrigo Alves Mesquita
 *
 * @file JogoDaVelha.c
**/

#include "JogoDaVelha.h"

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
  wprintf(L"\n\t ██╗   ██╗███████╗██╗     ██╗  ██╗ █████╗ ");
  wprintf(L"\n\t ██║   ██║██╔════╝██║     ██║  ██║██╔══██╗");
  wprintf(L"\n\t ██║   ██║█████╗  ██║     ███████║███████║");
  wprintf(L"\n\t ╚██╗ ██╔╝██╔══╝  ██║     ██╔══██║██╔══██║");
  wprintf(L"\n\t  ╚████╔╝ ███████╗███████╗██║  ██║██║  ██║");
  wprintf(L"\n\t   ╚═══╝  ╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝");

  wprintf(L"\n\n\t\t┌─── JOGO DA VELHA ───┐");
  wprintf(L"\n\t\t│                     │");
  wprintf(L"\n\t\t│      %c │ %c │ %c      │", vet[0][0], vet[0][1], vet[0][2]);
  wprintf(L"\n\t\t│     ───┼───┼───     │");
  wprintf(L"\n\t\t│      %c │ %c │ %c      │", vet[1][0], vet[1][1], vet[1][2]);
  wprintf(L"\n\t\t│     ───┼───┼───     │");
  wprintf(L"\n\t\t│      %c │ %c │ %c      │", vet[2][0], vet[2][1], vet[2][2]);
  wprintf(L"\n\t\t│                     │");
  wprintf(L"\n\t\t└─────────────────────┘\n");
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

  wprintf(L"\n\tDigite a Linha e a Coluna da jogada");
  wprintf(L"\n\tUse espaço para separar os valores: ");
  scanf("%d %d", &linha, &coluna);
  if (vet[linha - 1][coluna - 1] != 'X' && vet[linha - 1][coluna - 1] != 'O')
  {
    vet[linha - 1][coluna - 1] = item;
  }
  else{
    wprintf(L"\n\tEscolha outro lugar! ");
    InsereVelha(vet,item);
  }
}
