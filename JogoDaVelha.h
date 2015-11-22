/**
 * @package Jogo da Velha
 *
 * @author Rodrigo Alves Mesquita <rodrigo54mix@gmail.com>
 * @link http://www.github.com/rodrigo54
 * @version 0.4
 * @date 21 Nov 2015
 * @copyright 2015 by Rodrigo Alves Mesquita
 *
 * @file JogoDaVelha.h
**/

#ifndef JOGODAVELHA_H_INCLUDED
#define JOGODAVELHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define DIM 3

void ZerarJogo(char vet[DIM][DIM]);
void MostraJogo(char vet[DIM][DIM]);
int ConfereDiagonal(char vet[DIM][DIM], char item);
int ConfereLinha(char vet[DIM][DIM], char item);
int ConfereColuna(char vet[DIM][DIM], char item);
int ConfereJogo(char vet[DIM][DIM], char item);
void InsereVelha(char vet[DIM][DIM], char item);

#endif // JOGODAVELHA_H_INCLUDED
