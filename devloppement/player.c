#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "player.h"

//freeing the
Player *initPlayer(char *NAME, int Position, int color)
{
	Player *p = malloc(sizeof(Player));
	p->money = 0;
	p->name = malloc(strlen(NAME) + 1);
	strcpy(p->name, NAME);
	p->canPlay = 1;
	p->playerPosition = Position;
	p->color = color;
}

//freeing the players
void freePlayer(Player *p)
{
	free(p->name);
	p->name = NULL;
	free(p);
}
