#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    int convertError = 0;
    if (dst) {
        memset(dst, 0, INT_SIZE);
        if (src < 0) set_neg_bit(dst);
        dst->bits[0] = abs(src);
    } else {
        convertError = 1;
    }
    return convertError;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {

}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {

}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {

}
