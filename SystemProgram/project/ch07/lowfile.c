/* 초보적인 프로그램 예 */
/* 이 헤더 파일들은 아래에서 논의한다 */
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd;
	ssize_t nread;
	char buf[1024];

	/* 파일 "data"를 읽기 위해 개방한다 */
	fd = open("data", O_RDONLY);

	/* 데이터를 읽어들인다 */
	nread = read(fd, buf, 1024);

	/* 파일을 폐쇄한다 */
	close(fd);
}
