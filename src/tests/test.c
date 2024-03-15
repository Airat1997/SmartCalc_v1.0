#include <check.h>
#include "../SmartCalc2.h"

START_TEST(calc1) {
  char* str = "2+10*5-23\0";
  long double reza = run_calc(str);
  ck_assert_double_eq(reza, 29);
}
END_TEST

START_TEST(calc2) {
  char* str = "2^acos(1)\0";
  long double reza = run_calc(str);
  ck_assert_double_eq(reza, 1);
}
END_TEST

START_TEST(calc3) {
  char* str = "sin(2-243*(25341/5)*322-34-(52*23+(1/2)/31+411)-2)^2+cos(2-1)^2-sin(2-243*(25341/5)*322-34-(sin(2-243*(25341/5)*322-34-(52*23+(1/2)/31+411)-2)^2+cos(2-1)^2)-(52*23+(1/2)/31+411)-2)^2+cos(2-1)^2\0";
  long double reza = run_calc(str);
  ck_assert_double_eq_tol(reza, 1.10734, 1e-6);
}
END_TEST

START_TEST(calc4) {
  char* str = "tan(2)\0";
  long double reza = run_calc(str);
  ck_assert_double_eq_tol(reza, -2.18504, 1e-6);
}
END_TEST

START_TEST(calc5) {
  char* str = "1mod2\0";
  long double reza = run_calc(str);
  ck_assert_double_eq_tol(reza, 1, 1e-6);
}
END_TEST

START_TEST(calc6) {
  char* str = "8*(-1)\0";
  long double reza = run_calc(str);
  ck_assert_double_eq_tol(reza, -8, 1e-6);
}
END_TEST

START_TEST(calc7) {
  char* str = "sqrt(4)+asin(1)-log(2)+ln(2)\0";
  long double reza = run_calc(str);
  ck_assert_double_eq_tol(reza, 3.962913, 1e-6);
}
END_TEST

START_TEST(calc8) {
  char* str = "1+atan(5)\0";
  long double reza = run_calc(str);
  ck_assert_double_eq_tol(reza, 2.37340, 1e-6);
}
END_TEST

START_TEST(calc9) {
  char* str = "1+atan(5)\0";
  int reza = input_validate(str);
  ck_assert_int_eq(reza, 0);
}
END_TEST

START_TEST(calc10) {
  char* str = "1+(atan(5)\0";
  int reza = input_validate(str);
  ck_assert_int_eq(reza, 1);
}
END_TEST

START_TEST(calc11) {
  char* str = "-2+10\0";
  long double reza = run_calc(str);
  ck_assert_double_eq(reza, 8);
}
END_TEST

START_TEST(calc12) {
  char* str = "+2+10\0";
  long double reza = run_calc(str);
  ck_assert_double_eq(reza, 12);
}
END_TEST

START_TEST(calc13) {
  char* str = "(-2)*10\0";
  long double reza = run_calc(str);
  ck_assert_double_eq(reza, -20);
}
END_TEST

START_TEST(calc14) {
  char* str = "10*(+2)\0";
  long double reza = run_calc(str);
  ck_assert_double_eq(reza, 20);
}
END_TEST

START_TEST(credit1) {
  double reza = FirstPayAnn(100000,5,10);
  ck_assert_ldouble_eq_tol(reza, 10230.6, 6);
}
END_TEST

START_TEST(credit2) {
  
  double reza = AllPayAnn(100000,5,10);
  ck_assert_ldouble_eq_tol(reza, 102306, 6);
}
END_TEST

START_TEST(credit3) {
  
  double reza = FirstPayDif(100000,5,10,0);
  ck_assert_double_eq_tol(reza, 10416.67, 6);
}
END_TEST

START_TEST(credit4) {
  double reza = AllPayDif(100000,5,10);
  ck_assert_double_eq_tol(reza, 102291.67, 6);
}
END_TEST

int main() {
  Suite *s1 = suite_create("s21_SmartCalc");
  TCase *tc1_1 = tcase_create("s21_SmartCalc");
  SRunner *sr = srunner_create(s1);
  int nf = 0;
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, calc1);
  tcase_add_test(tc1_1, calc2);
  tcase_add_test(tc1_1, calc3);
  tcase_add_test(tc1_1, calc4);
  tcase_add_test(tc1_1, calc5);
  tcase_add_test(tc1_1, calc6);
  tcase_add_test(tc1_1, calc7);
  tcase_add_test(tc1_1, calc8);
  tcase_add_test(tc1_1, calc9);
  tcase_add_test(tc1_1, calc10);
  tcase_add_test(tc1_1, calc11);
  tcase_add_test(tc1_1, calc12);
  tcase_add_test(tc1_1, calc13);
  tcase_add_test(tc1_1, calc14);
  tcase_add_test(tc1_1, credit1);
  tcase_add_test(tc1_1, credit2);
  tcase_add_test(tc1_1, credit3);
  tcase_add_test(tc1_1, credit4);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
