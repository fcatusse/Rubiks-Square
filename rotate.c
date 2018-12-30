#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "rubiks.h"

void rotate_lines(int **table, int line, int offset) {
	if (offset > 0) {
		algo_line(table, line);
	}
	if (offset < 0) {
		algo_line_reverse(table, line);
	}
}

void rotate_columns(int **table, int column, int offset) {
	if (offset > 0) {
		algo_column(table, column);
	}
	if (offset < 0) {
		algo_column_reverse(table, column);
	}
}
