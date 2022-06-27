#include "solve.h"

int find_next_empty_slot(ushort_t board[BOARD_DIM][BOARD_DIM], unsigned* row, unsigned* col) {
	unsigned i = 0, j = 0;
	for (i = 0; i < BOARD_DIM; ++i) {
		for (j = 0; j < BOARD_DIM; ++j) {
			if (!is_int(log2((double)board[i][j]))) {
				*row = i;
				*col = j;
				return 1;
			}
		}
	}
	return 0;
}

int is_valid(ushort_t board[BOARD_DIM][BOARD_DIM], unsigned row, unsigned col, int option) {
	unsigned i, j;
	// check row
	for (i = 0; i < BOARD_DIM; ++i) {
		if (get_value(board[row][i]) == option && col != i)
			return 0;
	}
	// check col
	for (i = 0; i < BOARD_DIM; ++i) {
		if (get_value(board[i][col]) == option && row != i)
			return 0;
	}

	//check block

	for (i = (row / 3) * 3; i < (row / 3) * 3 + 3; ++i) {
		for (j = (col / 3) * 3; j < (col / 3) * 3 + 3; ++j) {
			if (get_value(board[i][j]) == option && !(row == i && col == j))
				return 0;
		}
	}

	return 1;
}


int solve_board(ushort_t board[BOARD_DIM][BOARD_DIM]) {
	unsigned options[NUM_NUMBERS] = {0};
	unsigned row = 0, col = 0;
	unsigned i = 1;

	if (0 == find_next_empty_slot(board, &row, &col)) {
		return 1;
	}

	get_options(board[row][col], options);

	for (i = 1; i < NUM_NUMBERS + 1; ++i) {
		if (options[i - 1] && is_valid(board, row, col, i)) {
			// put i in slot
			board[row][col] = (1 << (i - 1));

			if (solve_board(board))
				return 1;
			else
				board[row][col] = UNKW;
		}
	}

	return 0;
}
