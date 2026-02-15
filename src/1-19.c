/*

Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time.

*/

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

void reverse(char s[]);
int get_line(char line[], int maxline);

int main() {
	int len;	    /* current line length */
	char line[MAXLINE]; /* current input line */

	while ((len = get_line(line, MAXLINE)) > 0) {
		reverse(line);
		printf("%s", line);
	}

	return 0;
}

/* reverse a char string */
void reverse(char s[]) {

	int i = 0;
	int j = 0;
	char tmp;

	while (s[j] != '\0') {
		j++;
	}

	--j; /* before '\0' */

	if (j > 0 && s[j] == '\n') /* don't reverse \n */
		j--;

	while (i < j) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {

	int c = 0;
	int i = 0;

	while (i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}

	if (c == '\n' && i < lim - 1)
		s[i++] = '\n';

	s[i] = '\0';

	return i;
}
