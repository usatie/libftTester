extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "leaks.hpp"
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_putendl_fd\t: ")

	int fd = open("tripouille", O_RDWR | O_CREAT);
	ft_putendl_fd((char*)"42", fd);
	lseek(fd, SEEK_SET, 0);
	char s[10] = {0}; read(fd, s, 3);
	char r1[10] = {'4', '2', '\n'};
	bzero(r1 + 3, 7);
	/* 1 */ check(!strcmp(s, "42\n")); showLeaks();
	/* 2 */ check(!memcmp(s, r1, 10)); showLeaks();
	ft_putendl_fd((char*)"abcde", fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 9);
	/* 3 */ check(!strcmp(s, "42\nabcde\n")); showLeaks();
	lseek(fd, SEEK_SET, 0);
	ft_putendl_fd((char*)"abcde", fd);
	memset(s, 0, 10);
	read(fd, s, 3);
	/* 4 */ check(!strcmp(s, "de\n")); showLeaks();
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 6);
	/* 5 */ check(!strcmp(s, "abcde\n")); showLeaks();
	unlink("./tripouille");
	write(1, "\n", 1);
	return (0);
}
