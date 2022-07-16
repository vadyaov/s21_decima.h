#include <stdio.h>
#include <math.h>
#include "s21_decimal.h"

/* - from -79,228,162,514,264,337,593,543,950,335 to 79,228,162,514,264,337,593,543,950,335
   - default decimal == 0
   - 1-разр знак, 96-разр целое число и коэф масштабирования
   - коэф масштабир неявно равен 10 в степ от 0 до 28
*/

int main() {
    int a = 127;
    for (int i = 31; i >= 0; i--)
        printf("%d", findbit(a, i));
    // for (int i = 0; i < 32; i++)
        a = modbit(a, 31, 1);
    printf("\n");
    for (int i = 31; i >= 0; i--)
        printf("%d", findbit(a, i));
    printf("\na = %d", a);
    return 0;
}
