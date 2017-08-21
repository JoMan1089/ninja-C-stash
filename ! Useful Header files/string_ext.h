/*
 * Custom String Library - Function Prototypes
 * Last Modified: 2017-04-05
 * Created by: Joshua Luke R. Cordova
 * Student Number: 2015-90760
 */

#ifndef __STRING_EXT_H__
#define __STRING_EXT_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int check_string(char cArr[], size_t size);

void stringify(char cArr[], size_t size);

unsigned long num_occurences(char cArr[], char c, size_t size);

void replace_char(char cArr[], char original, char replacement, size_t size);

int push_character(char cArr[], char cAppend, size_t size, size_t len);

int pop_character(char cArr[], size_t len);

int strcpy_check(size_t destsize, size_t srclen);

int strcat_check(size_t destsize, size_t destlen, size_t srclen);

void str_reverse(char cArr[], size_t len);

int swap_string(char str1[], char str2[], size_t str1_size, size_t str2_size, size_t str1_len, size_t str2_len);

// The folloeing functions were added post-ME8

void str_toupper(char str[], size_t len);

void str_tolower(char str[], size_t len);

void str_toproper(char str[], size_t len);

int str_rm_whitespace(char str[], size_t len);

void str_backspace(char str[], size_t len, unsigned long index);

int strncmp_case(char str1[], char str2[], size_t n);

bool str_isdigit(char str[], size_t len);

bool str_isradix(char str[], size_t len);

void str_clear(char str[], size_t len);

size_t str_len(char str[],size_t size);

#endif