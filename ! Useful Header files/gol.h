/*
    ME9 - Mini Game of Life Simulator
    Created by: Joshua Luke R. Cordova
    Student Number: 2015-90760
*/

#ifndef __GOL_H__
#define __GOL_H__

#include <stdio.h>

void init_grid(char grid[][21], unsigned long num_rows);

void load_config(char grid[][21]);

void print_grid(char grid[][21], unsigned long num_rows);

int chk_neighbors(char grid[][21], unsigned long row, unsigned long col);

void step(char grid[][21], unsigned long num_rows);

#endif
