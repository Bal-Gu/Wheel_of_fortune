#ifndef textToFind
#define textToFind
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * gives the number of numberOfCategories
 * 
 * @f the file that has to be imported
 */
int numberOfCategories(FILE *f);

/**
 * gives the number of setneces that matches the string
 *  
 * @f               the file that has to be imported
 * @stringToComp    tringToComp the string of the categorie
 */
int sentencePerCategories(FILE *f, char *stringToComp);

/**
 * readFile and gives it back
 * @path the path to the file
 */
FILE *readFile(char *path);

/**
 * 
 * Makes an array of what the player will see
 * @nonVisibleField the string of the final answer
 */
char *playerField(char *nonVisibleField);

/**
 * This will reveal every non alpha or digit that the user will see 
 * 
 * @nonVisibleField     the string of the final answer
 * @playerField         what the player will see
 */
void revealNonAlphaAndNonDigit(char *nonVisibleField, char *playerField);

/**
 * return the category in string from integer input
 * 
 * @f         The file that has to be imported
 * @category  The number of the categorie
 */
char *searchCategory(FILE *f, int category);

/**
 * should return the non visibleField
 * @f           The file that has to be imported
 * @category    The number of the categorie
 * @SentenceNum The number of the sentence
 * 
 */
char *nonVisibleField(FILE *f, int Categorie, int SentenceNum);

/**
 * boolean 0 doesn't contain that char. 1 does contain the char.
 * sets also the char to the playerField.
 * 
 * @nonVisibleField     the string of the final answer
 * @playerField         what the player will see
 * @guessed             The char that the user guessed
 * 
 */
int containsChar(char *nonVisibleField, char *playerField, char guessed);

#endif
