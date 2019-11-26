#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>
#include <pthread.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


#define MAXBUF 1024

//메시지큐에 저장할 값의 변수

typedef struct{

	long data_type;
	char data[MAXBUF];

}t_data;

//디스크럽터와 클라이언트들의 데이터 타입의 숫자를 지정
typedef struct{
	int number;
	int fd;
}tide;

//동기화

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *snd_message(void *arg);
void *rcv_message(void *arg);

int main(int argc, char *argv[]){

	pthread_t snd_thread,rcv_thread;
	int fd;
	void *thread_result;
	tide num;
	
	//메시지 큐를 작성
	num.fd = msgget((key_t)12345, IPC_CREAT|0666);

	if(argc!=2){
		printf("error \n");
		exit(1);
	}

	num.number = atoi(argv[1]);

	//값을 주고, 받는 쓰레드 생성
	pthread_create(&snd_thread,NULL,snd_message,&num);
	pthread_create(&rcv_thread,NULL,rcv_message,&num);
	pthread_join(rcv_thread,&thread_result);
	pthread_join(snd_thread,&thread_result);
	return 0;
}


void *snd_message(void *arg){
	tide* num;
	num = (tide*)arg;
	pthread_t tid;
	char buf[MAXBUF];
	char buff[MAXBUF];
	t_data datas;
	int c;
	
	while(1){
		//입력받기
		memset(buf,'\0',MAXBUF);
		memset(buff,'\0',MAXBUF);
		scanf("%d",&c);
		getchar();
		fgets(buf,MAXBUF,stdin);
		*(buf+(strlen(buf)-1))='\0';

		datas.data_type = c;
		sprintf(buff,"[%d send] : %s\n",(*num).number,buf);
		strcpy(datas.data,buff);

		//메시지 큐에 입려되는 값을 동기화
		pthread_mutex_lock(&mutex);
		msgsnd((*num).fd,&datas,sizeof(datas)-sizeof(long),0);
		pthread_mutex_unlock(&mutex);				
	}
}

//메시지 큐에 해당 data_type 얻는다
void *rcv_message(void *arg){
	tide* num;
	num = (tide*)arg;
	char buf[MAXBUF];
	int i;
	t_data datas;

	while(1){
		if((msgrcv((*num).fd,&datas,sizeof(datas)-sizeof(long),(*num).number,0))>0){
			prnitf("%s\n",datas.data);
		}	
	}	
}
