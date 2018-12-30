#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "rubiks.h"

void build_final_line(int **table)
{
	rotate_columns(table, 3, -1);
	rotate_columns(table, 3, -1);
	rotate_columns(table, 2, -1);
	rotate_columns(table, 2, -1);

	// printf("finsih !!!\n");
	// print_tab(table);

	return;
}