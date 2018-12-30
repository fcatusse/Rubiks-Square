#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "rubiks.h"

void build_second_square(int **table)
{
	build_last_line(table);
	line_to_square(table, 3);
}

void build_last_line(int **table)
{
	int *ret_value;
	int *ret_space;
	int lines [4];
	int columns [4];

	/*

	LIGNE n3
	
	*/

	lines[0] = BLOCKED;
	lines[1] = BLOCKED;
	lines[2] = EMPTY;
	lines[3] = BLOCKED;
	columns[0] = EMPTY;
	columns[1] = EMPTY;
	columns[2] = EMPTY;
	columns[3] = EMPTY;

	ret_value = look_for_value(table, lines, columns, 3);
	while(ret_value != NULL) {
		for(int i=0; i<(3-ret_value[1]); i++) {
			rotate_lines(table, 2, -1);
			// print_tab(table);
		}
		rotate_columns(table, 3, -1);
		rotate_lines(table, 3, 1);
		// print_tab(table);
		ret_value = look_for_value(table, lines, columns, 3);
	}
	// print_tab(table);

	/*

	COLONNE n3 (sauf derniere ligne)

	*/

	lines[0] = EMPTY;
	lines[1] = EMPTY;
	lines[2] = EMPTY;
	lines[3] = BLOCKED;
	columns[0] = BLOCKED;
	columns[1] = BLOCKED;
	columns[2] = EMPTY;
	columns[3] = BLOCKED;

	ret_value = look_for_value(table, lines, columns, 3);
	while(ret_value != NULL) {
		for(int i=0; i<(3-ret_value[0]); i++) {
			rotate_columns(table, 2, -1);
			// print_tab(table);
		}
		rotate_lines(table, 3, 1);
		ret_value = look_for_value(table, lines, columns, 3);
	}

	/*

	COLONNE n4 (sauf derniere ligne)

	*/

	lines[0] = EMPTY;
	lines[1] = EMPTY;
	lines[2] = EMPTY;
	lines[3] = BLOCKED;
	columns[0] = BLOCKED;
	columns[1] = BLOCKED;
	columns[2] = BLOCKED;
	columns[3] = EMPTY;

	ret_value = look_for_value(table, lines, columns, 3);
	while(ret_value != NULL) {
		for(int i=0; i<(3-ret_value[0]); i++) {
			rotate_columns(table, 3, -1);
			// print_tab(table);
		}
		rotate_lines(table, 3, 1);
		ret_value = look_for_value(table, lines, columns, 3);
	}

	// Apercu etape
	// printf("last line\n");
	// print_tab(table);
	
	return;
}