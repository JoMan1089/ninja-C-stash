/*
    ME8 - Custom String Library
    string_ext.h custom library
    Created by: Joshua Luke R. Cordova
    Student Number: 2015-90760
*/

#ifndef __STRING_EXT_H__
#define __STRING_EXT_H__

#include <string.h>
#include <stdlib.h>

/*
    This is where you will place your function prototypes.
    I have placed the first one for you.
    Add the rest of the prototypes here.
    Note that you are not allowed to place function definitions here,
    only prototypes.
    Place all function definitions in a file called string_ext.c
    Also, rename this file to string_ext.h
*/
int check_string(char cArr[], size_t size);

void stringify(char cArr[], size_t size);

unsigned long num_occurences(char cArr[], char c, size_t size);

void replace_char(char cArr[], char original, char replacement, size_t size);

int push_character(char cArr[], char cAppend, size_t size, size_t len);

int pop_character(char cArr[], size_t len);

int strcpy_check(size_t destsize, size_t srclen);

int strcat_check(size_t destsize, size_t destlen, size_t srclen);

void string_reverse(char cArr[], size_t len);

int swap_string(char str1[], char str2[], size_t str1_size, size_t str2_size, size_t str1_len, size_t str2_len);

#endif