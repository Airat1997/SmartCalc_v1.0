#include "SmartCalc2.h"

long double run_calc(const char* str) {
  calc_stack A;
  initialize(&A);
  char* str2 = (char*)str;
  long double result = 0;
  char reza[510] = {'\0'};
  convert_in_polish(str2, reza, &A);
  result = calc_polish(reza);
  return result;
}

char* convert_in_polish(char* str, char* reza, calc_stack* A) {
  int j = 0;
  int end_str = 0;
  str = reduction_math_func(str);
  for (int i = 0; i < (int)strlen(str); i++, j++) {
    if (i == 0) one_unary(str, reza, &i, &j);
    if (unary_plus(str, reza, &i, &j, &end_str)) break;
    if (unary_minus(str, reza, &i, &j, &end_str)) break;
    if (isdigit(str[i]) || str[i] == '.') {
      reza[j] = str[i];
    } else {
      if (get_priority(str[i]) > 0 &&
          get_priority(str[i]) > get_priority(A->token[UP]))
        push(A, str[i]);
      else if (get_priority(str[i]) <= get_priority(A->token[UP])) {
        if (A->token[UP] != '(' && str[i] != ')') {
          while (get_priority(str[i]) <= get_priority(A->token[UP])) {
            if (A->token[UP] == '(') {
              break;
            }
            reza[j++] = ' ';
            reza[j++] = A->token[UP];
            pop(A);
          }
        } else if (str[i] == ')') {
          while (A->token[UP] != '(') {
            reza[j++] = ' ';
            reza[j++] = A->token[UP];
            pop(A);
          }
          pop(A);  // чтобы убрать ( из стека
          if (strchr("sctangqlo",
                     A->token[UP])) {  // обработка тригонометрии sin( cos(
            reza[j++] = ' ';
            reza[j++] = A->token[UP];
            pop(A);
          }
        }
        if (str[i] != ')') push(A, str[i]);
      }
      reza[j] = ' ';
    }
  }
  finaliz_polish(reza, A, &j);
  free(str);
  return reza;
}

void one_unary(char* str, char* reza, int* i, int* j) {
  if ((str[*i] == '-' && isdigit(str[1])) ||
      (str[*i] == '+' && isdigit(str[1]))) {
    if (str[*i] == '-') {
      reza[*j] = str[*i];
      (*j)++;
      (*i)++;
    } else if (str[*i] == '+')
      (*i)++;
    while (isdigit(str[*i]) || str[*i] == '.') {
      reza[*j] = str[*i];
      (*j)++;
      (*i)++;
    }
  }
}

int unary_minus(char* str, char* reza, int* i, int* j, int* end_str) {
  if (str[(*i)] == '(' && str[(*i) + 1] == '-') {
    (*i)++;
    while (str[(*i)] != ')') {
      reza[(*j)++] = str[(*i)++];
    }
    if (str[(*i) + 1] != '\0')
      (*i)++;
    else
      *end_str = 1;
  }
  return *end_str;
}

int unary_plus(char* str, char* reza, int* i, int* j, int* end_str) {
  if (str[(*i)] == '(' && str[(*i) + 1] == '+') {
    (*i) = (*i) + 2;
    while (str[(*i)] != ')') {
      reza[(*j)++] = str[(*i)++];
    }
    if (str[(*i) + 1] != '\0')
      (*i)++;
    else
      *end_str = 1;
  }
  return *end_str;
}

void finaliz_polish(char* reza, calc_stack* A, int* j) {
  while (A->length != 0) {
    reza[(*j)++] = ' ';
    reza[(*j)++] = pop(A);
  }
  remove_spaces(reza);
}

long double calc_polish(char* str) {
  calc_stack_num A = {0};
  char str_atoi[20] = {'\0'};
  for (int i = 0; i < (int)strlen(str); i++) {
    if (isdigit(str[i]) || (str[i] == '-' && isdigit(str[i + 1]))) {
      int j = 0;
      while ((str[i] != ' ')) {
        str_atoi[j++] = str[i++];
        if (i == (int)strlen(str)) {
          break;
        }
      }
      str_atoi[j] = '\0';
      push2(&A, atof(str_atoi));
      memset(str_atoi, 0, sizeof(str_atoi));
    }
    if (strchr("m+-*/^sctangqlo", str[i]) && str[i] != '\0') {
      long double operand2 = 0, operand1 = 0, triagnometry = 0;
      if (strchr("sctangqlo", str[i]) && str[i] != '\0') {
        triagnometry = pop2(&A);
      } else {
        operand2 = pop2(&A);
        operand1 = pop2(&A);
      }
      choise_operand(str, &A, operand1, operand2, triagnometry, i);
    }
  }
  return pop2(&A);
}

void choise_operand(char* str, calc_stack_num* A, long double operand1,
                    long double operand2, long double triagnometry, int i) {
  switch (str[i]) {
    case '+':
      push2(A, operand1 + operand2);
      break;
    case '-':
      push2(A, operand1 - operand2);
      break;
    case '*':
      push2(A, operand1 * operand2);
      break;
    case '/':
      push2(A, operand1 / operand2);
      break;
    case 's':
      push2(A, sin(triagnometry));
      break;
    case 'c':
      push2(A, cos(triagnometry));
      break;
    case 't':
      push2(A, tan(triagnometry));
      break;
    case 'a':
      push2(A, acos(triagnometry));
      break;
    case 'n':
      push2(A, asin(triagnometry));
      break;
    case 'g':
      push2(A, atan(triagnometry));
      break;
    case 'q':
      push2(A, sqrt(triagnometry));
      break;
    case 'l':
      push2(A, log(triagnometry));
      break;
    case 'o':
      push2(A, log10(triagnometry));
      break;
    case '^':
      push2(A, powl(operand1, operand2));
      break;
    case 'm':
      push2(A, remainder(operand1, operand2));
      break;
  }
}
