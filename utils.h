#pragma once
#include <math.h>

#include "def.h"

int is_int(double x);
int get_value(unsigned val);
int is_one_bit_only_on(int val);
void get_options(ushort_t num, unsigned* options);
void print_board(ushort_t board[BOARD_DIM][BOARD_DIM]);
void convert_board_to_bitwise(ushort_t board[BOARD_DIM][BOARD_DIM]);
void convert_board_from_bitwise(ushort_t board[BOARD_DIM][BOARD_DIM]);
