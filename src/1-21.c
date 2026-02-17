/*

Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When
either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?

*/

#include <stdio.h>

#define TAB_STOP 4

/* entab */
int main() {

	int c = 0, col = 0, space_ctr = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++space_ctr;
		} else {
			/* convert accumulated spaces */
			while (space_ctr > 0) {
				/* calculates how many spaces are needed to reach the next tab stop
				 */
				int spaces_to_tab = TAB_STOP - (col % TAB_STOP);

				/* if enough spaces to reach the next tab stop, insert a tab
				 * character */
				if (space_ctr >= spaces_to_tab) {
					putchar('\t');
					col += spaces_to_tab;
					space_ctr -= spaces_to_tab;
				} else {
					putchar(' ');
					++col;
					--space_ctr;
				}
			}

			putchar(c);

			if (c == '\n')
				col = 0;
			/* moves cursor to the next tab stop if a tab character is encountered */
			else if (c == '\t')
				col += TAB_STOP - (col % TAB_STOP);
			else
				++col;
		}
	}

	/* flush trailing spaces at EOF */
	while (space_ctr > 0) {
		int spaces_to_tab = TAB_STOP - (col % TAB_STOP);

		if (space_ctr >= spaces_to_tab) {
			putchar('\t');
			col += spaces_to_tab;
			space_ctr -= spaces_to_tab;
		} else {
			putchar(' ');
			++col;
			--space_ctr;
		}
	}

	return 0;
}
