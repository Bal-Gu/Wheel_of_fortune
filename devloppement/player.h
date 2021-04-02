#ifndef player
#define player

//Put the score,money,name,playerPostion,color

/**
 * 
 * The player and his attributes
 * 
 * @money            The amount of money the player has
 * @name             The name of the player
 * @CanPlay          Can the player play
 * @playerPosition   The turn of the player (p1|p2|p3)
 * @color            a color between 30-36 and 0
 */

typedef struct
{
	int money;
	char *name;
	int canPlay;
	int playerPosition;
	int color;

} Player;

/**
 * 
 * initate the Player with default value
 * 
 * @NAME            The name of the player
 * @Position   		The turn of the player (p1|p2|p3)
 * @color           A color of 30-36 or 0 (ANSI-color)
 * 
 */
Player *initPlayer(char *NAME, int Position, int color);

/**
 * 
 * free the structur that has been malloced from the player
 * 
 */

void freePlayer(Player *p);

#endif
