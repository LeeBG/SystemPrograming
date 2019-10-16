/*
* 6장 기본 함수
* 파일이름: curtime.c
*/

#include <stdio.h>
#include <time.h>

int main() {
	time_t curtime;

	time(&curtime);
	printf("current time is %d\n", (int)curtime);
}
