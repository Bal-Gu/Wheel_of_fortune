#ifndef playerAction
#define playerAction

/**
 * The player spins the Wheel
 * 
 * @Wheel the 2d array of 25 strings representing the wheelfields
 */
char *spinTheWheel(char **Wheel);

/**
 * checking if the player already give this char
 * It will also check if the user has given an alphabetic char
 * 
 * @c               The char that has  to be checked
 * @nonVisibleField  The string containing the answer
 */
int checkChar(char c, char *nonVisible);

/**
 * Determins if the Char is a voyel or a constant go to the according methode (return a boolean)
 * 
 * @p               The player that has played now
 * @c               The char this player tested
 * @nonVisibleField The string containing the answer
 * @VisibleField    What the player will see
 * @amount          The amount the wheel putted out
 */
int guessChar(Player *p, char c, char *nonVisibleField, char *VisibleField, int amount);

/**
 * Check if the user gave a Vowel if yes 3 outputs are possible
 * 0: isn't a Vowel
 * 1: is a Vowel
 * 2: The user is to poor to buy something
 * 
 * @c           The char that the user gave
 * @MoneyAmount The amount of money the user has
 */
int checkVowel(char c, int MoneyAmount);

/**
 * boolean gives 0 if wrong sentence gives 1 if true sentence (case insensitiv)
 *
 * @sentence            The sentence that the user gave 
 * @nonVisibleField     The string that contains the answer
 */
int guessSentence(char *sentence, char *nonVisibleField);

#endif
