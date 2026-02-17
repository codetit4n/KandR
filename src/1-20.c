/*

Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?

*/

#include <stdio.h>

#define TAB_STOP 4

int main() {

	int c = 0, col = 0;

	putchar('\n');

	while ((c = getchar()) != EOF) {

		if (c == '\t') {
			/* calculate number of spaces to next tab stop
			next multiple of TAB_STOP - current column */
			int spaces = TAB_STOP - (col % TAB_STOP);
			int i = 0;

			for (; i < spaces; i++) {
				putchar(' ');
			}

			col += spaces;
		} else {
			putchar(c);

			/* reset column on newline, otherwise increment */
			if (c == '\n')
				c = 0;
			else
				++col;
		}
	}

	return 0;
}
