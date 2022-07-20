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
    int convertError = 0;
    if (dst) {
        memset(dst, 0, INT_SIZE);
        if ((fabsf(src) > 0 && fabsf(src) < 1e-28) /*|| fabsf(src) > MAX_DECIMAL*/ || S21_IS_INF(src)) {
            convertError = 1;
        } else {
            if (__builtin_signbit(src)) set_neg_bit(dst);
            src = fabsf(src);
            float _int;
            modff(src, &_int);
            // printf("_int: %f\n", _int);
            int count = 0;
            for (float _int_cp = _int; _int_cp >= 1.0; count++)
                _int_cp /= 10.0;
            if (!count) count++;
            int cpy = count;
            count += (28 + 1 + 1);
            // printf("count = %d\n", count);
            char *str = malloc(count);
            str[count - 1] = '\0';
            sprintf(str, "%.28f", src);
            // for (int k = 0; k < count - 1; k++)
            //     printf("%d: %c\n", k, str[k]);
            int i = 0;
            if (*str == '0') {
                i += 2;
                while (str[i] == '0') {
                    i++;
                }
            }
            int j = count - 2;
            while (str[j] == '0') {
                str[j--] = '\0';
                if (str[j] == '.') str[j] = 0;
            }
            printf("str:     %s\n", str);
            char *point = strchr(str, '.');
            int m = 0;
            if (point)
                m = strlen(point + 1);
            char *new_str = malloc(strlen(str) + 1);
            strcpy(new_str, str + i);
            free(str);
            i -= 2;
            printf("new_str: %s\n", new_str);
            printf("m = %d\n", m);
            put_exp_in_decimal(dst, m);
        }
    } else {
        convertError = 1;
    }
    return convertError;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int convertError = 0;
    if (dst) {
        if (!check_int_overflow(&src)) {
            if (check_sign(&src)) {
                *dst = -src.bits[0];
            } else {
                *dst = src.bits[0];
            }
        } else {
            convertError = DATA_OVERFLOW;
        }
    } else {
        convertError = 1;
    }
    return convertError;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {

}
