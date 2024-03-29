/*
 * 5장 디버깅과 오류처리
 * 파일 이름 : errno_show.c
 */

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(int argc,char *argv[])
{
	FILE *f;
	if(argc <2)
	{
		printf("Usage : errno_show file_name\n");
		exit(1);
	}

	if ((f=fopen(argv[1],"r"))==NULL){
		printf("Cannot open a file \"%s\"... (errno:%d)\n",argv[1],errno);
		exit(1);
	}
	
	printf("Open a file \"%s\".\n",argv[1]);
	
	fclose(f);
}
