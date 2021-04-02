#include "randomWheel.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define LENGTHOFCONSOL 240

int stringlen(char *str)
{
	char completestr[LENGTHOFCONSOL];
	for (int i = 0; i < LENGTHOFCONSOL; i++)
	{
		completestr[i] = '\0';
	}
	strcpy(completestr, str);
	return strlen(completestr);
}

void printTopLine()
{
	printf("\033[1m");
	printf("┌");
	for (int i = 0; i < LENGTHOFCONSOL - 2; i++)
	{
		printf("─");
	}
	printf("┐\n");
}

void printBottomLine()
{
	printf("\033[1m");
	printf("└");
	for (int i = 0; i < LENGTHOFCONSOL - 2; i++)
	{
		printf("─");
	}
	printf("┘\n");
}

void ConsolPrint(char *stringOut, int color, int bold, int MustPrintLeft, int *lenToPrint)
{
	if (bold != 1 && bold != 0)
	{
		perror("Please only use 1 or 0 for the bold");
		exit(1);
	}

	if ((color < 30 && color != 0) || color > 36)
	{
		perror("Not a valid color");
		exit(1);
	}
	int lengthToPrint = 0;
	if (lenToPrint == NULL)
	{
		lengthToPrint = LENGTHOFCONSOL;
	}
	else
	{
		lengthToPrint = *lenToPrint;
	}

	int length = stringlen(stringOut);
	int counter = 0;

	//reset just to make sure
	printf("\033[0m");

	if (MustPrintLeft)
	{
		//first left bar
		printf("\033[1m");
		printf("│");
		counter += 1;
	}

	//print the middle part
	int howManyWhiteSpace = lengthToPrint / 2 - length / 2;
	for (int i = counter; i < howManyWhiteSpace; i++, counter++)
	{
		printf(" ");
	}

	//print the output with the asked color and bold
	if (color)
	{
		printf("\033[%d;%dm", bold, color);
	}
	else
	{
		printf("\033[%dm", bold);
	}
	printf("%s", stringOut);
	counter += length;

	//right spaces
	for (int i = counter; i < lengthToPrint - 1; i++)
	{
		printf(" ");
	}

	//reset
	printf("\033[0m");

	//right bar
	printf("\033[1m");
	printf("│");

	//reset
	printf("\033[0m");
}

void printPlayerName(Player **playerList, int amount)
{
	int size = amount;
	char *sentence = malloc(sizeof(char));
	for (int i = 0; i < size; i++)
	{

		int bank = randomInt(6);

		if (bank == 1)
		{
			strcpy(sentence, "Welcome ");
		}
		else if (bank == 2)
		{
			strcpy(sentence, "Hello ");
		}
		else if (bank == 3)
		{
			strcpy(sentence, "Greetings ");
		}
		else if (bank == 4)
		{
			strcpy(sentence, "Bienvenue ");
		}
		else if (bank == 5)
		{
			strcpy(sentence, "Willkommen ");
		}
		else if (bank == 6)
		{
			strcpy(sentence, "Benvenuto ");
		}
		strcat(sentence, playerList[i]->name);
		ConsolPrint(sentence, playerList[i]->color, 1, 1, NULL);
		puts("");
	}
	free(sentence);
}

void printMiddleLine(int intersections, int layer)
{
	int bank, check = 1;
	if (intersections < 0)
	{
		check = 0;
	}
	else if (intersections >= 0)
	{
		intersections++;
		bank = LENGTHOFCONSOL / (intersections);
	}
	if (layer == 1 && check == 1)
	{
		for (int i = 0; i < LENGTHOFCONSOL; i++)
		{
			if (i == 0)
			{
				printf("├");
			}
			else if ((i % bank) == 0)
			{
				printf("┼");
			}
			else if (i == LENGTHOFCONSOL - 1)
			{
				printf("┤\n");
			}
			else
			{
				printf("─");
			}
		}
	}
	else if (layer == 2 && check == 1)
	{
		for (int i = 0; i < LENGTHOFCONSOL; i++)
		{
			if (i == 0)
			{
				printf("├");
			}
			else if ((i % bank) == 0)
			{
				printf("┴");
			}
			else if (i == LENGTHOFCONSOL - 1)
			{
				printf("┤\n");
			}
			else
			{
				printf("─");
			}
		}
	}
	else if (layer == 3 && check == 1)
	{
		for (int i = 0; i < LENGTHOFCONSOL; i++)
		{
			if (i == 0)
			{
				printf("├");
			}
			else if ((i % bank) == 0)
			{
				printf("┬");
			}
			else if (i == LENGTHOFCONSOL - 1)
			{
				printf("┤\n");
			}
			else
			{
				printf("─");
			}
		}
	}
	else if (layer > 3 && layer < 1 && check == 1)
	{
		char *sentence = "This is not a possible layer Mode";
		ConsolPrint(sentence, 31, 1, 1, NULL);
	}
	else if (check == 0)
	{
		char *sentence = "Please put a positive integer value for interractions.";
		ConsolPrint(sentence, 31, 1, 1, NULL);
	}
}

void printWronganswer()
{


	// initSeedRandom();
	int bank = randomInt(10);
	if (bank == 0)
	{
		char *sentence = "That is a wrong Answer...";
		ConsolPrint(sentence, 31, 1, 1, NULL);
		puts("");
	}
	else if (bank == 1)
	{
		char *sentence = "Wrong, you'll get more luck next time!";
		ConsolPrint(sentence, 31, 1, 1, NULL);
		puts("");
	}
	else if (bank == 2)
	{
		char *sentence = "Wrong!";
		ConsolPrint(sentence, 31, 1, 1, NULL);
		puts("");
	}
	else if (bank == 3)
	{
		char *sentence = "False, i'm sure you can do better!";
		ConsolPrint(sentence, 31, 1, 1, NULL);
		puts("");
	}
	else if (bank == 4)
	{
		char *sentence = "Sorry, it's false.";
		ConsolPrint(sentence, 31, 1, 1, NULL);
		puts("");
	}
	else if (bank == 5)
	{
		char *sentence = "Wrong Answer.";
		ConsolPrint(sentence, 31, 1, 1, NULL);
		puts("");
	}
	else if (bank == 6)
	{
		char *sentence = "Wrong. You'll get it next time!";
		ConsolPrint(sentence, 31, 1, 1, NULL);
		puts("");
	}
	else if (bank == 7)
	{
		char *sentence = "Wrong. Don't surrender now!";
		ConsolPrint(sentence, 31, 1, 1, NULL);
		puts("");
	}
	else if (bank == 8)
	{
		char *sentence = "This is a bad Answer.";
		ConsolPrint(sentence, 31, 1, 1, NULL);
		puts("");
	}
	else if (bank == 9)
	{
		char *sentence = "Wrong, don't give up!";
		ConsolPrint(sentence, 31, 1, 1, NULL);
		puts("");
	}
}

void randomOutput(char *realOutput)
{
	char Output[stringlen(realOutput)];
	int index = 0;
	int len = strlen(realOutput);

	for (int i = index; i < len; i++)
	{
		Output[i] = 'a';
	}

	int iterations = 0;

	struct timespec ts, ts2;
	ts.tv_sec = 0;
	ts.tv_nsec = 10000000L;
	int color = 0;

	while (strncmp(Output, realOutput, len))
	{

		//first left bar
		printf("\033[1m");
		printf("│");
		printf("\033[0m");

		printf("\033[0;%dm", index % 7 + 30);

		for (int i = 0; i < iterations; i++)
		{

			printf(" ");
		}

		if (tolower(Output[index]) == tolower(realOutput[index]))
		{
			index += 1;
			color = randomInt(7) % 7;
		}

		for (int i = index; i < len; i++)
		{
			Output[i] = realOutput[i] >= 'A' && realOutput[i] <= 'Z' ? randomChar() : tolower(randomChar());
		}

		nanosleep(&ts, &ts2);
		for (int i = 0; i < len; i++)
		{
			printf("%c", Output[i]);
		}

		if (!strncmp(Output, realOutput, len))
		{
			printf("\r");
			ConsolPrint(realOutput, color + 30, 1, 1, NULL);
			puts("");
		}
		else
		{
			printf("\r");
		}

		//-5 to have a slightly centered effect
		if (iterations != LENGTHOFCONSOL / 2 - 5)
		{
			iterations += 1;
		}
	}
}

void printPlayerInfoBoxTurnPlayer(Player *p1, Player *p2, Player *p3, int PlayersTurn, int amount)
{

	int len2 = (amount == 3) ? LENGTHOFCONSOL / amount : (LENGTHOFCONSOL / amount) - 1;
	int len1 = (amount == 3) ? len2 + 1 : len2 + 2;
	int len3 = len2 - 1;
	printMiddleLine(amount - 1, 3);

	//Puts the PlayersTurn out in it's color
	if (PlayersTurn == 0)
	{
		ConsolPrint("It's your turn", p1->color, 1, 1, &len1);
	}
	else
	{
		if (p1->canPlay)
		{

			ConsolPrint("", p1->color, 1, 1, &len1);
		}
		else
		{

			ConsolPrint("You can't play this turn", 31, 1, 1, &len1);
		}
	}

	if (PlayersTurn == 1)
	{
		ConsolPrint("It's your turn", p2->color, 1, 0, &len2);
	}
	else
	{
		if (p2->canPlay)
		{
			ConsolPrint("", p2->color, 1, 0, &len2);
		}
		else
		{
			ConsolPrint("You can't play this turn", 31, 1, 0, &len2);
		}
	}

	if (p3 != NULL)
	{

		if (PlayersTurn == 2)
		{
			ConsolPrint("It's your turn", p3->color, 1, 0, &len3);
		}
		else
		{

			if (p3->canPlay)
			{
				ConsolPrint("", p3->color, 1, 0, &len3);
			}
			else
			{
				ConsolPrint("You can't play this turn", 31, 1, 0, &len3);
			}
		}
	}
	//newline
	puts("");

	//Puts the PlayersName out in it's color

	ConsolPrint(p1->name, p1->color, 0, 1, &len1);
	ConsolPrint(p2->name, p2->color, 0, 0, &len2);
	if (amount == 3)
	{
		ConsolPrint(p3->name, p3->color, 0, 0, &len3);
	}
	//newline
	puts("");

	//Puts the amount the Player has
	char Intstr[15];

	sprintf(Intstr, "%d", p1->money);
	strcat(Intstr, "$");

	ConsolPrint(Intstr, p1->color, 0, 1, &len1);
	sprintf(Intstr, "%d", p2->money);
	strcat(Intstr, "$");
	ConsolPrint(Intstr, p2->color, 0, 0, &len2);
	if (amount == 3)
	{
		sprintf(Intstr, "%d", p3->money);
		strcat(Intstr, "$");
		ConsolPrint(Intstr, p3->color, 0, 0, &len3);
	}
	puts("");

	printMiddleLine(amount - 1, 2);
}

void printVisibleOutPut(char *PlayerView, char *Question)
{

	ConsolPrint(Question, 0, 1, 1, NULL);
	for (int i = 0; i < 3; i++)
	{
		puts("");
		ConsolPrint("", 0, 0, 1, NULL);
	}
	puts("");

	ConsolPrint(PlayerView, 0, 0, 1, NULL);
	puts("");
}

void printWinner(char *name)
{

	int startingpoint = LENGTHOFCONSOL / 2 - strlen(name) / 2 - 1;
	name = strdup(name);
	name = realloc(name, strlen(name) + 20);

	strcat(name, " has won.");

	char lines[LENGTHOFCONSOL];

	char lineWithName[LENGTHOFCONSOL];

	for (int i = 0; i < LENGTHOFCONSOL - 2; i++)
	{
		lines[i] = '-';
	}

	for (int i = 0; i < LENGTHOFCONSOL - 2; i++)
	{
		lineWithName[i] = '-';
	}

	for (int i = startingpoint; i < strlen(name) + startingpoint; i++)
	{
		lineWithName[i] = name[i - startingpoint];
	}

	//will be used for a small delay between the animation
	struct timespec ts1, ts2;
	ts1.tv_sec = 0;
	ts1.tv_nsec = 150000000L; //adding 50ms by iterations

	// animation last 30 seconds
	int mSeconds = 1000 * 30;

	int addingTime = 500;
	// starting time
	clock_t startTime = clock();
	clock_t endTime = clock();
	int iterations = 1;
	int keys[(mSeconds / addingTime)];

	puts(lines);
	puts(lineWithName);
	printf("%s", lines);

	// looping till required time is not achieved
	while (endTime - startTime < mSeconds)
	{

		//adding every 0.25 sec a new whitespace

		keys[iterations] = 1;
		for (int i = 1; i < iterations; i++)
		{
			//leaves the borders alone
			if (!(keys[i] % LENGTHOFCONSOL == 0 || (keys[i] + 1) % LENGTHOFCONSOL == 0))
			{
				//reset
				printf("\033[0m");
				//set curser on left most place
				printf("\r");
				//set curser amount of lines up
				int position = (keys[i] % (3 * LENGTHOFCONSOL)) / LENGTHOFCONSOL;
				printf("\033[%dA", position);
				//set curser right and reset the last place
				printf("\033[%dC", (keys[i] % LENGTHOFCONSOL));
				printf("-");
				//set the curser 1 right with colors and blink
				printf("\033[%dm", iterations % 8 + 40);
				printf("\033[5C");
				printf("\033[5m");
				printf(" ");
				printf("\033[0m");
				//set the curser back
				printf("\r");
				//set curser amount of lines down
				printf("\033[%dB", position);
			}
			keys[i] += 5;
		}
		nanosleep(&ts1, &ts2);
		iterations += 1;
		for (int i = 0; i < 3; i++)
		{
			printf("\r");
			printf("\033[K");
			if (i != 2)
			{
				printf("\033[1A");
			}
		}

		if (iterations % 3 == 0)
		{
			puts(lines);
			puts(lineWithName);
			printf("%s", lines);
		}

		else if (iterations % 3 == 1)
		{
			puts(lines);
			puts(lines);
			printf("%s", lineWithName);
		}

		else if (iterations % 3 == 2)
		{
			puts(lineWithName);
			puts(lines);
			printf("%s", lines);
		}
		endTime = clock();
	}
}

/*int main()
{
	initSeedRandom();
	char fuu[] = "1000000E";
	char fuu1[] = "11";
	char fuu2[] = "joueur de manettes";
	char fuu3[] = "Quite le crossplay.";

	randomOutput(fuu);
	randomOutput(fuu1);
	randomOutput(fuu2);
	randomOutput(fuu3);


	return 0;
}*/