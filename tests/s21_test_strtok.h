#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_strtok_test1) {
  char string[] = "Hello there";
  char string2[] = "H";
  ck_assert_str_eq(s21_strtok(string, string2), strtok(string, string2));
}
END_TEST

START_TEST(s21_strtok_test2) {
  char string[] = "Hello there";
  char string2[] = "e";
  ck_assert_str_eq(s21_strtok(string, string2), strtok(string, string2));
}
END_TEST
START_TEST(s21_strtok_test3) {
  char string[] = "Hello there!";
  char string2[] = "!";
  ck_assert_str_eq(s21_strtok(string, string2), strtok(string, string2));
}
END_TEST

START_TEST(s21_strtok_test4) {
  char string[] = "Hello there";
  char string2[] = "le";
  ck_assert_str_eq(s21_strtok(string, string2), strtok(string, string2));
}
END_TEST

START_TEST(s21_strtok_test5) {
  char string[] = "";
  char string2[] = "Hello";
  ck_assert_ptr_null(s21_strtok(string, string2));
  ck_assert_ptr_null(strtok(string, string2));
}
END_TEST

START_TEST(s21_strtok_test6) {
  char string[] = "\0";
  char string2[] = "Hello";
  ck_assert_ptr_null(s21_strtok(string, string2));
  ck_assert_ptr_null(strtok(string, string2));
}
END_TEST

START_TEST(s21_strtok_test7) {
  char string[] = "";
  char string2[] = "";
  ck_assert_ptr_null(s21_strtok(string, string2));
  ck_assert_ptr_null(strtok(string, string2));
}
END_TEST

START_TEST(s21_strtok_test8) {
  char string[] = "tretre";
  char string2[] = "\0";
  ck_assert_str_eq(s21_strtok(string, string2), strtok(string, string2));
}
END_TEST

START_TEST(s21_strtok_test9) {
  char string[] = "Hello there";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strtok(string, string2), strtok(string, string2));
}
END_TEST

START_TEST(s21_strtok_test10) {
  char string[] = "abcdefe";
  char string2[] = "ei";
  ck_assert_str_eq(s21_strtok(string, string2), strtok(string, string2));
}
END_TEST

START_TEST(s21_strtok_test11) {
  char string[] = "tytuty";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strtok(string, string2), strtok(string, string2));
}
END_TEST

START_TEST(s21_strtok_test12) {
  char string[] = "a";
  char string2[] = "a\203";
  ck_assert_ptr_null(s21_strtok(string, string2));
  ck_assert_ptr_null(strtok(string, string2));
}
END_TEST

START_TEST(s21_strtok_test13) {
  char string[] = "a\003";
  char string2[] = "a\203";
  ck_assert_str_eq(s21_strtok(string, string2), strtok(string, string2));
}
END_TEST

START_TEST(s21_strtok_test14) {
  char string[] = "a\203";
  char string2[] = "a\203";
  ck_assert_ptr_null(s21_strtok(string, string2));
  ck_assert_ptr_null(strtok(string, string2));
}
END_TEST

START_TEST(s21_strtok_test15) {
  char str[80] = "This is - https://edu.21-school.ru/calendar - school website";
  char str2[80] =
      "This is - https://edu.21-school.ru/calendar - school website";
  const char s[4] = " - ";
  char *token = s21_strtok(str, s);
  char *token2 = strtok(str2, s);
  ck_assert_str_eq(token, token2);
  while (token != NULL) {
    ck_assert_str_eq(token, token2);
    token = s21_strtok(NULL, s);
    token2 = strtok(NULL, s);
  }
}
END_TEST

START_TEST(s21_strtok_test16) {
  char str[80] = "This is - https://edu.21-school.ru/calendar - school website";
  char str2[80] =
      "This is - https://edu.21-school.ru/calendar - school website";
  const char s[4] = "-";
  char *token = s21_strtok(str, s);
  char *token2 = strtok(str2, s);
  ck_assert_str_eq(token, token2);
  while (token != NULL) {
    ck_assert_str_eq(token, token2);
    token = s21_strtok(NULL, s);
    token2 = strtok(NULL, s);
  }
}
END_TEST

START_TEST(s21_strtok_test17) {
  char str[80] = "This  is  two  spaces  between";
  char str2[80] = "This  is  two  spaces  between";
  const char s[4] = " ";
  char *token = s21_strtok(str, s);
  char *token2 = strtok(str2, s);
  ck_assert_str_eq(token, token2);
  while (token != NULL) {
    ck_assert_str_eq(token, token2);
    token = s21_strtok(NULL, s);
    token2 = strtok(NULL, s);
  }
}
END_TEST

START_TEST(s21_strtok_test18) {
  char str[80] = "This  is  two  spaces  between";
  char str2[80] = "This  is  two  spaces  between";
  const char s[4] = " ";
  char *token = s21_strtok(str, s);
  char *token2 = strtok(str2, s);
  ck_assert_str_eq(token, token2);
  while (token != NULL) {
    ck_assert_str_eq(token, token2);
    token = s21_strtok(NULL, s);
    token2 = strtok(NULL, s);
  }
}
END_TEST
START_TEST(s21_strtok_test19) {
  char str[80] = " Spaces in begin and at the end ";
  char str2[80] = " Spaces in begin and at the end ";
  const char s[4] = " ";
  char *token = s21_strtok(str, s);
  char *token2 = strtok(str2, s);
  ck_assert_str_eq(token, token2);
  while (token != NULL) {
    ck_assert_str_eq(token, token2);
    token = s21_strtok(NULL, s);
    token2 = strtok(NULL, s);
  }
}
END_TEST
START_TEST(s21_strtok_test20) {
  char str[80] = "A lot of spaces at the end   ";
  char str2[80] = "A lot of spaces at the end   ";
  const char s[4] = " ";
  char *token = s21_strtok(str, s);
  char *token2 = strtok(str2, s);
  ck_assert_str_eq(token, token2);
  while (token != NULL) {
    ck_assert_str_eq(token, token2);
    token = s21_strtok(NULL, s);
    token2 = strtok(NULL, s);
  }
}
END_TEST

START_TEST(s21_strtok_test21) {
  char s1[] = "Hello,       world! And other people";
  char s2[] = "Hello,       world! And other people";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " o";
  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(s21_strtok_test22) {
  char s1[] = "Hello,      worllllllllllld! And lother people      ";
  char s2[] = "Hello,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " l";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(s21_strtok_test23) {
  char s1[] = "Helllllllo,      worllllllllllld! And lother people      ,,,,,";
  char s2[] = "Helllllllo,      worllllllllllld! And lother people      ,,,,";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = "l";
  char s6[] = " ,";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
  }
  ck_assert_pstr_eq(strtok(s3, s6), s21_strtok(s4, s6));
  ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
  ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
}
END_TEST

START_TEST(s21_strtok_test24) {
  char s1[] = "MYPHONENUM68697317172648";
  char s2[] = "MYPHONENUM68697317172648";
  char s3[] = "MYPHONENUM6869";
  char *s4 = strtok(s1, s3);
  char *s6 = strtok(S21_NULL, s3);

  char *s5 = s21_strtok(s2, s3);
  char *s7 = s21_strtok(S21_NULL, s3);

  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s4, s5);
  ck_assert_pstr_eq(s6, s7);
}
END_TEST

Suite *

strtok_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("strtok");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strtok_test1);
  tcase_add_test(tc_core, s21_strtok_test2);
  tcase_add_test(tc_core, s21_strtok_test3);
  tcase_add_test(tc_core, s21_strtok_test4);
  tcase_add_test(tc_core, s21_strtok_test5);
  tcase_add_test(tc_core, s21_strtok_test6);
  tcase_add_test(tc_core, s21_strtok_test7);
  tcase_add_test(tc_core, s21_strtok_test8);
  tcase_add_test(tc_core, s21_strtok_test9);
  tcase_add_test(tc_core, s21_strtok_test10);
  tcase_add_test(tc_core, s21_strtok_test11);
  tcase_add_test(tc_core, s21_strtok_test12);
  tcase_add_test(tc_core, s21_strtok_test13);
  tcase_add_test(tc_core, s21_strtok_test14);
  tcase_add_test(tc_core, s21_strtok_test15);
  tcase_add_test(tc_core, s21_strtok_test16);
  tcase_add_test(tc_core, s21_strtok_test17);
  tcase_add_test(tc_core, s21_strtok_test18);
  tcase_add_test(tc_core, s21_strtok_test19);
  tcase_add_test(tc_core, s21_strtok_test20);
  tcase_add_test(tc_core, s21_strtok_test21);
  tcase_add_test(tc_core, s21_strtok_test22);
  tcase_add_test(tc_core, s21_strtok_test23);
  tcase_add_test(tc_core, s21_strtok_test24);

  suite_add_tcase(s, tc_core);
  return s;
}
