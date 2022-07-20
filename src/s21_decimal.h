#ifndef _S21_DECIMAL_H_
#define _S21_DECIMAL_H_

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// #include <float.h>

#define INT_SIZE __CHAR_BIT__ * 4
#define _SIGNBIT_POS 31
#define DATA_OVERFLOW 1
#define MAX_DECIMAL 79228162514264337593543950335.0f
static const int exp_mask_bits3[29] = {0x00000, 0x10000, 0x20000, 0x30000, 0x40000, 0x50000, 0x60000, 0x70000, 0x80000, 0x90000,
                          0xa0000, 0xb0000, 0xc0000, 0xd0000, 0xe0000, 0xf0000, 0x100000, 0x110000, 0x120000, 0x130000,
                          0x140000, 0x150000, 0x160000, 0x170000, 0x180000, 0x190000, 0x1a0000, 0x1b0000, 0x1c0000};

/** 
  * returns float infinite value
  * This function is suitable for implementing the ISO C99 macro INFINITY
  */ 
#define S21_HUGE_VAL (__builtin_inff())
/**
  * returns float NaN value
  */
#define S21_NAN_VAL (__builtin_nanf(""))
/**
  * check for infinity: returns 1 if infinite, -1 if -infinite and 0 if finite
  */
#define S21_IS_INF(x) __builtin_isinf_sign(x)
/**
 * check for nan value: returns 1 if NaN and 0 if not 
 */
#define S21_IS_NAN(x) __builtin_isnan(x)

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
int check_sign(s21_decimal *dst);                       // проверка бита знака
int check_int_overflow(s21_decimal *dst);               // проверка на переполнение int
void put_exp_in_decimal(s21_decimal *dst, int e);

// converters
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);

#endif  // _S21_DECIMAL_H_