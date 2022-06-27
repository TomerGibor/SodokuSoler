#include <stdio.h>
#include "solve.h"


int main() {
	unsigned res = 0;

	ushort_t test_board[BOARD_DIM][BOARD_DIM] = {
		{5, 0, 9, 4, 0, 0, 0, 0, 0},
		{0, 0, 3, 0, 0, 0, 6, 9, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 5},
		{0, 5, 0, 1, 8, 0, 0, 0, 0},
		{3, 0, 0, 0, 5, 0, 0, 0, 7},
		{0, 0, 0, 0, 9, 6, 0, 5, 0},
		{9, 0, 0, 0, 0, 0, 0, 7, 0},
		{0, 3, 8, 0, 0, 0, 5, 0, 0},
		{0, 0, 0, 0, 0, 7, 1, 0, 3},
	};

	convert_board_to_bitwise(test_board);

	res = solve_board(test_board);
	if (!res) {
		printf("Invalid board, unable to solve\n");
	}
	else {
		printf("Solved!!!\n");
		convert_board_from_bitwise(test_board);
		print_board(test_board);
	}

	return 1;
}
