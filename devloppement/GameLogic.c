#include "GameLogic.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>

int nextPlayer(int PlayerAmount, int PlayerTurn)
{
	return ((PlayerTurn + 1) % PlayerAmount);
}

void bankrupt(Player *p)
{
	p->money = 0;
}

int Winner(int moneyp1, int moneyp2, int moneyp3)
{
	if (moneyp1 > moneyp3)
	{
		if (moneyp1 > moneyp2)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		if (moneyp3 > moneyp2)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
}
