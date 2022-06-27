#include "utils.h"

#include <stdio.h>

int is_int(double x) {
	return x == (int)x;
}


int is_one_bit_only_on(int val) {
	return is_int(log2(val));

}


int get_value(unsigned val) {
	if (is_one_bit_only_on(val))
		return (int)log2(val) + 1;
	return -1;
}


void get_options(ushort_t num, unsigned* options) {
	for (int i = 0; i < NUM_NUMBERS; ++i) {
		options[i] = num & (1 << i);
	}
}

void print_board(ushort_t board[BOARD_DIM][BOARD_DIM]) {
	unsigned i = 0, j = 0;
	for (i = 0; i < BOARD_DIM; ++i) {
		for (j = 0; j < BOARD_DIM; ++j) {
			printf("%d\t", board[i][j]);
		}
		printf("\n");
	}
}

void convert_board_to_bitwise(ushort_t board[BOARD_DIM][BOARD_DIM]) {
	unsigned i = 0, j = 0;
	for (i = 0; i < BOARD_DIM; ++i) {
		for (j = 0; j < BOARD_DIM; ++j) {
			board[i][j] = board[i][j] == 0 ? UNKW : 1 << (board[i][j] - 1);
		}
	}
}


void convert_board_from_bitwise(ushort_t board[BOARD_DIM][BOARD_DIM]) {
	unsigned i = 0, j = 0;
	for (i = 0; i < BOARD_DIM; ++i) {
		for (j = 0; j < BOARD_DIM; ++j) {
			board[i][j] = (ushort_t)get_value(board[i][j]);
		}
	}
}
