#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "rubiks.h"

void build_first_square(int **table)
{
	build_first_line(table);
	line_to_square(table, 0);
}

void build_first_line(int **table)
{
	int *ret_value;
	int *ret_space;
	int lines [4];
	int columns [4];

	// Fermer 1er ligne pour recherche le 0 sur les suivantes
	lines[0] = BLOCKED ;
	lines[1] = EMPTY ;
	lines[2] = EMPTY ;
	lines[3] = EMPTY ;
	columns[0] = EMPTY ;
	columns[1] = EMPTY ;
	columns[2] = EMPTY ;
	columns[3] = EMPTY ;

	// Rechercher presence valeur (ret_value)
	ret_value = look_for_value(table, lines, columns, 0);

	while (ret_value != NULL) {
		// Si ret_value bloquer lignes sauf la 1ere pour trouver un place
		lines[0] = EMPTY;
		lines[1] = BLOCKED;
		lines[2] = BLOCKED;
		lines[3] = BLOCKED;

		// Rechercher une place
		ret_space = look_for_space(table, lines, columns, 0);

		// Faire les rotations lines et columns
		rotate_lines(table, ret_value[0], ret_value[1] - ret_space[1]);
		rotate_columns(table, ret_space[1], ret_value[0] - ret_space[0]);
		lines[0] = BLOCKED;
		lines[1] = EMPTY;
		lines[2] = EMPTY;
		lines[3] = EMPTY;
		ret_value = look_for_value(table, lines, columns, 0);
	}
	// Apercu etape
	// printf("first line\n");
	// print_tab(table);
	
	return;
}

void line_to_square(int **table, int line) {

	if(line==0) {
		algo_square_reverse(table,0);
		algo_square_reverse(table,0);
		algo_line(table,0);
		algo_line(table,0);
		// printf("first square\n");
	}
	if(line==3) {
		algo_square_reverse(table,3);
		algo_square_reverse(table,3);
		algo_line(table,3);
		algo_line(table,3);
		algo_column(table,3);
		algo_column(table,3);
		algo_column(table,2);
		algo_column(table,2);
		// printf("second square\n");
	}
	// Apercu etape
	// print_tab(table);
}