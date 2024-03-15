#include "helper_func.h"

char* reduction_math_func(char* str) {
  char* str_reza = (char*)calloc(510, sizeof(char));
  int j = 0;
  for (int i = 0; i < (int)strlen(str); i++, j++) {
    if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'n') {
      str_reza[j] = 's';
      i += 2;
    } else if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's') {
      str_reza[j] = 'c';
      i += 2;
    } else if (str[i] == 't' && str[i + 1] == 'a' && str[i + 2] == 'n') {
      str_reza[j] = 't';
      i += 2;
    } else if (str[i] == 'a' && str[i + 1] == 'c' && str[i + 2] == 'o') {
      str_reza[j] = 'a';
      i += 3;
    } else if (str[i] == 'a' && str[i + 1] == 's' && str[i + 2] == 'i') {
      str_reza[j] = 'n';
      i += 3;
    } else if (str[i] == 'a' && str[i + 1] == 't' && str[i + 2] == 'a') {
      str_reza[j] = 'g';
      i += 3;
    } else if (str[i] == 's' && str[i + 1] == 'q' && str[i + 2] == 'r') {
      str_reza[j] = 'q';
      i += 3;
    } else if (str[i] == 'l' && str[i + 1] == 'n') {
      str_reza[j] = 'l';
      i += 1;
    } else if (str[i] == 'l' && str[i + 1] == 'o' && str[i + 2] == 'g') {
      str_reza[j] = 'o';
      i += 2;
    } else if (str[i] == 'm' && str[i + 1] == 'o' && str[i + 2] == 'd') {
      str_reza[j] = 'm';
      i += 2;
    } else {
      str_reza[j] = str[i];
    }
  }
  str_reza[j] = '\0';
  return str_reza;
}

int get_priority(char oper) {
  int priority = 0;
  switch (oper) {
    case '+':
    case '-':
      priority = 1;
      break;
    case '*':
    case '/':
      priority = 2;
      break;
    case '^':
      priority = 3;
      break;
    case 's':  // sin
    case 'c':  // cos
    case 't':  // tan
    case 'a':  // acos
    case 'n':  // asin
    case 'g':  // atan
    case 'q':  // sqrt
    case 'l':  // ln
    case 'o':  // log
    case 'm':  // mod
      priority = 4;
      break;
    case '(':
      priority = 5;
      break;
  }
  return priority;
}

int input_validate(const char* str) {
  int left_bracket = 0, right_bracket = 0, reza = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] == '(') left_bracket++;
    if (str[i] == ')') right_bracket++;
    if (left_bracket == 0 && right_bracket > 0) {
      reza = 1;
      break;
    }
  }
  if (left_bracket != right_bracket) reza = 1;
  return reza;
}

void remove_spaces(char* str) {
  int i = 0, j = 0;
  int space = 0;
  for (; i < (int)strlen(str); i++) {
    if (str[i] == ' ') {
      if (space) continue;
      space = 1;
    } else
      space = 0;
    str[j++] = str[i];
  }
  str[j] = '\0';
}