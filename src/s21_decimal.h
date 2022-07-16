#ifndef _S21_DECIMAL_H_
#define _S21_DECIMAL_H_

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

#endif  // _S21_DECIMAL_H_