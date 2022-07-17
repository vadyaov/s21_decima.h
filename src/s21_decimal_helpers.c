#include "s21_decimal.h"

int findbit(const int n, const int k) {return (n & (1 << k)) ? 1 : 0;}

int setbit(int n, const int k) {return (n | (1 << k));}

int clearbit(int n, const int k) {return (n & ~(1 << k));}

int switchbit(int n, const int k) {return (n ^ (1 << k));}

int modbit(int n, const int k, int bit) {
    int result;
    if (!bit) result = clearbit(n, k);
    else
        result = setbit(n, k);
    return result;
}

void set_neg_bit(s21_decimal *dst) {
    dst->bits[3] = setbit(dst->bits[3], _SIGNBIT_POS);
}

void set_pos_bit(s21_decimal *dst) {
    dst->bits[3] = clearbit(dst->bits[3], _SIGNBIT_POS);
}
