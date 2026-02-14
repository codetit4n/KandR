/*

Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines.

*/

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);

int main() {
	int len;	    /* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > 1) {
			printf("%s", line);
		}
	}

	return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {

	int c = 0;
	int i = 0;
	int last_blank = 0;

	while (i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
		if (c == ' ' || c == '\t')
			++last_blank;
		else
			last_blank = 0;

		s[i++] = c;
	}

	if (last_blank > 0)
		i -= last_blank;

	if (c == '\n' && i < lim - 1)
		s[i++] = '\n';

	s[i] = '\0';

	return i;
}
