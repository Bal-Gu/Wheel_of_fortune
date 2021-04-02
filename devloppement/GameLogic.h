#ifndef GameLogic
#define GameLogic
#include "player.h"
#include <stdio.h>
#include <stdlib.h>

/*
*The player that is playing next
*
*@PlayerAmount the amount of players that are playing
*@PlayerTurn the player that is currently playing 
*
*/
int nextPlayer(int PlayerAmount, int PlayerTurn);

/*
*The player will have his money set to 0
*
*@Player *p the player that is lossing his money
*
*/
void bankrupt(Player *p);

/*
*This functions looks which player has to most money.
*Per default 2 wins
*
*@moneyp1 the money Player 1 has
*@moneyp2 the money Player 2 has
*@moneyp3 the money Player 3 has
*/
int Winner(int moneyp1, int moneyp2, int moneyp3);

#endif
