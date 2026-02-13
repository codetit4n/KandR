/*

Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.

*/

#include <stdio.h>

#define MAXLINE 1000  /* maximum input line length */
#define LOWERBOUND 80 /* minimum length of line to print */

int get_line(char line[], int maxline);

int main() {
	int len;	    /* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > LOWERBOUND) {
			printf("\nLine > 80 len: %s \n", line);
		}

	return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
	int c = 0, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	/* If line is longer, continue counting */
	while (c != EOF && c != '\n') {
		c = getchar();
		++i;
	}
	return i;
}
