/*
 * Custom String Library - Function Definitions
 * Last Modified: 2017-04-05
 * Created by: Joshua Luke R. Cordova
 * Student Number: 2015-90760
 */

#include "string_ext.h"

int check_string(char cArr[], size_t size)
{
	size_t i;
	for (i = 0;i < size; i++) {
		printf("Arr[%lu] = %c\n", i, cArr[i]);
		if (cArr[i] == '\0') {
			return strlen(cArr);
		}
	}
	return -1;
}

void stringify(char cArr[], size_t size)
{
	if (check_string(cArr, size) < 0) {
		cArr[size - 1] = '\0';
	}
}

size_t num_occurences(char cArr[], char c, size_t size)
{
	size_t i, occurrences = 0;
	for (i = 0;i < size; i++){
		if (cArr[i] == c){
			occurrences += 1;
			}
		}
	return occurrences;
}

void replace_char(char cArr[], char original, char replacement, size_t size)
{
	size_t i;
	for (i = 0;i < size; i++){
		if (cArr[i] == original){
			cArr[i] = replacement;
		}
	}
}

int push_character(char cArr[], char cAppend, size_t size, size_t len)
{
	if (len + 1 < size) {
		cArr[len] = cAppend;
		cArr[len + 1] = '\0';
		return 0;
	}
	else {
		return -1;
	}
}

int pop_character(char cArr[], size_t len)
{
	if (!cArr[0] == 0) {
		cArr[len - 1] = '\0';
		return 0;
	}
	return -1;
}

int strcpy_check(size_t destsize, size_t srclen)
{
	if (destsize >= srclen + 1){
		return 0;
	}
	else {
		return (srclen + 1) - destsize;
	}
}

int strcat_check(size_t destsize, size_t destlen, size_t srclen)
{
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

void str_reverse(char cArr[], size_t len)
{
	char cbuff;
	if (len > 0) {
		cbuff = cArr[0];
		cArr[0] = cArr[len - 1]; //swaps with char before NULL terminator
		cArr[len - 1] = cbuff;
		str_reverse(cArr + 1, len - 2); //shifts pointer 1 block over and shortens len to refer to cArr[0]'s new partner
	}
	
	return;
}

int swap_string(char str1[], char str2[], size_t str1_size, size_t str2_size, size_t str1_len, size_t str2_len)
{
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
		size_t i;
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

// The following functions were added post-ME8

void str_toupper(char str[], size_t len)
{
	size_t i;
	for (i = 0; i < (len); i++) {
		str[i] = toupper(str[i]);
	}
	return;
}

void str_tolower(char str[], size_t len)
{
	size_t i;
	for (i = 0; i < (len); i++) {
		str[i] = tolower(str[i]);
	}
	return;
}

void str_toproper(char str[], size_t len)
{
	str_tolower(str, len);
	str[0] = toupper(str[0]);
}

int str_rm_whitespace(char str[], size_t len)
{
	size_t i;
	int space_removed = 0;
	for (i = 0; i <= (len - 1); i++) {
		if ((isspace(str[i])) && (i !=0)) {
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

void str_backspace(char str[], size_t len, size_t index)
{
	size_t i;
	for (i = index; i < (len - 1); i++) {
		str[i] = str[i + 1];
	}
	str[i] = '\0';
	return;
}

int strncmp_case(char str1[], char str2[], size_t n)
{
	char buff1[n];
	char buff2[n];
	strncpy(buff1, str1, n);
	strncpy(buff2, str2, n);
	str_tolower(buff1, strlen(buff1));
	str_tolower(buff2, strlen(buff2));
	return strncmp(buff1, buff2, n);
}
bool str_isdigit(char str[], size_t len) {
	if (str[0] == '\0') {
		return false;
	}
	else {
		size_t i;
		for (i = 0; (i < (len)); i++) {
			if (isdigit(str[i]) == 0) {
				return false;
			}
		}
		return true;
	}
}
bool str_isradix(char str[], size_t len)
{
	if (str[0] == '\0') {
		return false;
	}
	else {
		size_t i, radix_ctr;
		bool negative = false;
		for (i = 0, radix_ctr = 0; (i < (len)) || (radix_ctr > 1); i++) {
			//printf("str[%d] = %c\n", (int) i, str[i]);
			if ((str[0] == '-') && (negative == false)) {
				negative = true;
			}
			else if ((str[i] == '.') && (radix_ctr == 0)) {
				printf("radix\n");
				radix_ctr++;
			}
			else if (isdigit(str[i]) == 0) {
				printf("NOT\n");
				return false;
			}
		}
		return true;
	}
}



size_t str_len(char str[], size_t size)
{
	size_t i;
	for (i = 0; (i < size - 1); i++) {
		if (str[i] == '\0') {
			break;
		}
	}
	return i;
}

size_t str_search(char str[], char c, size_t len)
{
	size_t i;
	for (i = 0; i < len; i++) {
		//printf("i = %zu\n", i);
		if (str[i] == c) {
			return i;
		}
	}
	return (-1);
}

size_t get_min(size_t a, size_t b)
{
	if (a < b)
		return a;
	return b;
}