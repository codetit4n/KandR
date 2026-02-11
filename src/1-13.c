/*

Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

*/

/*

Histogram is basically a bar chart that shows frequency(how often something occurs).

*/

#include <stdio.h>

#define MAX_LENGTH 100

int main() {
	int c = 0, word_len = 0, j = 0, max = 0, row = 0;
	int lens[MAX_LENGTH] = {0};
	printf("Enter some text or Press Ctrl+D to exit\n");
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (word_len > 0) {
				++lens[word_len];
				word_len = 0;
			}
		} else {
			++word_len;
		}
	}
	/* Handle last word if input doesn't end with whitespace */
	if (word_len > 0) {
		++lens[word_len];
	}

	printf("\nHorizontal histogram: \n");

	for (c = 1; c < MAX_LENGTH; c++) {
		if (lens[c] > 0) {
			printf("%2d: ", c);
			for (j = 0; j < lens[c]; j++) {
				putchar('*');
			}
			putchar('\n');
		}
	}

	printf("\nVertical histogram: \n");

	for (c = 1; c < 100; c++) {
		if (lens[c] > max) {
			max = lens[c];
		}
	}

	for (row = max; row > 0; row--) {
		for (c = 1; c < 100; c++) {
			if (lens[c] >= row) {
				printf("* ");
			} else if (lens[c] > 0) {
				printf("  ");
			}
		}
		printf("\n");
	}

	for (c = 1; c < 100; c++) {
		if (lens[c] > 0) {
			printf("%d ", c);
		}
	}

	return 0;
}
