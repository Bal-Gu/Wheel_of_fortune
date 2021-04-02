#include "textToFind.h"
#include "PrintToConsol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//function to open specific files in reader mode
FILE *readFile(char *path)
{
	int c;
	FILE *f;
	f = fopen(path, "r");
	if (f == NULL)
	{
		char *sentence = "The path doesn't exist.";
		ConsolPrint(sentence, 31, 1, 1, NULL);
		return 0;
	}
	return f;
}
//Reveals every digit that is not in the Alphabet
void revealNonAlphaAndNonDigit(char *nonVisibleField, char *playerField)
{

	for (int i = 0; i < strlen(nonVisibleField); i++)
	{
		if ((nonVisibleField[i] >= 'A' && nonVisibleField[i] <= 'Z') || (nonVisibleField[i] >= 'a' && nonVisibleField[i] <= 'z'))
		{
			playerField[i] = '-';
		}
		else
		{
			playerField[i] = nonVisibleField[i];
		}
	}
}
//Count number of Category by parsing the File, adding 1 for different category
int numberOfCategories(FILE *f)
{
    //each character is saved in arr using c
	int c, i = 0, y = 0, z = 2, ret, count = 0;
	char arr[200][200];

	while ((c = fgetc(f)) != EOF)
	{
        //z refers to different steps of the algorithm
		if (c == '\n')
		{
			y = 0;
			z = 1;
			ret = strcmp(arr[i], arr[i - 1]);
			if (ret == 0)
			{
				arr[i][0] = '\0';
			}
			else if (ret != 0)
			{
				count++;
				i++;
			}
		}
		//We will only save category in arr to compare them
		else if (c == ':')
		{
			z = 0;
			arr[i][y] = '\0';
		}
		if (z == 2)
		{
			arr[i][y] = c;
			y++;
		}
		else if (z == 1)
		{
			z++;
		}
	}
	fclose(f);

	return count;
}
//Count number of sentences for a given char that is the category
int sentencePerCategories(FILE *f, char *stringToComp)
{
	int ret = 0;
	int count = 0;
	int c = 0;
	int i = 0;
	int y = 0;
	int z = 2;
	char arr[200][200];
	while ((c = fgetc(f)) != EOF)
	{
	    //z refers to different steps of the algorithm
		if (c == '\n')
		{
			y = 0;
			z = 1;
			//function will parse the txt file to see how many times the category is referred, adding 1 when it's the case
			ret = strcmp(arr[i], stringToComp);
			if (ret == 0)
			{
				count++;
			}
			i++;
		}
		else if (c == ':')
		{
			z = 0;
			arr[i][y] = '\0';
		}
		if (z == 2)
		{
			arr[i][y] = c;
			y++;
		}
		else if (z == 1)
		{
			z++;
		}
	}
	fclose(f);

	return count;
}
//Defines the playerField using the nonVisibleField, it reveals characters that aren't alphabet and defines the size
char *playerField(char *nonVisibleField)
{
	int a = 1 + stringlen(nonVisibleField);

	char *playerField = malloc(a * sizeof(char));
	for (int i = 0; i < a; i++)
	{
		playerField[i] = '\0';
	}
	revealNonAlphaAndNonDigit(nonVisibleField, playerField);
	return playerField;
}
//Parse the txt file to give the category in char type using an integer
char *searchCategory(FILE *f, int category)
{
	char c;
	int i = 1, y = 0, z = 2, count = 0, check = 1;
	int ret = 1;

	char arr[200][200];
	char *bank = malloc(200 * sizeof(char));

	for (int k = 0; k < 50; k++)
	{
		for (int j = 0; j < 50; j++)
		{
			arr[i][j] = '\0';
		}
	}
	for (int k = 0; k < 50; k++)
	{
		bank[i] = '\0';
	}

	while ((c = (char)fgetc(f)) != EOF && check == 1)
	{
        //z refers to different steps of the algorithm
		if (c == '\n')
		{
			y = 0;
			z = 1;
			if (i != 0)
			{
				for (int k = 0; k < strlen(arr[i - 1]); k++)
				{
					if (arr[i - 1][k] != arr[i][k])
					{
					    //ret unlocks the second part of the if statement that copies the string into the bank
						ret = 1;
						break;
					}
					ret = 0;
				}
			}

			if (ret != 0)
			{
				i++;
				if (i == category + 1)
				{
					strcpy(bank, arr[i - 1]);
					check = 0;
				}
			}
		}
		else if (c == ':')
		{
			z = 0;
			arr[i][y] = '\0';
		}
		if (z == 2)
		{
			arr[i][y] = c;
			y++;
			arr[i][y] = '\0';
		}
		else if (z == 1)
		{
			z++;
		}
	}
	fclose(f);

	return bank;
}
//Put the sentence to find in nonVisibleField with category and sentencenumber as parameter
char *nonVisibleField(FILE *f, int Categorie, int SentenceNum)
{
    //check refers to a key that will unlock parts of the algorithm, firstly it will only save category in arr to campare them, then it will save sentences 
	int c, x = 0, i = 0, y = 0, z = 2, ret, count = 0, check = 0, timer = 0;
	char arr[200][200];
	char *bank;

	while ((c = fgetc(f)) != EOF && check != 3)
	{
		if (check == 2)
		{
			x++;
		}
		//z refers to different steps of the algorithm
		if (c == '\n')
		{
			y = 0;
			z = 1;
			if (check == 2)
			{
				bank = malloc(x * sizeof(char));
				strcpy(bank, arr[i]);
				check = 3;
			}
		}
		else if (c == ':')
		{
		    //timer is needed to not save ":" in the sentences
			timer = 1;
			arr[i][y] = '\0';
			ret = strcmp(arr[i], arr[i - 1]);
			if ((ret == 0) && (check != 1))
			{
				arr[i][0] = '\0';
			}
			else if (ret != 0 || check == 1)
			{
				i++;
				if (i == Categorie && check != 1)
				{
					check = 1;
				}
				if (check == 1)
				{
					if (count == 0)
					{
						i--;
					}
					count++;
					if (count == SentenceNum)
					{
						arr[i][0] = '\0';
						y = 0;
						check = 2;
					}
				}
			}
			if (check != 2)
			{
				z = 0;
			}
		}
		if (z == 2)
		{
			if (timer == 0 || check == 0)
			{
				arr[i][y] = c;
				y++;
				arr[i][y] = '\0';
			}
			else if (timer == 1)
			{
				timer = 0;
			}
		}
		else if (z == 1)
		{
			z++;
		}
	}
	fclose(f);
	return bank;
}
//Verify if a guessed char is in nonVisibleField, if yes it will save the char in playerField and return the number of times the character is in the sentence
int containsChar(char *nonVisibleField, char *playerField, char guessed)
{
	int len = strlen(nonVisibleField), check = 0;

	for (int i = 0; i < len; i++)
	{
		if (toupper(nonVisibleField[i]) == toupper(guessed))
		{
			playerField[i] = nonVisibleField[i];
			check += 1;
		}
	}
	return check;
}
