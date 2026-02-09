/*

Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.

*/

#include <stdio.h>

int main() {

	int c; /* must be int as char type can't hold EOF */

	printf("Press Ctrl+D for EOF on Linux - should print 0(false) else 1(true)\n");
	c = (getchar() != EOF);
	printf("%d\n", c);

	return 0;
}
