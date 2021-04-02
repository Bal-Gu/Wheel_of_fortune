#ifndef randomWheel
#define randomWheel
/**
 * Set the seed to the value set in this seed
 * 
 */
void initseed(long seed);
/**
 *Set a random Seed
 *  
 */
void initSeedRandom();

/**
 *Give back a random int between 1 and max
 *  
 * @max the maximum number. The number is included in it
 */
int randomInt(int max);

/**
 *Give a randomChar for the animation
 *  
 */
char randomChar();
#endif
