/*
 * 5장 디버깅과 오류처리
 * 파일이름 : dbg_watch.c
 */ 

#include <stdio.h>

int main()
{
	int i;
	int sum=0;

	for(i=0;i<3;i++)
		sum +=1;

	printf("sum = %d\n",sum);
}
