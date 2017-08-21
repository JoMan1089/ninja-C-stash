// Joshua Luke R. Cordova       SN: 2015-90760

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INPUT_MAX 128
#define CSV_MAX 64

int check_string(char *cArr, size_t size);
void stringify(char *cArr, size_t size);
int str_rm_whitespace(char *str, size_t len);
void str_backspace(char *str, size_t len, size_t index);


int main()
{
	char *inputArr = (char *) calloc(INPUT_MAX, sizeof(*inputArr)); // allocate memory for input
	if (inputArr) {
		printf("%zu bytes allocated. Storing input.\n", INPUT_MAX * sizeof(*inputArr));
	}
	else {
		printf("Memory Allocation Failed!");
		return 0;
	}
	
	char c;
	size_t i;
	for (c = getchar(), i = 0; (c != EOF); c = getchar()) { // get input
		if (i < INPUT_MAX - 1) {
			inputArr[i] = c;
			//printf("%c", inputArr[i]);
			i++;
		}
	}
	
	int input_len = check_string(inputArr, INPUT_MAX);
	if (input_len < 0) { // handle exception: overwriting of null terminator
		printf("NOT String\n");
		stringify(inputArr, INPUT_MAX);
		input_len = check_string(inputArr, INPUT_MAX);
	}
	input_len++;
	char *tmp = realloc(inputArr, (input_len) * sizeof(*tmp)); //reallocate input storage to smallest possible size
	if (tmp) {
		printf("Input storage reallocated to %zu bytes.\n", (input_len) * sizeof(*tmp));
		inputArr = tmp;
	}
	else {
		printf("Memory Reallocation Failed! Freeing Previously Allocated Memory.");
		free(inputArr);
		return 0;
	}
	
	str_rm_whitespace(inputArr, strlen(inputArr) + 1);
	
	char **CSV_Arr = malloc(CSV_MAX * sizeof(char)); // create CSV storage
	if (CSV_Arr) {
		printf("%zu bytes allocated. Storing CSV's.\n", CSV_MAX * sizeof(char));
	}
	else {
		printf("Memory Allocation Failed! Freeing Previously Allocated Memory.");
		free(inputArr);
		return 0;
	}
	
	size_t csv_ctr = 0;
	size_t csv_i;
	for (i = 0, csv_i = 1; ((i <= (size_t)input_len) && (csv_ctr <= CSV_MAX)); i++, csv_i++) {
		if ((inputArr[i] == ',') || (inputArr[i] == '\0')) {
			CSV_Arr[csv_ctr] = calloc (csv_i, sizeof(char));
			
			if (CSV_Arr[csv_ctr]) {
				//printf("%zu bytes allocated. Storage available for CSV[%zu].\n", (csv_i) * sizeof(char), csv_ctr);
			}
			else {
				printf("Memory Allocation Failed! Freeing Previously Allocated Memory.");
				free(inputArr);
				size_t free_i;
				for (free_i = 0; free_i >= csv_ctr - 1; free_i++) {
					free(CSV_Arr[free_i]);
					printf("Freeing CSV_Arr[%zu]\n", free_i);
				}
				free(CSV_Arr);
				return 0;
			}
			csv_ctr++;
			csv_i = 0;
			if (inputArr[i] == '\0')
				break;
		}
	}
	printf("%zu CSV's found.\n", csv_ctr);
	
	size_t csv_ctr_w = 0;
	for (i = 0, csv_ctr_w = 0, csv_i = 0; (i <= (size_t)input_len) && (csv_ctr_w < csv_ctr); i++, csv_i++) {
		if ((inputArr[i] == ',') || (inputArr[i] == '\0')) {
			CSV_Arr[csv_ctr_w][csv_i] = '\0';
			//printf("Comma at: %zu\n", i);
			csv_ctr_w++;
			csv_i = 0;
			if (inputArr[i] == 0)
				break;
		}
		else {
			CSV_Arr[csv_ctr_w][csv_i] = inputArr[i];
		}
	}
	for(i = 0; i < csv_ctr; i++) {
		size_t j;
		printf("Word %zu: \"", i+1);
		for(j = 0; CSV_Arr[j] != '\0'; j++) {
			printf("%c", CSV_Arr[i][j]);
		}
		printf("\"\n");
	}
	
	free(inputArr);
	size_t free_i = 0;
	for (free_i = 0; free_i <= csv_ctr; free_i++) {
		free(CSV_Arr[free_i]);
		//printf("Freeing CSV_Arr[%zu]\n", free_i);
	}
	free(CSV_Arr);
	return 0;
}

int check_string(char *cArr, size_t size)
{
	unsigned long i;
        for (i = 0;i < size; i++) {
		if (cArr[i] == '\0') {
			return strlen(cArr);
		}
	}
	return -1;
}

void stringify(char *cArr, size_t size)
{
	if (check_string(cArr, size) < 0) {
		cArr[size - 1] = '\0';
	}
}

int str_rm_whitespace(char *str, size_t len)
{
	size_t i;
	int space_removed = 0;
	for (i = 0; i <= len; i++) {
		if ((isspace(str[i])) && (i != 0)) {
			str_backspace(str, len, i);
			space_removed += 1;
			i--;
			len--;
		}
	}
	if (space_removed > 0)
		return space_removed;
	return -1;
}

void str_backspace(char *str, size_t len, size_t index)
{
	size_t i;
	for (i = index; i <= len; i++) {
		str[i] = str[i + 1];
	}
	str[i] = '\0';
	return;
}