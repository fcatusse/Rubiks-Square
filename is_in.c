#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "rubiks.h"

int is_in_line(int **table, int line, int value)
{
	int i = 0;
	while(i < 4) {
		if (table[line][i] == value) {
			return(0);
		}
		i++;
	}
	return(1);
}

int is_in_col(int **table, int column, int value) {
	int i = 0;
	while(i < 4) {
		if (table[i][column] == value) {
			return(0);
		}
		i++;
	}
	return(1);
}