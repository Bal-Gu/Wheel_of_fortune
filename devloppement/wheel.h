#ifndef wheel
#define wheel

/**
 * 
 *Get's the wheelfield of a 2d array  (25 strings) 
 *
 * @Wheel is used for a 2d array of 25 strings
 * @fieldNum the number of the field we want
 * 
 */
char *getField(char **Wheel, int fieldNum);

/**
 * Initate the wheel and mallocs space
 */
char **initwheel();

/**
 * 
 * free the space malloced by the wheel
 * 
 * @wheel the 2d wheel array that contains the 25 strings
 * 
 */
void freewheel(char **wheel);

#endif
