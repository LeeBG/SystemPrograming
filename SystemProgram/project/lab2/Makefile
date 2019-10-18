foobar : main2.o foo.o bar.o
	gcc -o foobar main2.o foo.o bar.o

main2.o : main2.c
	gcc -c -o main2.o main2.c

foo.o : foo.c
	gcc -c -o foo.o foo.c

bar.o : bar.c
	gcc -c -o bar.o bar.c

main.o : main.c
	gcc -I./lib -L./lib main.c -ltest

clean :
	rm *.o foobar

