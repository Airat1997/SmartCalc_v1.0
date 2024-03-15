#include "stack.h"

void push(calc_stack* A, char token) {
  A->token[A->length] = token;
  A->length++;
}

char pop(calc_stack* A) {
  A->length--;
  return A->token[A->length];
}

void push2(calc_stack_num* A, double token) {
  A->num[A->length] = token;
  A->length++;
}

long double pop2(calc_stack_num* A) {
  A->length--;
  return A->num[A->length];
}

void initialize(calc_stack* A) {
  A->length = 0;
  A->token[UP] = '0';
}