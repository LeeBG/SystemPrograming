#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	DIR   *dp;
	struct  dirent   *dirp;
	char   *ptr;
	struct  stat   buf;
	 
	if (argc != 2) {
		printf("usage: ls directory name\n");
		return -1;
	}

	if ((dp = opendir(argv[1])) == NULL) {

		printf("Can't open %s\n", argv[1]);
		return -1;
	}

	while ((dirp = readdir(dp)) != NULL) {

		printf("%s: ", dirp->d_name);

		if (lstat(dirp->d_name, &buf) < 0) {

			printf("lstat error\n");
			continue;
		}
	 
		if (S_ISREG(buf.st_mode))
			ptr = "Regular";
		else if (S_ISDIR(buf.st_mode))
			ptr = "Directory";
		else if (S_ISCHR(buf.st_mode))
			ptr = "Character Speical";
		else if (S_ISBLK(buf.st_mode))
			ptr = "Block Special";
		else if (S_ISFIFO(buf.st_mode))
			ptr = "Fifo";
		else if (S_ISLNK(buf.st_mode))
			ptr = "Symbolic Link";
		else if (S_ISSOCK(buf.st_mode))

			ptr = "Socket";
		else
			ptr = "Unkown Mode";

		printf("%s\n", ptr);

	}
	closedir(dp);
	return 0;

}

