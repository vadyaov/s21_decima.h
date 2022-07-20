#include "s21_decimal.h"

/* - from -79,228,162,514,264,337,593,543,950,335 to 79,228,162,514,264,337,593,543,950,335
   - default decimal == 0
   - 1-разр знак, 96-разр целое число и коэф масштабирования
   - коэф масштабир неявно равен 10 в степени от 0 до 28
*/

void print_decimal(s21_decimal *number) {
    for(int i = 3; i >= 0; i--) {
        for (int j = 31; j >= 0; j--) {
            printf("%d", findbit(number->bits[i], j));
            if (j == 24 || j == 16 || j == 8) printf(" ");
        }
        printf("  ");
    }
    printf("\n");
}
// 00000000 00000000 00000000 00000000 - 0
// 00000000 00001111 00000000 00000000 - 
// 28 - 0x1c0000
// 27 - 0x1b0000
// 26 - 0x1a0000
// 25 - 0x190000
// 24 - 0x180000
// 23 - 0x170000
// 22 - 0x160000
// 21 - 0x150000
// 20 - 0x140000
// 19 - 0x130000
// 18 - 0x120000
// 17 - 0x110000
// 16 - 0x100000
// 15 - 0xf0000
// 14 - 0xe0000
// 13 - 0xd0000
// 12 - 0xc0000
// 11 - 0xb0000
// 10 - 0xa0000
//  9 - 0x90000
//  8 - 0x80000
//  7 - 0x70000
//  6 - 0x60000
//  5 - 0x50000
//  4 - 0x40000
//  3 - 0x30000
//  2 - 0x20000
//  1 - 0x10000
//  0 - 0x00000

int main() {
    s21_decimal num;
    float a = 11111;
    printf("a = %.28f\n", a);
    printf("%d\n", s21_from_float_to_decimal(a, &num));
    print_decimal(&num);
    // int a = 1;
    // for (int i = 31; i >= 0; i--)
    //     printf("%d", findbit(a, i));
    // a = modbit(a, 2, 1);
    // for (int i = 31; i >= 0; i--)
    //     printf("%d", findbit(a, i));
    return 0;
}
