libtest.a : sum.o sub.o mult.o dev.o
	ar rcs libtest.a sum.o sub.o mult.o dev.o

sum.o : sum.c
	gcc -c -o sum.o sum.c

sub.o : sub.c
	gcc -c -o sub.o sub.c

mult.o : mult.c
	gcc -c -o mult.o mult.c

dev.o : dev.c
	gcc -c -o dev.o dev.c

clean :
	rm *.o foobar

