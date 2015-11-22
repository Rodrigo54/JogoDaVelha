/**
 * @package Jogo da Velha
 *
 * @author Rodrigo Alves Mesquita <rodrigo54mix@gmail.com>
 * @link http://www.github.com/rodrigo54
 * @version 0.4
 * @date 21 Nov 2015
 * @copyright 2015 by Rodrigo Alves Mesquita
 *
 * @file main.c
**/

#include "JogoDaVelha.h"

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
