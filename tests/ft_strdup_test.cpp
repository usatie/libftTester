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

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_strdup\t: ")

	char * s = ft_strdup((char*)"coucou");
	/* 1 */ check(!strcmp(s, "coucou"));
	/* 2 */ mcheck(s, strlen("coucou") + 1); free(s); showLeaks();
	
	s = ft_strdup((char*)"");
	/* 3 */ check(!strcmp(s, ""));
	/* 4 */ mcheck(s, 1); free(s); showLeaks();

	s = ft_strdup((char*)"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	/* 5 */ check(!strcmp(s, "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	/* 6 */ mcheck(s, 10 + 26 + 26 + 1); free(s); showLeaks();
	write(1, "\n", 1);
	return (0);
}
