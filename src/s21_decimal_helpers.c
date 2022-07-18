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

int check_sign(s21_decimal *dst) {return findbit(dst->bits[3], _SIGNBIT_POS);}

int check_int_overflow(s21_decimal *dst) {
    int error = 0;
    for (int i = 1; i < 3; i++) {
        for (int j = 0; j < INT_SIZE; j++) {
            if (findbit(dst->bits[i], j)) {
                error = DATA_OVERFLOW;
                break;
            }
        }
        if (error) break;
    }
    if (!error) {
        if (findbit(dst->bits[0], 31)) {
            if (!check_sign(dst)) error = DATA_OVERFLOW;
            for (int i = 0; i < INT_SIZE - 1; i++) {
                if (findbit(dst->bits[0], i)) {
                    error = DATA_OVERFLOW;
                    break;
                }
            }
        }
    }
    return error;
}
