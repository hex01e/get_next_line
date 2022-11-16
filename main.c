#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int main(int argc, char  *argv[])
{
	int fd = open("tt",O_RDWR, 0644);

	printf("%s", get_next_line(fd));
	close(fd);
	fd =  open("tt",O_RDWR, 0644);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return 0;
}

