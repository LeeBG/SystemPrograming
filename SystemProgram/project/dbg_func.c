/*
 * 5장 디버깅과 오류처리
 * 파일이름 : dbg_func.c
 */
#include <stdio.h>
#include <stdlib.h>
int my_sum(int k);
int my_sum(int k)
{
	int i;
	int sum=0;
	
	for(i=0; i<=k; i++){
		sum +=1;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int i;
	int k;
	int sum = 0;

	if(argc < 2){
		fprintf(stderr, "Usage: dbg_func 3 \n");
		exit(1);
	}

	k = atoi(argv[1]);
	sum = my_sum(k);
	
	printf("sum = %d\n", sum);
}
