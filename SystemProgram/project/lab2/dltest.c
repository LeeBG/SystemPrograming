/* dltest.c */
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main()
{
	void *handle;
	int (*sum)(int, int), (*sub)(int, int);
	int (*mult)(int, int), (*dev)(int, int);
	char *error;

	handle = dlopen ("./lib/libtest.so", RTLD_LAZY);

	if (!handle) {
		fputs (dlerror(), stderr);
		exit(1);
	}
	sum = dlsym(handle, "sum"); 
	if ((error = dlerror()) != NULL) { 
		fprintf (stderr, "%s", error); 
		exit(1); 
	}
	sub = dlsym(handle, "sub");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	mult = dlsym(handle, "mult"); 
	if ((error = dlerror()) != NULL) { 
		fprintf (stderr, "%s", error); 
		exit(1); 
	}
	dev = dlsym(handle, "dev");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	printf("SUM(1,2)=%d\n", (*sum)(1,2));
	printf("SUB(1,2)=%d\n", (*sub)(1,2));
	printf("MULT(1,2)=%d\n", (*mult)(1,2));
	printf("DEV(1,2)=%d\n", (*dev)(1,2));
	dlclose(handle);
}
