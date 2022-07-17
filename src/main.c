#include <stdio.h>
#include <math.h>
#include "s21_decimal.h"

/* - from -79,228,162,514,264,337,593,543,950,335 to 79,228,162,514,264,337,593,543,950,335
   - default decimal == 0
   - 1-разр знак, 96-разр целое число и коэф масштабирования
   - коэф масштабир неявно равен 10 в степени от 0 до 28
*/

int main() {
    s21_decimal num;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 32; j++)
            clearbit(num.bits[i], j);
    int a = INT32_MAX;
    s21_from_int_to_decimal(a, &num);
    for(int i = 3; i >= 0; i--) {
        for (int j = 31; j >= 0; j--)
            printf("%d", findbit(num.bits[i], j));
        printf(" ");
    }
    return 0;
}
