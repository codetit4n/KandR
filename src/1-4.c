/*

Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table.

*/

#include <stdio.h>

int main() {

	float fahr, celsius;
	float lower, upper, step;
	lower = 0;   /* lower limit of temperatuire scale */
	upper = 300; /* upper limit */
	step = 20;   /* step size */
	celsius = lower;
	printf("Celsius to Fahrenheit Table\n");
	printf("---------------------------\n");
	printf("Celsius\tFahr\n");
	while (celsius <= upper) {
		fahr = (9.0 / 5.0) * celsius + 32.0;
		printf("%6.1f %3.0f\n", celsius, fahr);
		celsius = celsius + step;
	}

	return 0;
}
