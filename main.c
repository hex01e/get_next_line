#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int main(int argc, char const *argv[])
{
	int fd = open("tt",O_RDWR, 0644);
	// printf("|%d|\n", fd);
	// printf("|%zd|", read(fd, o,1));
	// printf("%s\n",  o);
	// printf("|%zd|", read(fd, o,1));
	// printf("%s\n",  o);
	// printf("|%zd|", read(fd, o,1));
	// printf("%s\n",  o);
	// printf("|%zd|", read(fd, o,1));
	// printf("%s\n",  o);
	// printf("|%zd|", read(fd, o,1));
	// printf("%s\n",  o);
	// printf("|%zd|", read(fd, o,1));
	// printf("%s\n",  o);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return 0;
}

