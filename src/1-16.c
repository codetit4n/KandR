/*

Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the
length of arbitrary long input lines, and as much as possible of the text.

*/

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main() {
	int len;	       /* current line length */
	int max;	       /* maximum length seen so far */
	char line[MAXLINE];    /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}

	putchar('\n');
	if (max > 0) {
		printf("Longest line length: %d\n", max);
		printf("Text:\n%s", longest);
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
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
