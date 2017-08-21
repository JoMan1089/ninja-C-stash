// Joshua Luke R. Cordova   Student Number: 2015-90760

#include <stdio.h>
#include <string.h>

int get_input(char inputArr[], size_t size);

int main()
{
        char iArr[64];
	printf("Enter Tweet: ");
	get_input(iArr, sizeof(iArr));
	char *pos = iArr;
	//printf("Starting Address: %p\n", pos);
	int hash_found = 0;
	for (;*pos != '\0'; pos++) {
		if (*pos == '#') {
			hash_found += 1;
			//printf("Hash At: %p\n", pos);
			if (hash_found == 1) {
				printf("Hashtags found:\n");
			}
			for (;(iArr - pos) <= (int)strlen(iArr); pos++) {
				if ((*pos == ' ') || (*pos == '\0')) {
					//printf("Space At: %p\n", pos);
					printf("\n");
					break;
				}
				else {
					printf("%c", *pos);
				}
			}
		}
	}
	if (hash_found == 0) {
			printf("No Hashtags found.\n");
		}
        return 0;
}

int get_input(char inputArr[], size_t size)
{
	inputArr[0] = '\0';
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
	if (inputArr[0] == '\0') {
		return 0;
	}
	//puts(inputArr);
	return i;
}