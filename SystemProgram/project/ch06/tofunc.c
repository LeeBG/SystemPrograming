/*
* 6장 기본 함수
* 파일이름: tofunc.c
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main (void) /*소문자·대문자 변환*/
{
	int i;
	char s[20], t[20];
	printf("string ? ");

	scanf("%s", s);

	for (i=0;i<=strlen(s);i++){
		if (isupper(s[i]))
			t[i]=tolower(s[i]);
		else if (islower(s[i]))
			t[i]=toupper(s[i]);
		else
			t[i]=s[i];
	}
	printf("%s ----> %s\n", s, t);
}
