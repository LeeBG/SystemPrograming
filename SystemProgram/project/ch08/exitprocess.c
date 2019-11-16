

/* exitprocess.c */ 
/* exit example */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int exit_status;
	
	printf("enter exit status: ");
	scanf("%d",&exit_status);
	exit(exit_status);
	return 0;
}

