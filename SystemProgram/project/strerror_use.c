/*
 * 5장 디버깅과 오류처리 
 * 파일 이름 : strerror_use.c
 */

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main(int argc,char *argv[])
{
	FILE *f;

	if(argc<2){
		printf("Usage : strerror_use nofilename\n");
		exit(1);
	}
	
	if((f=fopen(argv[1], "r")) == NULL){
		printf("Cannot open a file \"%s\"... (error message: %s)\n",argv[1],strerror(errno));
		exit(1);
	}
	
	printf("Open a file \"%s\".\n",argv[1]);
	
	fclose(f);
}
