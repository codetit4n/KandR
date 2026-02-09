/*

Exercise 1-8. Write a program to count blanks, tabs, and newlines.

*/

#include <stdio.h>

int main() {
	int c, nl, b, t;
	nl = b = t = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		if (c == ' ')
			++b;
		if (c == '\t')
			++t;
	}

	printf("new lines: %d\n", nl);
	printf("blanks: %d\n", b);
	printf("tabs: %d\n", t);

	return 0;
}
