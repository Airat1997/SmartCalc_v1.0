#ifndef SMARTCALC2_H
#define SMARTCALC2_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculator/credit.h"
#include "calculator/helper_func.h"
#include "calculator/stack.h"

long double run_calc(const char* str);
char* convert_in_polish(char* str, char* reza, calc_stack* A);
long double calc_polish(char* str);
void choise_operand(char* str, calc_stack_num* A, long double operand1,
                    long double operand2, long double triagnometry, int i);
void finaliz_polish(char* reza, calc_stack* A, int* j);
int unary_minus(char* str, char* reza, int* i, int* j, int* end_str);
int unary_plus(char* str, char* reza, int* i, int* j, int* end_str);
void one_unary(char* str, char* reza, int* i, int* j);
#endif
