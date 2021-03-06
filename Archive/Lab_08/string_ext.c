/*
    ME8 - Custom String Library - Function Definitions
    string_ext.h custom library definitions
    Created by: Joshua Luke R. Cordova
    Student Number: 2015-90760
*/

#include "string_ext.h"

int check_string(char cArr[], size_t size){
	unsigned int i;
        for (i = 0;i < size; i++){
			if (cArr[i] == '\0'){
				return strlen(cArr);
			}
		}
	return -1;
}

void stringify(char cArr[], size_t size){
	if (check_string(cArr,size) < 0){
		cArr[size-1] = '\0';
	}
}

unsigned long num_occurences(char cArr[], char c, size_t size){
	unsigned long i, occurrences = 0;
	for (i = 0;i < size; i++){
		if (cArr[i] == c){
			occurrences += 1;
			}
		}
	return occurrences;
}

void replace_char(char cArr[], char original, char replacement, size_t size){
	unsigned long i;
	for (i = 0;i < size; i++){
		if (cArr[i] == original){
			cArr[i] = replacement;
		}
	}
}

int push_character(char cArr[], char cAppend, size_t size, size_t len){
	if (len + 1 < size) {
		cArr[len] = cAppend;
		cArr[len + 1] = '\0';
		return 0;
	}
	else {
		return -1;
	}
}

int pop_character(char cArr[], size_t len){
	if (!cArr[0] == 0) {
		cArr[len - 1] = '\0';
		return 0;
	}
	return -1;
}

int strcpy_check(size_t destsize, size_t srclen){
	if (destsize >= srclen + 1){
		return 0;
	}
	else {
		return (srclen + 1) - destsize;
	}
}

int strcat_check(size_t destsize, size_t destlen, size_t srclen) {
	if (destsize >= srclen + destlen + 1){
		return 0;
	}
	else if (destsize == destlen + 1){
		return -1;
	}
	else if (destsize == srclen + destlen){
		return -2;
	}
	else {
		return (srclen + destlen) - destsize;
	}
}

void string_reverse(char cArr[], size_t len){
	char cbuff;
	if (len > 0) {
		cbuff = cArr[0];
		cArr[0] = cArr[len - 1]; //swaps with char before NULL terminator
		cArr[len - 1] = cbuff;
		string_reverse(cArr + 1, len - 2); //shifts pointer 1 block over and shortens len to refer to cArr[0]'s new partner
	}
	
	return;
}

int swap_string(char str1[], char str2[], size_t str1_size, size_t str2_size, size_t str1_len, size_t str2_len) {
	/*
	puts(str1);
	printf("\tstr1_size = %lld\n", (long long)str1_size);
	printf("\tstr1_len = %lld\n", (long long)str1_len);
	
	puts(str2);
	printf("\tstr2_size = %lld\n", (long long)str2_size);
	printf("\tstr2_len = %lld\n", (long long)str2_len);
	*/
	if ((strcpy_check(str1_size, str2_len) == 0) && (strcpy_check(str2_size, str1_len) == 0)){
		char strbuff[str1_size];
		unsigned long i;
		for (i = 0; str1[i] != '\0'; i++) {
			strbuff[i] = str1[i];
		}
		strbuff[i] = '\0';
		
		for (i = 0; str2[i] != '\0'; i++) {
			str1[i] = str2[i];
		}
		str1[i] = '\0';
		
		for (i = 0; strbuff[i] != '\0'; i++) {
			str2[i] = strbuff[i];
		}
		str2[i] = '\0';
		
		/*
		puts(strbuff);
		printf("\tstrbuff_size = %lld\n", (long long)sizeof(strbuff));
		printf("\tstrbuff_len = %lld\n", (long long)strlen(strbuff));
		*/
		return 0;
	}
	return -1;
}

