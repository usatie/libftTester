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
	title("ft_calloc\t: ")

	void * p = ft_calloc(4, 8);
	char e[] = {0, 0, 0, 0, 
		0, 0, 0, 0, 
		0, 0, 0, 0, 
		0, 0, 0, 0, 
		0, 0, 0, 0, 
		0, 0, 0, 0, 
		0, 0, 0, 0, 
		0, 0, 0, 0};
	/* 1 */ check(!memcmp(p, e, 32));
	/* 2 */ mcheck(p, 32); free(p); showLeaks();
	/* 3 */ check(ft_calloc(SIZE_MAX, SIZE_MAX) == NULL);
	p = ft_calloc(0, 8);
	/* 4 */ check(!memcmp(p, e, 0));
	/* 5 */mcheck(p, 0); free(p); showLeaks();
	p = ft_calloc(8, 0);
	/* 6 */ check(!memcmp(p, e, 0));
	/* 7 */ mcheck(p, 0); free(p); showLeaks();
	p = ft_calloc(0, 0);
	/* 8 */ check(!memcmp(p, e, 0));
	/* 9 */ mcheck(p, 0); free(p); showLeaks();
	write(1, "\n", 1);
	return (0);
}
