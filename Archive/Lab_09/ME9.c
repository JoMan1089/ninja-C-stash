/*
    ME9 - Mini Game of Life Simulator
    Created by: Joshua Luke R. Cordova
    Student Number: 2015-90760
*/

#include "gol.h"

int main()
{
    int ctr;
	char grid[21][21];
	unsigned long num_rows = sizeof(grid)/sizeof(grid[0]);

	init_grid(grid, num_rows);
	
	load_config(grid);
	
	/*
	//debug chk_neighbors
	grid[2][3] = '1';
	grid[3][3] = '1';
	grid[4][3] = '1';
	grid[2][5] = '1';
	grid[3][2] = '1';
	grid[10][10] = '1';
	
	printf("%d\n", chk_neighbors(grid, 3, 3));
	*/
	
	print_grid(grid, num_rows);
	
	
	for (ctr = 0; ctr < 10; ++ctr) {
		step(grid, num_rows);
	}
	
    return 0;
}