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
	title("ft_strchr\t: ")
	char s[] = "tripouill\n€";
	/* 1 */ check(ft_strchr(s, 't') == s); showLeaks();
	/* 2 */ check(ft_strchr(s, 'l') == s + 7); showLeaks();
	/* 3 */ check(ft_strchr(s, 'z') == 0); showLeaks();
	/* 4 */ check(ft_strchr(s, 0) == s + strlen(s)); showLeaks();
	/* 5 */ check(ft_strchr(s, 't' + 256) == s); showLeaks();
	/* 6 */ check(ft_strchr(s, 't') == s + 0); showLeaks();
	/* 7 */ check(ft_strchr(s, 'r') == s + 1); showLeaks();
	/* 8 */ check(ft_strchr(s, 'i') == s + 2); showLeaks();
	/* 9 */ check(ft_strchr(s, 'p') == s + 3); showLeaks();
	/* 10 */ check(ft_strchr(s, 'o') == s + 4); showLeaks();
	/* 11 */ check(ft_strchr(s, 'u') == s + 5); showLeaks();
	/* 12 */ check(ft_strchr(s, 'i') == s + 2); showLeaks();
	/* 13 */ check(ft_strchr(s, 'l') == s + 7); showLeaks();
	/* 14 */ check(ft_strchr(s, 'l') == s + 7); showLeaks();
	/* 15 */ check(ft_strchr(s, '\n') == s + 9); showLeaks();
	/* 16 */ check(ft_strchr(s, "€"[0]) == s + 10); showLeaks();
	/* 17 */ check(ft_strchr(s, 'z') == NULL); showLeaks();
	write(1, "\n", 1);
	return (0);
}
