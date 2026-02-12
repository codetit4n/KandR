/*

Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
in its input.

*/

#include <stdio.h>

#define ASCII_SIZE 128

int main() {
	int c, i, j;
	int chars[ASCII_SIZE] = {0};

	while ((c = getchar()) != EOF) {
		if (c >= 0 && c < ASCII_SIZE)
			chars[c]++;
	}

	for (i = 0; i < ASCII_SIZE; i++) {
		if (chars[i] > 0) {
			if (i == '\n')
				printf("\\n: ");
			else if (i == '\t')
				printf("\\t: ");
			else
				printf("%2c: ", i);

			for (j = 0; j < chars[i]; j++)
				printf("*");

			printf("\n");
		}
	}

	return 0;
}
