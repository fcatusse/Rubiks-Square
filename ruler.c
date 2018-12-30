#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "rubiks.h"

void print_number(int nb)
{
	switch (nb) {
	case 0:
		printf("\x1b[30m|\x1b[0m \x1b[31m%d\x1b[0m ", nb);
		break;
	case 1:
		printf("\x1b[30m|\x1b[0m \x1b[32m%d\x1b[0m ", nb);
		break;
	case 2:
		printf("\x1b[30m|\x1b[0m \x1b[33m%d\x1b[0m ", nb);
		break;
	case 3:
		printf("\x1b[30m|\x1b[0m \x1b[34m%d\x1b[0m ", nb);
		break;
	}
}

void print_tab(int **table) {
	int counter_y;
	int i;

	printf("\033[2J");
	usleep(200000);

	counter_y = 0;
	printf("\x1b[30m-----------------\x1b[0m\n");
	while (counter_y < 4) {
		i = 0;
		while (i < 4) {
			print_number(table[counter_y][i]);
			i++;
		}
		printf("\x1b[30m|\x1b[0m\n");
		printf("\x1b[30m-----------------\x1b[0m\n");
		counter_y++;
	}
	return;
}