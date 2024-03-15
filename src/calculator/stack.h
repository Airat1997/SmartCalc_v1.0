#ifndef STACK_H
#define STACK_H
#define MAX_SIZE_LABEL 255

#define UP A->length - 1

typedef struct stack_struct {
  char token[10];
  int length;
} calc_stack;

typedef struct stack_struct_num {
  long double num[10];
  int length;
} calc_stack_num;

void push(calc_stack* A, char token);
char pop(calc_stack* A);

void push2(calc_stack_num* A, double token);
long double pop2(calc_stack_num* A);

void initialize(calc_stack* A);
#endif
