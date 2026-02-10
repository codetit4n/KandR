/*

Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.

*/

#include <stdio.h>

int main() {
	int c = 0, found = 0;
	printf("Enter some text or Press Ctrl+D to exit\n");
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (!found) {
				putchar(c);
				found = 1;
			}
		} else {
			putchar(c);
			found = 0;
		}
	}

	return 0;
}
