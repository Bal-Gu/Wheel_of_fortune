#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WheelFields 24
#define MaxStringSize 10

char *getField(char **Wheel, int fieldNum)
{

	//small optimistation where we don't reinitialise the wheel
	if (strcmp(Wheel[0], "BankRupt"))
	{

		strcpy(Wheel[0], "Bankrupt");
		strcpy(Wheel[1], "Bankrupt");
		strcpy(Wheel[2], "Extra Turn");
		strcpy(Wheel[3], "Lose a Turn");
		strcpy(Wheel[4], "500$");
		strcpy(Wheel[5], "500$");
		strcpy(Wheel[6], "500$");
		strcpy(Wheel[7], "500$");
		strcpy(Wheel[8], "550$");
		strcpy(Wheel[9], "600$");
		strcpy(Wheel[10], "600$");
		strcpy(Wheel[11], "600$");
		strcpy(Wheel[12], "600$");
		strcpy(Wheel[13], "650$");
		strcpy(Wheel[14], "650$");
		strcpy(Wheel[15], "650$");
		strcpy(Wheel[16], "700$");
		strcpy(Wheel[17], "700$");
		strcpy(Wheel[18], "700$");
		strcpy(Wheel[19], "800$");
		strcpy(Wheel[20], "800$");
		strcpy(Wheel[21], "900$");
		strcpy(Wheel[22], "900$");
		strcpy(Wheel[23], "2500$");
	}

	return Wheel[fieldNum];
}

//Initate the wheel and mallocs space

char **initwheel()
{

	char **wheel = malloc(WheelFields * sizeof(char *));
	for (int i = 0; i < WheelFields; i++)
	{
		wheel[i] = malloc(MaxStringSize * sizeof(char));
	}
	for (int i = 0; i < WheelFields; i++)
	{
		for (int j = 0; j < MaxStringSize; j++)
		{
			wheel[i][j] = '0';
		}
	}
	return wheel;
}

//free the space malloced by the wheel

void freewheel(char **wheel)
{

	for (int i = 0; i < WheelFields; ++i)
	{

		free(wheel[i]);
		wheel[i] = NULL;
	}

	free(wheel);
	wheel = NULL;
}
