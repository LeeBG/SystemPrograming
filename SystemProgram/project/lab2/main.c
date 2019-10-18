#include <stdio.h>
#include <stdlib.h>
#include "testlib.h"

int main()
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
}
