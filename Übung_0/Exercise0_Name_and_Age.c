#include <stdio.h>

int main()
{
	printf("Please enter your first and second names and your current age\n");
	char first[10] = { '\0' };	// fehlerhafte ausgabe bei >10 Zeichen
	char second[20] = { '\0' };	// fehlerhafte ausgabe bei >20 Zeichen
	int age = 0;
	scanf_s("%9s %19s %d", first, 10u, second, 20u, &age);
	printf("You entered: %s %s, age %d\n", first, second, age);
}