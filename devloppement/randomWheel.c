#include "randomWheel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void initseed(long seed)
{
	srand(seed);
}

void initSeedRandom()
{
	time_t t;
	srand((unsigned)time(&t));
}

char randomChar()
{
	char randomChar, sample[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789$,.\'\?- ";
	int len = strlen(sample);
	randomChar = sample[rand() % len];
	return randomChar;
}

int randomInt(int max)
{
	//avoids unintentional 0 outputs
	if (max == 0)
	{
		return 1;
	}
	int randomNumber = (rand() % max);
	return randomNumber + 1;
}
