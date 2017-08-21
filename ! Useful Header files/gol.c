/*
    ME9 - Mini Game of Life Simulator
    Created by: Joshua Luke R. Cordova
    Student Number: 2015-90760
*/

#include "gol.h"

void init_grid(char grid[][21], unsigned long num_rows) {
	unsigned long i, j;
	for (i = 0; i <= num_rows - 1; i++) {
		for (j = 0; j <= 20; j++) {
			grid[i][j] = '0';
		}
	}
}

void load_config(char grid[][21]) {
	unsigned long i, lines, x, y;
	scanf("%lu", &lines);
	//printf("%lu\n", lines);
	for (i = 0; (i < lines); i++) {
		scanf("%lu %lu", &x, &y);
		//printf("%lu %lu\n", x, y);
		grid[x][y] = '1';
	}
}


void print_grid(char grid[][21], unsigned long num_rows) {
	unsigned long i, j;
	for (i = 0; i <= num_rows - 1; i++) {
		for (j = 0; j <= 20; j++) {
			printf("%c ", grid[i][j]);
		}
		printf("\n");
	}
}

int chk_neighbors(char grid[][21], unsigned long row, unsigned long col) {
	unsigned long i, j, row_min, row_max, col_min, col_max;
	int neighbors = 0;
	
	row_min = row - 1;
	row_max = row + 1;
	col_min = col - 1;
	col_max = col + 1;
	
	//printf("Running: chk_neighbors(%lu, %lu)\n", row, col);
	if (row == 0)
		row_min = 0;
	if (row == 20)
		row_max = 20;
	if (col == 0)
		col_min = 0;
	if (col == 20)
		col_max = 20;
	
	for (i = row_min ; i <= row_max; i++) {
		for (j = col_min; j <= col_max; j++) {
			//printf("(%lu, %lu) = %c\n", i, j, grid[i][j]);
			if(grid[i][j] == '1') {
				if (!((i == row) && (j == col)))
				neighbors += 1;
			}
		}
	}
	return neighbors;
}


void step(char grid[][21], unsigned long num_rows) {
	printf("\n");
	unsigned long i, j, n;
	
	char buff_grid[num_rows][21];
	for (i = 0; i <= num_rows - 1; i++) {
		for (j = 0; j <= 20; j++) {
			buff_grid[i][j] = grid[i][j];
		}
	}
	
	for (i = 0; i <= num_rows - 1; i++) {
		for (j = 0; j <= 20; j++) {
			n = chk_neighbors(buff_grid, i, j);
			if (buff_grid[i][j] == '1') {
				if ((n <= 1) || (n >= 4))
					grid[i][j] = '0';
				if ((n == 2) || (n == 3))
					grid[i][j] = '1';
			}
			else if (buff_grid[i][j] == '0') {
				if (n == 3)
					grid[i][j] = '1';
			}
		}
	}
	print_grid(grid, num_rows);
}