#ifndef _S21_DECIMAL_H_
#define _S21_DECIMAL_H_

#include <math.h>
#include <stdlib.h>
#include <string.h>

#define INT_SIZE __CHAR_BIT__ * 4
#define _SIGNBIT_POS 31

struct decimal {
    int bits[4];
};

typedef struct decimal s21_decimal;

// helpers
int findbit(const int n, const int k);
int setbit(int n, const int k);
int clearbit(int n, const int k);
int switchbit(int n, const int k);
int modbit(int n, const int k, int bit);

void set_neg_bit(s21_decimal *dst);
void set_pos_bit(s21_decimal *dst);

// converters
int s21_from_int_to_decimal(int src, s21_decimal *dst);

#endif  // _S21_DECIMAL_H_