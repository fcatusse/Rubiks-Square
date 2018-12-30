#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "rubiks.h"

void algo_line_reverse(int **table, int line) {
	int cell_tmp;

	cell_tmp = table[line][3];
	table[line][3] = table[line][2];
	table[line][2] = table[line][1];
	table[line][1] = table[line][0];
	table[line][0] = cell_tmp;
	if (PRINT_SQUARE_DEBUG__) {
		printf("Rotate Right line %d.\n", line);
		print_tab(table);
		printf("\n");
	}
	print_tab(table);
}

void algo_column_reverse(int **table, int column) {
	int cell_tmp;

	cell_tmp = table[3][column];
	table[3][column] = table[2][column];
	table[2][column] = table[1][column];
	table[1][column] = table[0][column];
	table[0][column] = cell_tmp;
	if (PRINT_SQUARE_DEBUG__) {
		printf("Rotate Bottom column %d.\n", column);
		print_tab(table);
		printf("\n");
	}
	print_tab(table);
}

void algo_square_reverse(int **table, int square)
{
	int cell_tmp;

  	if (square == 0) {
		cell_tmp = table[1][1];
		table[1][1] = table[1][0];
		table[1][0] = table[0][0];
		table[0][0] = table[0][1];
		table[0][1] = cell_tmp;
	}
	if (square == 1) {
		cell_tmp = table[1][3];
		table[1][3] = table[1][2];
		table[1][2] = table[0][2];
		table[0][2] = table[0][3];
		table[0][3] = cell_tmp;
	}
	if (square == 2) {
		cell_tmp = table[3][1];
		table[3][1] = table[3][0];
		table[3][0] = table[2][0];
		table[2][0] = table[2][1];
		table[2][1] = cell_tmp;
	}
	if (square == 3) {
		cell_tmp = table[3][3];
		table[3][3] = table[3][2];
		table[3][2] = table[2][2];
		table[2][2] = table[2][3];
		table[2][3] = cell_tmp;
	}
	if (PRINT_SQUARE_DEBUG__) {
		printf("Rotate Counter Clockwise square %d.\n", square);
		print_tab(table);
		printf("\n");
	}
	print_tab(table);
}