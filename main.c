
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "rubiks.h"

int main()
{
	/*

	Creation du cube

	*/

	int **table = malloc(sizeof(int*)*3);
	int i=0;
	int j=0;
	int cpt=0;

	while (i<=3) {
		table[i] = malloc(sizeof(int)*3);
		while (j<=3) {
			table[i][j] = 0;
			j++;
		}
		j=0;
		i++;
	}

	table[0][0] = 0;
	table[0][1] = 1;
	table[1][0] = 2;
	table[1][1] = 3;
	table[0][2] = 0;
	table[0][3] = 3;
	table[1][2] = 1;
	table[1][3] = 2;
	table[2][0] = 3;
	table[2][1] = 1;
	table[3][0] = 2;
	table[3][1] = 0;
	table[2][2] = 3;
	table[2][3] = 2;
	table[3][2] = 1;
	table[3][3] = 0;

	print_tab(table);
	
	build_first_square(table);
	build_second_square(table);
	build_final_line(table);

	free(table);

	return(0);
}