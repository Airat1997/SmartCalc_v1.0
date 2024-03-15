#ifndef HELPER_FUNC_H
#define HELPER_FUNC_H

#include <stdlib.h>
#include <string.h>

char* reduction_math_func(char* str);
int get_priority(char oper);
int input_validate(const char* str);
void remove_spaces(char* str);

#endif