#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../headers/s21_sscanf.h"
#include "s21_test.h"

#endif

START_TEST(s21_sscanf_test1) {
  char orig_buffer[] = "1212";
  char orig_format[] = "%d%d";
  int orig_var1 = 0;
  int orig_var2 = 0;
  int test_var1 = 0;
  int test_var2 = 0;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2);
  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
}

END_TEST

START_TEST(s21_sscanf_test2) {
  char orig_buffer[] = "123123";
  char orig_format[] = "%d%d";
  int orig_var1 = 0;
  int orig_var2 = 0;
  int test_var1 = 0;
  int test_var2 = 0;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2);
  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
}

END_TEST

START_TEST(s21_sscanf_test3) {
  char orig_buffer[] = "12341234";
  char orig_format[] = "%d%d";
  int orig_var1 = 0;
  int orig_var2 = 0;
  int test_var1 = 0;
  int test_var2 = 0;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2);
  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
}

END_TEST

START_TEST(s21_sscanf_test4) {
  char orig_buffer[] = "1234 1234";
  char orig_format[] = "%d%d";
  int orig_var1 = 0;
  int orig_var2 = 0;
  int test_var1 = 0;
  int test_var2 = 0;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2);
  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
}

END_TEST

START_TEST(s21_sscanf_test5) {
  char orig_buffer[] = "1234 1234";
  char orig_format[] = "%d %d";
  int orig_var1 = 0;
  int orig_var2 = 0;
  int test_var1 = 0;
  int test_var2 = 0;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2);
  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
}

END_TEST

START_TEST(s21_sscanf_test6) {
  char orig_buffer[] = "124 12123";
  char orig_format[] = "%d %d";
  int orig_var1 = 0;
  int orig_var2 = 0;
  int test_var1 = 0;
  int test_var2 = 0;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2);
  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
}

END_TEST

START_TEST(s21_sscanf_test7) {
  char orig_buffer[] = "14.123 12123";
  char orig_format[] = "%6f %d";
  float orig_var1 = 0;
  int orig_var2 = 0;
  float test_var1 = 0;
  int test_var2 = 0;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2);
  ck_assert_float_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
}

END_TEST

START_TEST(s21_sscanf_test8) {
  char orig_buffer[] = "123456.123456789 12123";
  char orig_format[] = "%100f %4d";
  float orig_var1 = 0;
  int orig_var2 = 0;
  float test_var1 = 0;
  int test_var2 = 0;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2);
  ck_assert_float_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
}

END_TEST

START_TEST(s21_sscanf_test9) {
  char orig_buffer[] = "123456.123456789999999999999999 12123.12313123";
  char orig_format[] = "%100f %4d";
  float orig_var1 = 0;
  int orig_var2 = 0;
  float test_var1 = 0;
  int test_var2 = 0;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2);
  ck_assert_float_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
}

END_TEST

START_TEST(s21_sscanf_test10) {
  char orig_buffer[] =
      "123456.123456789999999999999999 12123 0x100 0X12FFF FFFFF";
  char orig_format[] = "%100f %d %x %x %x";
  float orig_var1 = 0;
  int orig_var2 = 0;
  int orig_var3 = 0;
  int orig_var4 = 0;
  int orig_var5 = 0;

  float test_var1 = 0;
  int test_var2 = 0;
  int test_var3 = 0;
  int test_var4 = 0;
  int test_var5 = 0;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3,
         &orig_var4, &orig_var5);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3,
             &test_var4, &test_var5);
  ck_assert_float_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
  ck_assert_int_eq(orig_var3, test_var3);
  ck_assert_int_eq(orig_var4, test_var4);
  ck_assert_int_eq(orig_var5, test_var5);
}

END_TEST

START_TEST(s21_sscanf_test11) {
  char orig_buffer[] =
      "123456.123456789999999999999999 12123.12313123 0x100 0X12FFF FFFFF";
  char orig_format[] = "%100f %f %X %X %X";
  float orig_var1 = 0;
  float orig_var2 = 0;
  int orig_var3 = 0;
  int orig_var4 = 0;
  int orig_var5 = 0;

  float test_var1 = 0;
  float test_var2 = 0;
  int test_var3 = 0;
  int test_var4 = 0;
  int test_var5 = 0;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3,
         &orig_var4, &orig_var5);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3,
             &test_var4, &test_var5);
  ck_assert_float_eq(orig_var1, test_var1);
  ck_assert_float_eq(orig_var2, test_var2);
  ck_assert_int_eq(orig_var3, test_var3);
  ck_assert_int_eq(orig_var4, test_var4);
  ck_assert_int_eq(orig_var5, test_var5);
}

END_TEST

START_TEST(s21_sscanf_test12) {
  char orig_buffer[] =
      "+123456.123456789999999999999999 -12123.12313123 +0x100 -0X12FFF +FFFFF";
  char orig_format[] = "%100f %f %X %X %X";
  float orig_var1 = 0;
  float orig_var2 = 0;
  int orig_var3 = 0;
  int orig_var4 = 0;
  int orig_var5 = 0;

  float test_var1 = 0;
  float test_var2 = 0;
  int test_var3 = 0;
  int test_var4 = 0;
  int test_var5 = 0;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3,
         &orig_var4, &orig_var5);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3,
             &test_var4, &test_var5);
  ck_assert_float_eq(orig_var1, test_var1);
  ck_assert_float_eq(orig_var2, test_var2);
  ck_assert_int_eq(orig_var3, test_var3);
  ck_assert_int_eq(orig_var4, test_var4);
  ck_assert_int_eq(orig_var5, test_var5);
}

END_TEST

START_TEST(s21_sscanf_test13) {
  char orig_buffer[] = "string 0x100";
  char orig_format[] = "string %x";
  int orig_var1 = 0;

  int test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_int_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test14) {
  char orig_buffer[] = "string 0x111111";
  char orig_format[] = "string %x";
  int orig_var1 = 0;

  int test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_int_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test15) {
  char orig_buffer[] = "string 0xFFFFFF";
  char orig_format[] = "string %x";
  int orig_var1 = 0;

  int test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_int_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test16) {
  char orig_buffer[] = "string 0xFFFFFF";
  char orig_format[] = "nonExistString %x";
  int orig_var1 = 0;

  int test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_int_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test17) {
  char orig_buffer[] = "string nonExistValue";
  char orig_format[] = "nonExistString %x";
  int orig_var1 = 0;

  int test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_int_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test18) {
  char orig_buffer[] = "string nonExistValue";
  char orig_format[] = "string %x";
  int orig_var1 = 0;

  int test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_int_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test19) {
  char orig_buffer[] = "string";
  char orig_format[] = "string %x";
  int orig_var1 = 0;

  int test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_int_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test20) {
  char orig_buffer[] = "string 111111AA1FF11";
  char orig_format[] = "string %100x";
  int orig_var1 = 0;

  int test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_int_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test21) {
  char orig_buffer[] =
      "num: 0x441, num: 155.99, num: 1.005, char: C, string: HelloThere!";
  char orig_format[] = "num: %x, num: %f, num: %lf, char: %c, string: %s";
  int orig_var1 = 0;
  float orig_var2 = 0;
  double orig_var3 = 0;
  char orig_var4 = 0;
  char orig_var5[100] = {0};

  int test_var1 = 0;
  float test_var2 = 0;
  double test_var3 = 0;
  char test_var4 = 0;
  char test_var5[100] = {0};

  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3,
         &orig_var4, orig_var5);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3,
             &test_var4, test_var5);
  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_float_eq(orig_var2, test_var2);
  ck_assert_double_eq(orig_var3, test_var3);
  ck_assert_int_eq(orig_var4, test_var4);
  ck_assert_str_eq(orig_var5, test_var5);
}

END_TEST

START_TEST(s21_sscanf_test22) {
  char orig_buffer[] =
      "num: 0x441 num: 155.99 num: 1.005 char: C string: HelloThere!";
  char orig_format[] =
      "num: %x    num: %f     num: %lf      char: %c     string: %s";
  int orig_var1 = 0;
  float orig_var2 = 0;
  double orig_var3 = 0;
  char orig_var4 = 0;
  char orig_var5[100] = {0};

  int test_var1 = 0;
  float test_var2 = 0;
  double test_var3 = 0;
  char test_var4 = 0;
  char test_var5[100] = {0};

  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3,
         &orig_var4, orig_var5);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3,
             &test_var4, test_var5);
  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_float_eq(orig_var2, test_var2);
  ck_assert_double_eq(orig_var3, test_var3);
  ck_assert_int_eq(orig_var4, test_var4);
  ck_assert_str_eq(orig_var5, test_var5);
}

END_TEST

START_TEST(s21_sscanf_test23) {
  char orig_buffer[] =
      "num: 0x441 num: 155.99 num: 1.005 char: C string: HelloThere!";
  char orig_format[] =
      "num: %x           num: %f               num: %lf                 char: "
      "%c                 string: %s";
  int orig_var1 = 0;
  float orig_var2 = 0;
  double orig_var3 = 0;
  char orig_var4 = 0;
  char orig_var5[100] = {0};

  int test_var1 = 0;
  float test_var2 = 0;
  double test_var3 = 0;
  char test_var4 = 0;
  char test_var5[100] = {0};

  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3,
         &orig_var4, orig_var5);
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3,
             &test_var4, test_var5);
  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_float_eq(orig_var2, test_var2);
  ck_assert_double_eq(orig_var3, test_var3);
  ck_assert_int_eq(orig_var4, test_var4);
  ck_assert_str_eq(orig_var5, test_var5);
}

END_TEST

START_TEST(s21_sscanf_test24) {
  char orig_buffer[] = "num: 441";
  char orig_format[] = "num: %u";
  unsigned int orig_var1 = 0;
  unsigned int test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_int_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test25) {
  char orig_buffer[] = "num: 441   ";
  char orig_format[] = "num: %u      ";
  unsigned int orig_var1 = 0;

  unsigned int test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_int_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test26) {
  char orig_buffer[] =
      "num: 441 num: 959 num: 555 num: 111 num: 441 num: 959 num: 555 num: "
      "111 ";
  char orig_format[] =
      "num: %u num: %u num: %u num: %u num: %u num: %u num: %u num: %u ";
  unsigned origArray[8] = {0};
  unsigned testArray[8] = {0};
  sscanf(orig_buffer, orig_format, &origArray[0], &origArray[1], &origArray[2],
         &origArray[3], &origArray[4], &origArray[5], &origArray[6],
         &origArray[7]);
  s21_sscanf(orig_buffer, orig_format, &testArray[0], &testArray[1],
             &testArray[2], &testArray[3], &testArray[4], &testArray[5],
             &testArray[6], &testArray[7]);

  for (int i = 0; i < 8; ++i) {
    ck_assert_int_eq(origArray[i], testArray[i]);
  }
}

END_TEST

START_TEST(s21_sscanf_test27) {
  char orig_buffer[] =
      "somestring +12345           anotherString 123       "
      "anotherAnotherString 98765";
  char orig_format[] = "somestring %6o";

  unsigned int orig_var1 = -100;
  unsigned int orig_var2 = -100;
  unsigned int orig_var3 = -100;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3);

  unsigned int test_var1 = -100;
  unsigned int test_var2 = -100;
  unsigned int test_var3 = -100;
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3);

  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
  ck_assert_int_eq(orig_var3, test_var3);
}

END_TEST
START_TEST(s21_sscanf_test28) {
  char orig_buffer[] =
      "somestring +12345           anotherString 123       "
      "anotherAnotherString 98765";
  char orig_format[] = "somestring";

  unsigned int orig_var1 = -100;
  unsigned int orig_var2 = -100;
  unsigned int orig_var3 = -100;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3);

  unsigned int test_var1 = -100;
  unsigned int test_var2 = -100;
  unsigned int test_var3 = -100;
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3);

  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
  ck_assert_int_eq(orig_var3, test_var3);
}

END_TEST
START_TEST(s21_sscanf_test29) {
  char orig_buffer[] = "";
  char orig_format[] = "";

  unsigned int orig_var1 = -100;
  unsigned int orig_var2 = -100;
  unsigned int orig_var3 = -100;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3);

  unsigned int test_var1 = -100;
  unsigned int test_var2 = -100;
  unsigned int test_var3 = -100;
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3);

  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
  ck_assert_int_eq(orig_var3, test_var3);
}

END_TEST

START_TEST(s21_sscanf_test30) {
  char orig_buffer[] = "value: 50 100 200";
  char orig_format[] = "value: %d %d %d";

  int orig_var1 = -100;
  int orig_var2 = -100;
  int orig_var3 = -100;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3);

  int test_var1 = -100;
  int test_var2 = -100;
  int test_var3 = -100;
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3);

  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
  ck_assert_int_eq(orig_var3, test_var3);
}

END_TEST

START_TEST(s21_sscanf_test31) {
  char orig_buffer[] = "value: 50 100 200";
  char orig_format[] = "value: %*d %d %d";

  int orig_var1 = -100;
  int orig_var2 = -100;
  int orig_var3 = -100;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3);

  int test_var1 = -100;
  int test_var2 = -100;
  int test_var3 = -100;
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3);

  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
  ck_assert_int_eq(orig_var3, test_var3);
}

END_TEST

START_TEST(s21_sscanf_test32) {
  char orig_buffer[] = "value: 50 100 200";
  char orig_format[] = "value: %d %*d %d";

  int orig_var1 = -100;
  int orig_var2 = -100;
  int orig_var3 = -100;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3);

  int test_var1 = -100;
  int test_var2 = -100;
  int test_var3 = -100;
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3);

  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
  ck_assert_int_eq(orig_var3, test_var3);
}

END_TEST

START_TEST(s21_sscanf_test33) {
  char orig_buffer[] = "value: 50 100 200";
  char orig_format[] = "value: %d %*d %*d";

  int orig_var1 = -100;
  int orig_var2 = -100;
  int orig_var3 = -100;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3);

  int test_var1 = -100;
  int test_var2 = -100;
  int test_var3 = -100;
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3);

  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
  ck_assert_int_eq(orig_var3, test_var3);
}

END_TEST

START_TEST(s21_sscanf_test34) {
  char orig_buffer[] = "value: 50 100 200";
  char orig_format[] = "value: %*d %*d %*d";

  int orig_var1 = -100;
  int orig_var2 = -100;
  int orig_var3 = -100;
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3);

  int test_var1 = -100;
  int test_var2 = -100;
  int test_var3 = -100;
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3);

  ck_assert_int_eq(orig_var1, test_var1);
  ck_assert_int_eq(orig_var2, test_var2);
  ck_assert_int_eq(orig_var3, test_var3);
}

END_TEST

START_TEST(s21_sscanf_test35) {
  char orig_buffer[] = "value: 50 100 200";
  char orig_format[] = "value: %*s %*s %*s";

  char orig_var1[100] = {0};
  char orig_var2[100] = {0};
  char orig_var3[100] = {0};
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3);

  char test_var1[100] = {0};
  char test_var2[100] = {0};
  char test_var3[100] = {0};
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3);

  ck_assert_str_eq(orig_var1, test_var1);
  ck_assert_str_eq(orig_var2, test_var2);
  ck_assert_str_eq(orig_var3, test_var3);
}

END_TEST

START_TEST(s21_sscanf_test36) {
  char orig_buffer[] = "value: 50 100 200";
  char orig_format[] = "value: %*s %s %*s";

  char orig_var1[100] = {0};
  char orig_var2[100] = {0};
  char orig_var3[100] = {0};
  sscanf(orig_buffer, orig_format, &orig_var1, &orig_var2, &orig_var3);

  char test_var1[100] = {0};
  char test_var2[100] = {0};
  char test_var3[100] = {0};
  s21_sscanf(orig_buffer, orig_format, &test_var1, &test_var2, &test_var3);

  ck_assert_str_eq(orig_var1, test_var1);
  ck_assert_str_eq(orig_var2, test_var2);
  ck_assert_str_eq(orig_var3, test_var3);
}

END_TEST

START_TEST(s21_sscanf_test37) {
  char orig_buffer[] = "num: 0100";
  char orig_format[] = "num: %i";
  int orig_var1 = 0;
  int test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_int_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test38) {
  char orig_buffer[] = "100";
  char orig_format[] = "%i";
  int orig_var1 = 0;
  int test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_int_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test39) {
  char orig_buffer[] = "num: 9223372036854775806";
  char orig_format[] = "num: %ld";
  long int orig_var1 = 0;
  long int test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_int_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test40) {
  char orig_buffer[] = "num: 9223372036854775806";
  char orig_format[] = "num: %lld";
  long long int orig_var1 = 0;
  long long int test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_int_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test41) {
  char orig_buffer[] = "num: 13423.1000";
  char orig_format[] = "num: %f";
  float orig_var1 = 0;
  float test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_float_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test42) {
  char orig_buffer[] = "num: 13412312423.1241241000";
  char orig_format[] = "num: %lf";
  double orig_var1 = 0;
  double test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_double_eq(orig_var1, test_var1);
}

END_TEST

START_TEST(s21_sscanf_test43) {
  char orig_buffer[] = "num: 13412312412312312323.1241231231241000";
  char orig_format[] = "num: %20Lf";
  long double orig_var1 = 0;
  long double test_var1 = 0;

  sscanf(orig_buffer, orig_format, &orig_var1);
  s21_sscanf(orig_buffer, orig_format, &test_var1);
  ck_assert_ldouble_eq(orig_var1, test_var1);
}

END_TEST

Suite *sscanf_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("sscanf");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_sscanf_test1);
  tcase_add_test(tc_core, s21_sscanf_test2);
  tcase_add_test(tc_core, s21_sscanf_test3);
  tcase_add_test(tc_core, s21_sscanf_test4);
  tcase_add_test(tc_core, s21_sscanf_test5);
  tcase_add_test(tc_core, s21_sscanf_test6);
  tcase_add_test(tc_core, s21_sscanf_test7);
  tcase_add_test(tc_core, s21_sscanf_test8);
  tcase_add_test(tc_core, s21_sscanf_test9);
  tcase_add_test(tc_core, s21_sscanf_test10);
  tcase_add_test(tc_core, s21_sscanf_test11);
  tcase_add_test(tc_core, s21_sscanf_test12);
  tcase_add_test(tc_core, s21_sscanf_test13);
  tcase_add_test(tc_core, s21_sscanf_test14);
  tcase_add_test(tc_core, s21_sscanf_test15);
  tcase_add_test(tc_core, s21_sscanf_test16);
  tcase_add_test(tc_core, s21_sscanf_test17);
  tcase_add_test(tc_core, s21_sscanf_test18);
  tcase_add_test(tc_core, s21_sscanf_test19);
  tcase_add_test(tc_core, s21_sscanf_test20);
  tcase_add_test(tc_core, s21_sscanf_test21);
  tcase_add_test(tc_core, s21_sscanf_test22);
  tcase_add_test(tc_core, s21_sscanf_test23);
  tcase_add_test(tc_core, s21_sscanf_test24);
  tcase_add_test(tc_core, s21_sscanf_test25);
  tcase_add_test(tc_core, s21_sscanf_test26);
  tcase_add_test(tc_core, s21_sscanf_test27);
  tcase_add_test(tc_core, s21_sscanf_test28);
  tcase_add_test(tc_core, s21_sscanf_test29);
  tcase_add_test(tc_core, s21_sscanf_test30);
  tcase_add_test(tc_core, s21_sscanf_test31);
  tcase_add_test(tc_core, s21_sscanf_test32);
  tcase_add_test(tc_core, s21_sscanf_test33);
  tcase_add_test(tc_core, s21_sscanf_test34);
  tcase_add_test(tc_core, s21_sscanf_test35);
  tcase_add_test(tc_core, s21_sscanf_test36);
  tcase_add_test(tc_core, s21_sscanf_test37);
  tcase_add_test(tc_core, s21_sscanf_test38);
  tcase_add_test(tc_core, s21_sscanf_test39);
  tcase_add_test(tc_core, s21_sscanf_test40);
  tcase_add_test(tc_core, s21_sscanf_test41);
  tcase_add_test(tc_core, s21_sscanf_test42);
  tcase_add_test(tc_core, s21_sscanf_test43);
  suite_add_tcase(s, tc_core);
  return s;
}
