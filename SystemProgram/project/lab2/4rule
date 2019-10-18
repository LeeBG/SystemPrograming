#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum(int a,int b);
int dev(int a,int b);
int mult(int a,int b);
int sub(int a,int b);

int sum(int a,int b){
	int result = 0;
	result = a+b;
	return result;
}
int dev(int a,int b){
	int result = 0;
	result = a/b;
	return result;
}
int mult(int a,int b){
	int result = 1;
	result = a*b;
	return result;
}
int sub(int a,int b){
	int result = 0;
	result = abs(a-b);
	return result;
}

int main(int argc, char **argv)
{
	int a,b,menu;
	int result=0;
	char sign;
	
	printf("숫자 둘을 입력하세요 : ");
	scanf("%d %d",&a,&b);
	
	printf("[1.덧셈 2.뺄셈 3.곱셈 4.나눗셈] 중 선택하세요 :  ");
	
	scanf("%d",&menu);
	switch(menu){
		case 1:
			sign = '+';
			result =  sum(a,b);
			break;
		case 2:
			sign = '-';
			result =  sub(a,b);
			break;
		case 3:
			sign = 'x';
			result =  mult(a,b);
			break;
		case 4:
			sign = '/';
			result =  dev(a,b);
			break;
		default:
			printf("잘못된 입력!!\n");
			break;				
		}
		printf("%d %c %d = %d",a,sign,b,result);
	
	return 0;
}

