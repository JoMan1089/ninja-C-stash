/*
 * Custom Safe-Input Function Library - Function Definitions
 * Created by: Joshua Luke R. Cordova
 * Student Number: 2015-90760
 */

#include "safe_input.h"

int get_input(char inputArr[], size_t size)
{
	inputArr[0] = '\0';
	assert(size > 0 && size < INT_MAX);
	size_t i;
	char c;
	for (c = getchar(), i = 0; (c != EOF); c = getchar()) {
		if (c == '\n') {
			break;
		}
		if (i < size - 1) {
			inputArr[i] = c;
			i++;
		}
	}
	inputArr[i] = '\0';
	if (inputArr[0] == '\0')
		return 0;
	//puts(inputArr);
	return i;
}