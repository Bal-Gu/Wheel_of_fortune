
main.o:main.c
	gcc -c main.c

PrintToConsol.o:PrintToConsol.c
	gcc -c PrintToConsol.c

randomWheel.o: randomWheel.c
	gcc -c randomWheel.c

player.o:player.c
	gcc -c player.c

wheel.o:wheel.c
	gcc -c wheel.c

textToFind.o : textToFind.c
	gcc -c textToFind.c

playerAction.o : playerAction.c
	gcc -c playerAction.c

GameLogic.o : GameLogic.c
	gcc -c GameLogic.c

main:  main.o PrintToConsol.o randomWheel.o player.o wheel.o textToFind.o playerAction.o GameLogic.o
	gcc -o main main.o PrintToConsol.o randomWheel.o player.o wheel.o textToFind.o playerAction.o GameLogic.o
	rm *.o