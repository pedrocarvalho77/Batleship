static: logo.h logo.c point.h point.c cell.h cell.c quadtree.h quadtree.c boat.h boat.c player.h player.c setup.h setup.c game.h game.c
	gcc -Wall -c -std=c99 logo.c
	gcc -Wall -c -std=c99 point.c
	gcc -Wall -c -std=c99 boat.c
	gcc -Wall -c -std=c99 cell.c
	gcc -Wall -c -std=c99 quadtree.c
	gcc -Wall -c -std=c99 player.c
	gcc -Wall -c -std=c99 setup.c
	gcc -Wall -c -std=c99 game.c
	ar -rc libgame.a logo.o point.o boat.o cell.o quadtree.o player.o setup.o game.o
dynamic:

engine: engine.c libgame.a
	gcc -Wall -std=c99 engine.c -o engine -L. -lgame
	
clean:
	rm -f *.o