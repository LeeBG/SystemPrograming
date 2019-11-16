/* atexitprocess.c */ 
/* atexit example */

#include <stdio.h> 
#include <stdlib.h>

void exitfunc1(void);
void exitfunc2(void);

int main(int argc, char **argv)
{
	atexit(exitfunc1);
	atexit(exitfunc2);
	printf("This is main function. \n");
	
	return 0;
}

void exitfunc1(void)
{
	printf("This is exit function 1.\n");
}

void exitfunc2(void)
{
	printf("This is exit funciton 2.\n");
}
