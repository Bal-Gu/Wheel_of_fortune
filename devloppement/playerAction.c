#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "player.h"
#include "randomWheel.h"
#include "wheel.h"
#include "PrintToConsol.h"
#include "textToFind.h"
#include "playerAction.h"

//The player spins the Wheel
char *spinTheWheel(char **randomWheelName wheel)
{

	int fieldnumber = randomInt(24) % 24;

	char *field = getField(randomWheelName, fieldnumber);
	randomOutput(field);
	return field;
}

//checking if the player already give this char + isalpha

int checkChar(char c, char *Visible)
{

	int strlen = stringlen(Visible);
	if (!(isalpha(c)))
	{
		return 1;
	}

	for (int i = 0; i < strlen; i++)
	{
		if (tolower(Visible[i]) == tolower(c))
		{
			return 1;
		}
	}

	return 0;
}
//Determins if the Char is a voyel or a constant go to the according methode (return a boolean)
int guessChar(Player *p, char c, char *nonVisibleField, char *VisibleField, int amount)
{
	//will give the player another chance if he puts the message 2 times the same char in it.

	int VowelOutput = checkVowel(c, p->money);
	if (VowelOutput == 2)
	{
		return 0;
	}
	else if (VowelOutput == 1)
	{
		p->money -= 250;
		VowelOutput = containsChar(nonVisibleField, VisibleField, c);
	}
	else
	{
		VowelOutput = containsChar(nonVisibleField, VisibleField, c);
		p->money += (VowelOutput * amount);
	}

	return VowelOutput;
}

//check if the Consonant is in the textToFind if not get back to the userinput and end his turn + informe him.
//If it is true then reveal it to the user using the textToFind methode
int checkVowel(char c, int MoneyAmount)
{
	int check = 0;
	char vowel[] = "AEIOUaeiou";

	for (int i = 0; i < strlen(vowel); i++)
	{

		if (c == vowel[i])
		{
			check = 1;
		}
	}

	if (MoneyAmount < 250 && check == 1)
	{
		ConsolPrint("You have not enough money", 31, 1, 1, NULL);
		puts("");
		check = 2;
	}

	return check;
}

int guessSentence(char *sentence, char *nonVisibleField)
{

	for (int i = 0; i < strlen(nonVisibleField); i++)
	{
		if (tolower(sentence[i]) != tolower(nonVisibleField[i]))
		{
			return 0;
		}
	}
	return 1;
}