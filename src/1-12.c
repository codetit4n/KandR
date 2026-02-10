/*

Exercise 1-12. Write a program that prints its input one word per line.

*/

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

int main() {
	int c = 0, state = 0;
	printf("Enter some text or Press Ctrl+D to exit\n");
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				putchar('\n');
				state = OUT;
			}
		} else {
			putchar(c);
			state = IN;
		}
	}

	return 0;
}
