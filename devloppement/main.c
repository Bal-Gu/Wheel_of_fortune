#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "PrintToConsol.h"
#include "player.h"
#include "textToFind.h"
#include "GameLogic.h"
#include "playerAction.h"
#include "randomWheel.h"
#include "wheel.h"

#define useranswerMax 100
#define MaxLength 240
void flush()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}

//makes a small pause so that the terminal can follow
void pause()
{
	struct timespec ts, ts2;
	ts.tv_sec = 0;
	ts.tv_nsec = 10000L;
	nanosleep(&ts, &ts2);
}

//clean the buffer with only '\0'
void cleanupBuffer(char *buff)
{
	for (int i = 0; i < useranswerMax; i++)
	{
		buff[i] = '\0';
	}
}

//goes one step above and delete that line
void deleteUserInput()
{
	printf("\r");
	printf("\033[1A");
	printf("\r");
	printf("\033[K");
}

int main()
{

	FILE *f = fopen("sentences.txt", "r");

	//init the buffer to avoid garbage comparaison
	char useranswers[useranswerMax];
	cleanupBuffer(useranswers);

	printTopLine();

	//setup to know how many player we want
	int players = 0;
	ConsolPrint("How many Player do you want(Either 2 or 3)", 0, 0, 1, NULL);
	puts("");
	pause();
	useranswers[0] = getchar();
	flush();

	deleteUserInput();

	//print in Red on the last line asking to renter the player amount
	while (useranswers[0] != '2' && useranswers[0] != '3')
	{

		ConsolPrint("Please enter either 2 or 3 ", 31, 1, 1, NULL);
		puts("");
		pause();
		useranswers[0] = getchar();
		flush();

		deleteUserInput();
		deleteUserInput();
	}
	//delete the last line
	deleteUserInput();

	players = (int)strtol(useranswers, NULL, 10);

	strcat(useranswers, " users were selected");
	ConsolPrint(useranswers, 0, 0, 1, NULL);
	puts("");
	printMiddleLine(0, 1);
	cleanupBuffer(useranswers);
	Player *playerList[players];
	char defaultName[] = "Default";
	for (int i = 0; i < players; i++)
	{
		//init everything with defaults value
		playerList[i] = initPlayer(defaultName, i, 0);
	}

	// set username to  each player
	for (int j = 0; j < players; j++)
	{
		
		sprintf(useranswers, "Player % d : What is your name ? ", j + 1);
		ConsolPrint(useranswers, 0, 1, 1, NULL);
		puts("");
		cleanupBuffer(useranswers);
		pause();
		fgets(useranswers, useranswerMax, stdin);
		deleteUserInput();

		//avoid crashing the programm by getting digits in the fist place
		if (isdigit(useranswers[0]))
		{
			ConsolPrint("We are sorry to tell you that your name can't start with a digit please restart the programm.", 31, 1, 1, NULL);
			puts("");
			exit(1);
		}
		strcpy(playerList[j]->name, useranswers);

		deleteUserInput();
		cleanupBuffer(useranswers);
	}

	//Strip the newline out of the playername
	for (int i = 0; i < players; i++)
	{

		playerList[i]->name[strlen(playerList[i]->name) - 1] = '\0';
	}

	printPlayerName(playerList, players);
	// set color of each player
	for (int i = 0; i < players; i++)
	{
		int save = 0;
		cleanupBuffer(useranswers);
		while (useranswers[0] < '0' || useranswers[0] > '7')
		{
			cleanupBuffer(useranswers);
			sprintf(useranswers, " %s : What do you want as a Color ? ", playerList[i]->name);
			ConsolPrint(useranswers, 0, 1, 1, NULL);
			puts("");
			ConsolPrint("0 - WHITE ", 0, 1, 1, NULL);
			puts("");
			ConsolPrint("1 - BLACK", 30, 1, 1, NULL);
			puts("");
			ConsolPrint("2 - RED", 31, 1, 1, NULL);
			puts("");
			ConsolPrint("3 - GREEN", 32, 1, 1, NULL);
			puts("");
			ConsolPrint("4 - YELLOW", 33, 1, 1, NULL);
			puts("");
			ConsolPrint("5 - BLUE", 34, 1, 1, NULL);
			puts("");
			ConsolPrint("6 - MAGENTA", 35, 1, 1, NULL);
			puts("");
			ConsolPrint("7 - CYAN", 36, 1, 1, NULL);
			puts("");
			pause();
			useranswers[0] = getchar();
			flush();
			save = (int)strtol(useranswers, NULL, 10);
			for (int i = 0; i < 9; i++)
			{
				deleteUserInput();
			}
		}

		playerList[i]->color = save ? save + 29 : save;
		cleanupBuffer(useranswers);

		//Prints the user name with the respecitv color

		sprintf(useranswers, " Your name : %s looks now like this. ", playerList[i]->name);
		ConsolPrint(useranswers, playerList[i]->color, 0, 1, NULL);
		cleanupBuffer(useranswers);
		puts("");
	}

	char **Wheel = initwheel();
	int check = 0;
	int checkRedundancy[3];
	int size = sizeof checkRedundancy / sizeof checkRedundancy[0];
	for(int i = 0; i < size; i++){
		checkRedundancy[i] = 0;
	}
	int randomCategories;
	//start at round 1
	int round = 1;
	int numbOfCat = numberOfCategories(f);
	//a list to determin who will commance 3 for has already start
	int hasStarted[] = {0, 1, 2};
	printMiddleLine(0, 1);
	initSeedRandom();
	while (round <= 3)
	{
		cleanupBuffer(useranswers);
		sprintf(useranswers, " We are now starting with round %d ", round);
		ConsolPrint(useranswers, 0, 0, 1, NULL);
		puts("");
		int RoundWon = 0;

		while(check == 0){
			randomCategories = randomInt(numbOfCat);
			for(int i = 0; i < size; i++){
				if((randomCategories == checkRedundancy[i])){
					i = size;
				}else if((randomCategories != checkRedundancy[i]) && (checkRedundancy[i] == 0)){
					checkRedundancy[i] = randomCategories;
					i = size;
					check = 1;
				}
			}
		}
		check = 0;



		f = fopen("sentences.txt", "r");
		char *Categorie = searchCategory(f, randomCategories);

		if (Categorie == NULL)
		{
			perror("Could not malloc the string");
			exit(1);
		}
		//puts(Categorie); 			//debugging options

		f = fopen("sentences.txt", "r");

		int randomQuestion = randomInt(sentencePerCategories(f, Categorie));
		int commance = 3;
		int PlayerTurn = 0;

		f = fopen("sentences.txt", "r");

		char *noneVisibleField = nonVisibleField(f, randomCategories, randomQuestion);

		//puts("");					//debugging options
		//puts(noneVisibleField);	//debugging options
		//puts(""); 				//debugging options
		char *pField = playerField(noneVisibleField);
		

		while (!RoundWon)
		{
			//select the first player to play
			while (commance == 3)
			{
				if (round == 3 && players == 2)
				{
					commance = randomInt(players) % players;
					PlayerTurn = commance;
					break;
				}
				int tmpcommance = randomInt(players) % players;
				if (hasStarted[tmpcommance] != 3)
				{
					commance = hasStarted[tmpcommance];
					hasStarted[tmpcommance] = 3;
					PlayerTurn = commance;
				}
			}
			if (players == 3)
			{
				printPlayerInfoBoxTurnPlayer(playerList[0], playerList[1], playerList[2], PlayerTurn, players);
			}
			else if (players == 2)
			{
				printPlayerInfoBoxTurnPlayer(playerList[0], playerList[1], NULL, PlayerTurn, players);
			}
			char *WheelOutput = spinTheWheel(Wheel);

			//Extra Turn output
			if (!strncmp(WheelOutput, "Extra Turn", 11))
			{
				ConsolPrint("Enjoy your extra Turn.", 32, 0, 1, NULL);
				puts("");
				//wil redo the loop  and spin the wheel again
			}
			//Bankrupt output
			else if (!strncmp(WheelOutput, "Bankrupt", 9))
			{

				//The current player will  not play and he will  lose all his money
				bankrupt(playerList[PlayerTurn]);
				PlayerTurn = nextPlayer(players, PlayerTurn);
			}
			//Lose a Turn output
			else if (!strncmp(WheelOutput, "Lose a Turn", 12))
			{
				PlayerTurn = nextPlayer(players, PlayerTurn);
			}
			else
			{

				//The strtol will read up to the $
				int amount = (int)strtol(&WheelOutput[0], NULL, 10);
				ConsolPrint("Press 1 if you want to guess a char.", 0, 0, 1, NULL);
				puts("");
				ConsolPrint("Press 2 if you want to guess a sentence.", 0, 0, 1, NULL);
				puts("");
				char answer = getchar();
				flush();

				deleteUserInput();
				deleteUserInput();
				deleteUserInput();

				while (answer != '1' && answer != '2')
				{
					ConsolPrint("Please only enter 1 or 2", 31, 1, 1, NULL);
					puts("");
					answer = getchar();
					flush();
					deleteUserInput();
					deleteUserInput();
				}
				//Wants to give a char
				if (answer == '1')
				{

					printVisibleOutPut(pField, Categorie);
					printMiddleLine(0, 1);
					ConsolPrint("Please give us your character", 0, 1, 1, NULL);
					puts("");
					printMiddleLine(0, 1);

					//check if alpha

					answer = getchar();
					flush();
					deleteUserInput();
					while (!(isalpha(answer)))
					{
						ConsolPrint("Please only enter alphabetics characters", 31, 1, 1, NULL);
						puts("");

						answer = getchar();
						flush();
						deleteUserInput();
						deleteUserInput();
					}

					while (checkChar(answer, pField))
					{
						ConsolPrint("You already gave us that letter  please give us another alphabetic char", 31, 1, 1, NULL);
						puts("");

						answer = getchar();
						flush();
						deleteUserInput();
						deleteUserInput();
						
					}
					//the gues is right
					if (guessChar(playerList[PlayerTurn], answer, noneVisibleField, pField, amount))
					{
						printVisibleOutPut(pField, Categorie);
					}
					//the guess is wrong
					else
					{
						PlayerTurn = nextPlayer(players, PlayerTurn);
						printWronganswer();
					}
				}
				//Want to give a sentence
				else if (answer == '2')
				{
					printVisibleOutPut(pField, Categorie);
					printMiddleLine(0, 1);
					ConsolPrint("Please give us the full sentece.", 0, 1, 1, NULL);
					puts("");
					//checks  the  userInput
					int wrong = 1;

					while (wrong)
					{

						fgets(useranswers, useranswerMax, stdin);

						deleteUserInput();
						wrong = 1;
						for (int i = 0; i < strlen(useranswers); i++)
						{
							if (strlen(useranswers) - 1 == i)
							{
								wrong = 0;
								break;
							}
							else if (!((isalpha(useranswers[i]) || useranswers[i] == '\'' || useranswers[i] == ' ' || useranswers[i] == ',')))
							{

								printf("%s", useranswers);
								wrong = 1;
								char *mallocedstring = malloc(sizeof(char) * 60);
								char intermediatesave[] = "Please only enter alphabetics or ' or , or space characters";
								strncpy(mallocedstring, intermediatesave, 60);
								ConsolPrint(mallocedstring, 31, 1, 1, NULL);
								free(mallocedstring);
								break;
							}
						}
					}
					//checks if the sentce guessed is right
					if (guessSentence(useranswers, noneVisibleField))
					{ //finish the round
						cleanupBuffer(useranswers);
						sprintf(useranswers, "Congrats %s : You have won round %d ", playerList[PlayerTurn]->name, round);
						ConsolPrint(useranswers, 32, 1, 1, NULL);
						puts("");
						RoundWon = 1;
						printMiddleLine(0, 1);
					}

					else
					{ //wrong sentence the game continues
						PlayerTurn = nextPlayer(players, PlayerTurn);
						printWronganswer();
					}
					cleanupBuffer(useranswers);
				}
			}
		}
		//freeing up everything that has bee allocated
		round += 1;
		free(Categorie);
		free(noneVisibleField);
		free(pField);
	}
	//animation for the winner
	int winner = 0;
	if (players == 2)
	{
		winner = Winner(playerList[0]->money, playerList[1]->money, 0);
	}
	else
	{

		winner = Winner(playerList[0]->money, playerList[1]->money, playerList[2]->money);
	}

	printWinner(playerList[winner]->name);

	//continue to free up the rest
	freewheel(Wheel);
	puts("");
	printBottomLine();
	for (int i = 0; i < players; i++)
	{
		freePlayer(playerList[i]);
	}
	fclose(f);
	return 0;
}
