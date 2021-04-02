#ifndef playeraction
#define playeraction
#include "player.h"

int stringlen(char *str);

/**
*Print the Top line.
*/
void printTopLine();

/**
 * Prints the Bottom Line.
 */
void printBottomLine();

/**
 * used once at the start to greet the player.
 * 
 * @playerList the list of all the players
 * @amount the amount of players
 * 
 */
void printPlayerName(Player **playerList, int amount);

/**
*intersections should be printed evenly.
*int layer : 1 is for ├┼┤/ 2 is for ├┴┤/ 3 is for ├┬┤.
*int intersections = number of intersections. If no intersection, give 0.
*/
void printMiddleLine(int intersections, int layer);

/**
 *   Will be used as the prinf function with the given colors.
 *
 * @stringOut       the string that must be printed.
 * @color           ANSI color 30-36 0 for white.
 * @bold            bold printing.
 * @MustPrintLeft   boolean if the Left | has to be printed out.
 * @lengthToPrint   The length it has to print to. If unknow give NULL.
 */
void ConsolPrint(char *stringOut, int color, int bold, int MustPrintLeft, int *lengthToPrint);

/**
*		Will creat the wheel output.
*
*@p 	will be used as the string that has to be putted out.
*/
void randomOutput(char *p);

/**
 *   Prints in a box the information of the player and if it's his turn
 *
 * @p1     			Player 1.
 * @p2           	Player 2.
 * @p3            	Optional Player 3. If not present give NULL.
 * @PlayersTurn     The Player that will currently be playing.
 * @amount			How many players are in the game.
 */
void printPlayerInfoBoxTurnPlayer(Player *p1, Player *p2, Player *p3, int PlayersTurn, int amount);

/**
*Prints a random  different wrong answer.
*/
void printWronganswer();

/**
 *   Print the question then the visible playerField.
 *
 * @PlayerView     	The string of what players are seeing currently.
 * @Question        The string containing the Question/Hint.
 */
void printVisibleOutPut(char *PlayerView, char *Question);

/**
*		Will do an animation of 30 second of the winner playing.
*
* @name 	The name of the Winner.
*/
void printWinner(char *name);

#endif
