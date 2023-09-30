#ifndef TEST_HEADER_SPRINTF_
#define TEST_HEADER_SPRINTF_

#include "../headers/s21_sprintf.h"
#include "s21_test.h"

#endif

START_TEST(s21_sprintf_test1) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "num1: %+5d, num2: %+5d\n";
  int value1 = 10;
  int value2 = -10;
  sprintf(origDest, formatString, value1, value2);
  s21_sprintf(testDest, formatString, value1, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test2) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "num1: %5d, num2: %5d";
  int value1 = 10;
  int value2 = -10;
  sprintf(origDest, formatString, value1, value2);
  s21_sprintf(testDest, formatString, value1, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test3) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "num1: %*d, num2: %*d";
  int value1 = 10;
  int value2 = -10;
  int width1 = 5;
  int width2 = 10;
  sprintf(origDest, formatString, width1, value1, width2, value2);
  s21_sprintf(testDest, formatString, width1, value1, width2, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test4) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "num1: % *d, num2: %*d";
  int value1 = 8564;
  int value2 = -101000;
  int width1 = 5;
  int width2 = 10;
  sprintf(origDest, formatString, width1, value1, width2, value2);
  s21_sprintf(testDest, formatString, width1, value1, width2, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test5) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "num1: %*d, num2: %*d";
  int value1 = 0x8564;
  int value2 = -0x101000;
  int width1 = 100;
  int width2 = 100;
  sprintf(origDest, formatString, width1, value1, width2, value2);
  s21_sprintf(testDest, formatString, width1, value1, width2, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test6) {
  char origDest[10000] = {0};
  char testDest[10000] = {0};
  char formatString[] = "num1: %*d, num2: %*d";
  int value1 = 0x8564;
  int value2 = 0x1010;
  int width1 = 25;
  int width2 = 25;
  sprintf(origDest, formatString, width1, value1, width2, value2);
  s21_sprintf(testDest, formatString, width1, value1, width2, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test7) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "num1: %-*d, num2: %-*d";
  int value1 = 5;
  int value2 = -10;
  int width1 = 10;
  int width2 = 10;
  sprintf(origDest, formatString, width1, value1, width2, value2);
  s21_sprintf(testDest, formatString, width1, value1, width2, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test8) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  const char *formatString = "%c%c%c%c%c%c%c%c%c%c%c%c";

  sprintf(origDest, formatString, 'H', 'e', 'l', 'l', 'o', ' ', 't', 'h', 'e',
          'r', 'e', '!');
  s21_sprintf(testDest, formatString, 'H', 'e', 'l', 'l', 'o', ' ', 't', 'h',
              'e', 'r', 'e', '!');

  ck_assert_str_eq(origDest, testDest);
}

END_TEST
START_TEST(s21_sprintf_test9) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somechars: %c%c";

  sprintf(origDest, formatString, 'H', 'e');
  s21_sprintf(testDest, formatString, 'H', 'e');

  ck_assert_str_eq(origDest, testDest);
}

END_TEST
START_TEST(s21_sprintf_test10) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "%c %c";

  sprintf(origDest, formatString, 'E', 'E');
  s21_sprintf(testDest, formatString, 'E', 'E');

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test11) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "string: % 100s, string2: %s, string3: %s";
  char string1[] = "Hello there!\n";
  char string2[] = "another Hello there!\n";
  char string3[] = "one more time Hello there!\n";

  sprintf(origDest, formatString, string1, string2, string3);
  s21_sprintf(testDest, formatString, string1, string2, string3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test12) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "%s%s%s";
  char string1[] = "Hello there!\n";
  char string2[] = "another Hello there!\n";
  char string3[] = "one more time Hello there!\n";

  sprintf(origDest, formatString, string1, string2, string3);
  s21_sprintf(testDest, formatString, string1, string2, string3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test13) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %x";
  int num1 = 0x1fffff;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

START_TEST(s21_sprintf_test14) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %10x %10x %10x %10x";
  int num1 = 0x1fffff;
  long int num2 = -0xffffffff;
  long int num3 = 0xffffffff;
  int num4 = -0;

  sprintf(origDest, formatString, num1, num2, num3, num4);
  s21_sprintf(testDest, formatString, num1, num2, num3, num4);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test15) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %10x %10x %10x %10x";
  int num1 = 100;
  long int num2 = -0xffffffff;
  long int num3 = 0xffffffff;
  int num4 = -0;

  sprintf(origDest, formatString, num1, num2, num3, num4);
  s21_sprintf(testDest, formatString, num1, num2, num3, num4);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test16) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %10X %10X %10X %10X";
  int num1 = 100;
  long int num2 = -0xfffffff;
  long int num3 = 0xfffffff;
  int num4 = -0;

  sprintf(origDest, formatString, num1, num2, num3, num4);
  s21_sprintf(testDest, formatString, num1, num2, num3, num4);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test17) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %10x %10x %10X %10X";
  int num1 = 100;
  long int num2 = -0xffffffff;
  long int num3 = 0xffffffff;
  int num4 = -0;

  sprintf(origDest, formatString, num1, num2, num3, num4);
  s21_sprintf(testDest, formatString, num1, num2, num3, num4);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test18) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %10X";
  int num1 = 100;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test19) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %10p";
  int num = 100;
  int *pNum = &num;

  sprintf(origDest, formatString, pNum);
  s21_sprintf(testDest, formatString, pNum);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test20) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %10p %10p %10p %10p";
  int num1 = 100;
  int num2 = 100;
  int num3 = 100;
  int num4 = 100;

  int *pNum1 = &num1;
  int *pNum2 = &num2;
  int *pNum3 = &num3;
  int *pNum4 = &num4;
  sprintf(origDest, formatString, pNum1, pNum2, pNum3, pNum4);
  s21_sprintf(testDest, formatString, pNum1, pNum2, pNum3, pNum4);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test21) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %-25p %25p %-25p %25p";
  int num1 = 100;
  int num2 = 100;
  int num3 = 100;
  int num4 = 100;

  int *pNum1 = &num1;
  int *pNum2 = &num2;
  int *pNum3 = &num3;
  int *pNum4 = &num4;
  sprintf(origDest, formatString, pNum1, pNum2, pNum3, pNum4);
  s21_sprintf(testDest, formatString, pNum1, pNum2, pNum3, pNum4);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST
START_TEST(s21_sprintf_test22) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %-50p %+-++050p %-25p %25p";
  int num1 = 100;
  int num2 = 100;
  int num3 = 100;
  int num4 = 100;

  int *pNum1 = &num1;
  int *pNum2 = &num2;
  int *pNum3 = &num3;
  int *pNum4 = &num4;
  sprintf(origDest, formatString, pNum1, pNum2, pNum3, pNum4);
  s21_sprintf(testDest, formatString, pNum1, pNum2, pNum3, pNum4);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test23) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %u";
  int num1 = 100;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test24) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %u";
  unsigned int num1 = 100;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test25) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %u";
  unsigned int num1 = -100;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test26) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %u";
  int num1 = -100;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test27) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %+u %+u %+-u";
  int num1 = -100;
  int num2 = 10101001;
  int num3 = 91919191;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test28) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %-+u %+-u %+-u";
  int num1 = -100;
  int num2 = 10101001;
  int num3 = 91919191;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test29) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %-0+u %+0-u %+0-u";
  int num1 = -100;
  int num2 = 10101001;
  int num3 = 91919191;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test30) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %0u %0u %0u";
  int num1 = -100;
  int num2 = 10101001;
  int num3 = 91919191;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test31) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %010u %010u %010u";
  int num1 = -100;
  int num2 = 10101001;
  int num3 = 91919191;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test32) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %025u %025u %025u";
  int num1 = -100;
  int num2 = 10101001;
  int num3 = 91919191;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test33) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %o";
  int num1 = -100;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test34) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %o %o %o";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test35) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %+o %+o %+o";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test36) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %+-o %-+o %+-o";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test37) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %0+-o %0-+o %0+-o";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test38) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %0+-25o %0-+o %0+-25o";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test39) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %0+-010o %0-+010o %0+-010o";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test40) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %i";
  int num1 = -100;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test41) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %i %i %i";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test42) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %+i %+i %+i";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test43) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %+-i %-+i %+-i";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test44) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %0+-i %0-+i %0+-i";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test45) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %0+-25i %0-+i %0+-25i";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test46) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %0+-010i %0-+010i %0+-010i";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test47) {
  double array[] = {0.00000002, 1.12,  1.123,  1.1234,  10.5,  1.,
                    -1.,        -1.12, -1.123, -1.1234, -10.5, -10.12345};
  const int countTestNums = sizeof(array) / sizeof(array[0]);
  const int countFormatStrings = 7;
  const char formatStrings[7][50] = {
      "Somestring: %+0000000015E", "Somestring: %+15e",

      "Somestring: %+015e",        "Somestring: %.10e", "Somestring: %000e",
      "Somestring: %000.2e",       "Somestring: %0e",
  };
  for (int i = 0; i < countTestNums; ++i) {
    for (int j = 0; j < countFormatStrings; ++j) {
      char origDest[1000] = {0};
      char testDest[1000] = {0};
      sprintf(origDest, formatStrings[j], array[i]);
      s21_sprintf(testDest, formatStrings[j], array[i]);

      ck_assert_str_eq(origDest, testDest);
    }
  }
}

END_TEST

START_TEST(s21_sprintf_test48) {
  double array[] = {2,  12,   123,  1234,  1.001, 1,
                    -1, 1000, 1123, 11234, -101,  101245};
  int size = sizeof(array) / sizeof(array[0]);
  for (int i = 0; i < size; ++i) {
    char origDest[1000] = {0};
    char testDest[1000] = {0};
    char formatString[] = "Somestrings: %g";
    sprintf(origDest, formatString, array[i]);
    s21_sprintf(testDest, formatString, array[i]);
    ck_assert_str_eq(origDest, testDest);
  }
}

END_TEST

START_TEST(s21_sprintf_test49) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char *formatString = "somestring: %s%n";

  int origLength = 0;
  int testLength = 0;
  char *string = "123456789";

  sprintf(origDest, formatString, string, &origLength, &origLength);
  s21_sprintf(testDest, formatString, string, &testLength);
  ck_assert_str_eq(origDest, testDest);
  ck_assert_int_eq(origLength, testLength);
}

END_TEST

START_TEST(s21_sprintf_test50) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char *formatString = "somestring: %s:tring: %s: tring: %s:tring: %s%n";

  int origLength = 0;
  int testLength = 0;
  char *string = "123456789";
  char *string2 = "String a bit longer";

  sprintf(origDest, formatString, string, string2, string, string2,
          &origLength);
  s21_sprintf(testDest, formatString, string, string2, string, string2,
              &testLength);
  ck_assert_str_eq(origDest, testDest);
  ck_assert_int_eq(origLength, testLength);
}

END_TEST

START_TEST(s21_sprintf_test51) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  const char *formatString = "num1: %*.*f";
  float value1 = 123.f;
  float value2 = -444.f;
  int width1 = 10;
  int precision1 = 10;
  int width2 = 10;
  int precision2 = 10;

  sprintf(origDest, formatString, width1, precision1, value1, width2,
          precision2, value2);
  s21_sprintf(testDest, formatString, width1, precision1, value1, width2,
              precision2, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test52) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};

  float nums[] = {
      123.123456789f,
      -123.12300011111f,
      -123.123456789f,
      111312323423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342.001000000000010000000000000000000000000010000000000000000001f,
      111312323423423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
      111131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
  };

  char formatString[] = "num1: %f, num2: %f";
  int count = 10;
  for (int i = 0; i < count; ++i) {
    sprintf(origDest, formatString, nums[i], nums[i]);
    s21_sprintf(testDest, formatString, nums[i], nums[i]);

    ck_assert_str_eq(origDest, testDest);
  }
}

END_TEST

START_TEST(s21_sprintf_test53) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};

  float nums[] = {
      123.123456789f,
      -123.12300011111f,
      -123.123456789f,
      111312323423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342.001000000000010000000000000000000000000010000000000000000001f,
      111312323423423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
      111131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
  };

  char formatString[] = "num1: % +f, num2: % +10f";
  int count = 10;
  for (int i = 0; i < count; ++i) {
    sprintf(origDest, formatString, nums[i], nums[i]);
    s21_sprintf(testDest, formatString, nums[i], nums[i]);

    ck_assert_str_eq(origDest, testDest);
  }
}

END_TEST

START_TEST(s21_sprintf_test54) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};

  float nums[] = {
      123.123456789f,
      -123.12300011111f,
      -123.123456789f,
      111312323423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342.001000000000010000000000000000000000000010000000000000000001f,
      111312323423423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
      111131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
  };

  char formatString[] = "num1: % 0+100.14f, num2: % +100.50f";
  int count = 10;
  for (int i = 0; i < count; ++i) {
    sprintf(origDest, formatString, nums[i], nums[i]);
    s21_sprintf(testDest, formatString, nums[i], nums[i]);

    ck_assert_str_eq(origDest, testDest);
  }
}

END_TEST

START_TEST(s21_sprintf_test55) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};

  float nums[] = {
      123.123456789f,
      -123.12300011111f,
      -123.123456789f,
      111312323423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342.001000000000010000000000000000000000000010000000000000000001f,
      111312323423423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
      111131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
  };

  char formatString[] = "num1: % 0+100f, num2: % +.50f";
  int count = 10;
  for (int i = 0; i < count; ++i) {
    sprintf(origDest, formatString, nums[i], nums[i]);
    s21_sprintf(testDest, formatString, nums[i], nums[i]);

    ck_assert_str_eq(origDest, testDest);
  }
}

END_TEST
START_TEST(s21_sprintf_test56) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};

  float nums[] = {
      123.123456789f,
      -123.12300011111f,
      -123.123456789f,
      111312323423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342.001000000000010000000000000000000000000010000000000000000001f,
      111312323423423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
      111131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
  };

  char formatString[] = "num1: % 0+100f, num2: % +.50f";
  int count = 10;
  for (int i = 0; i < count; ++i) {
    sprintf(origDest, formatString, nums[i], nums[i]);
    s21_sprintf(testDest, formatString, nums[i], nums[i]);

    ck_assert_str_eq(origDest, testDest);
  }
}

END_TEST

START_TEST(s21_sprintf_test57) {
  char origDest[10000] = {0};
  char testDest[10000] = {0};
  char formatString[] = "string: %s, string2: %s, string3: %s";
  char string1[1000] = "☀☀☀☀☀☀☀⚪⛱️️☀☀☀☀☀☀☀";
  char string2[1000] =
      "☀☀☀☀☀☀☀☀☀☀☀☀☀☀☀☀☀☀☀⚪⛱️🍀"
      "☘"
      "e"
      "☀"
      "☀"
      "☀"
      "☀";
  char string3[1000] =
      "Somessss☀☀☀☀☀☀☀☀☀️🍀☘essss☀☀☀☀☀☀☀"
      "☀"
      "☀"
      "🇺"
      "🇾"
      "☀"
      "️"
      "⚪"
      "⛱"
      "️"
      "🍀"
      "☘"
      "️";
  sprintf(origDest, formatString, string1, string2, string3);
  s21_sprintf(testDest, formatString, string1, string2, string3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test58) {
  float array[] = {
      0.5f,
      0.555555555555555555555555555555555555333333333555555555f,
      233333333333333333333333333333333.3222222222222222222222222222222222222222222f,
      1242.23521f,
      1111.9939999999999999999999999999999999999999999f,
      1.555555555555555555555555555555555555333333333555555555f,
      0.500009f,
      0.500004f,
      0.500001f,
      0.500000f,
      0.5000006f,
      0.5000004f,
      0.5000044f,
      0.5000048f,
      0.55000000f,
      0.550005f,
      0.550004f,
      0.5500006f,
      5.5500000f,
      200000000000000000.0f,
      210000000000000000.0f,
      239847.2340f,
      0.00000001f,
      1.123456f,
      12.34567124f,
      123.456767f,
      1234.56775f,
      12345.677f,
      123456.76f,
      10000000.000018f,
      0.0000000015015088f,
      10.00000000118811f,
      11231231231231231230.0800000f,
      2351230.000000f,
      1241478888830.000009999999999999999999999999999999999999999999999990f,
      77777.000000f,
      1.0f,
      10.0f,
      100.0f,
      1000.0f,
      10000.0f,
      100000.0f,
      1000000.0f,
      10000000.0f,
      100000000.0f,
      1000000000.0f,
      10000000000.0f,
      100000000000.0f,
      1000000000000.0f,
      10000000000000.0f,
      100000000000000.0f,
      0.001f,
      0.0001f,
      0.00001f,
      0.000001f,
      0.0000001f,
      0.00000001f,
      0.000000001f,
      0.0000000001f,
      0.00000000001f,
      0.000000000001f,
      0.0000000000001f,
      0.0f,
      2,
      12,
      123,
      1234,
      1011,
      1,
      -1,
      1000,
      1123,
      11234,
      -101,
      101245,
      1.12f};

  int numTests = sizeof(array) / sizeof(float);

  const int countFormatStrings = 9;
  const char formatStrings[10][50] = {
      "Somestring: %g",    "Somestring: %g",

      "Somestring: %G",    "Somestring: %G",     "Somestring: %050.6g",
      "Somestring: %g",    "Somestring: %0100g", "Somestring: %100.6g",
      "Somestring: %010g",
  };
  for (int i = 0; i < numTests; ++i) {
    for (int j = 0; j < countFormatStrings; ++j) {
      char origDest[1000] = {0};
      char testDest[1000] = {0};
      sprintf(origDest, formatStrings[j], array[i]);
      s21_sprintf(testDest, formatStrings[j], array[i]);

      ck_assert_str_eq(origDest, testDest);
    }
  }
}

END_TEST

START_TEST(s21_sprintf_test59) {
  char origDest[10000] = {0};
  char testDest[10000] = {0};

  char formatString[] = "string: %s";
  char string[1000] =
      "☀☀☀☀☀🇺🇾☀️⚪⛱️🍀☘☀☀☀⚪";
  sprintf(origDest, formatString, string);
  s21_sprintf(testDest, formatString, string);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test60) {
  char origDest[10000] = {0};
  char testDest[10000] = {0};

  char formatString[] = "string: %ls";
  wchar_t string[1000] =
      L"Here's some wide string, one char here is 2 or 4 bytes";
  sprintf(origDest, formatString, string);
  s21_sprintf(testDest, formatString, string);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

Suite *

sprintf_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("sprintf");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_sprintf_test1);
  tcase_add_test(tc_core, s21_sprintf_test2);
  tcase_add_test(tc_core, s21_sprintf_test3);
  tcase_add_test(tc_core, s21_sprintf_test4);
  tcase_add_test(tc_core, s21_sprintf_test5);
  tcase_add_test(tc_core, s21_sprintf_test6);
  tcase_add_test(tc_core, s21_sprintf_test7);
  tcase_add_test(tc_core, s21_sprintf_test8);
  tcase_add_test(tc_core, s21_sprintf_test9);
  tcase_add_test(tc_core, s21_sprintf_test10);
  tcase_add_test(tc_core, s21_sprintf_test11);
  tcase_add_test(tc_core, s21_sprintf_test12);
  tcase_add_test(tc_core, s21_sprintf_test13);
  tcase_add_test(tc_core, s21_sprintf_test14);
  tcase_add_test(tc_core, s21_sprintf_test15);
  tcase_add_test(tc_core, s21_sprintf_test16);
  tcase_add_test(tc_core, s21_sprintf_test17);
  tcase_add_test(tc_core, s21_sprintf_test18);
  tcase_add_test(tc_core, s21_sprintf_test19);
  tcase_add_test(tc_core, s21_sprintf_test20);
  tcase_add_test(tc_core, s21_sprintf_test21);
  tcase_add_test(tc_core, s21_sprintf_test22);
  tcase_add_test(tc_core, s21_sprintf_test23);
  tcase_add_test(tc_core, s21_sprintf_test24);
  tcase_add_test(tc_core, s21_sprintf_test25);
  tcase_add_test(tc_core, s21_sprintf_test26);
  tcase_add_test(tc_core, s21_sprintf_test27);
  tcase_add_test(tc_core, s21_sprintf_test28);
  tcase_add_test(tc_core, s21_sprintf_test29);
  tcase_add_test(tc_core, s21_sprintf_test30);
  tcase_add_test(tc_core, s21_sprintf_test31);
  tcase_add_test(tc_core, s21_sprintf_test32);
  tcase_add_test(tc_core, s21_sprintf_test33);
  tcase_add_test(tc_core, s21_sprintf_test34);
  tcase_add_test(tc_core, s21_sprintf_test35);
  tcase_add_test(tc_core, s21_sprintf_test36);
  tcase_add_test(tc_core, s21_sprintf_test37);
  tcase_add_test(tc_core, s21_sprintf_test38);
  tcase_add_test(tc_core, s21_sprintf_test39);
  tcase_add_test(tc_core, s21_sprintf_test40);
  tcase_add_test(tc_core, s21_sprintf_test41);
  tcase_add_test(tc_core, s21_sprintf_test42);
  tcase_add_test(tc_core, s21_sprintf_test43);
  tcase_add_test(tc_core, s21_sprintf_test44);
  tcase_add_test(tc_core, s21_sprintf_test45);
  tcase_add_test(tc_core, s21_sprintf_test46);
  tcase_add_test(tc_core, s21_sprintf_test47);
  tcase_add_test(tc_core, s21_sprintf_test48);
  tcase_add_test(tc_core, s21_sprintf_test49);
  tcase_add_test(tc_core, s21_sprintf_test50);
  tcase_add_test(tc_core, s21_sprintf_test51);
  tcase_add_test(tc_core, s21_sprintf_test52);
  tcase_add_test(tc_core, s21_sprintf_test53);
  tcase_add_test(tc_core, s21_sprintf_test54);
  tcase_add_test(tc_core, s21_sprintf_test55);
  tcase_add_test(tc_core, s21_sprintf_test56);
  tcase_add_test(tc_core, s21_sprintf_test57);
  tcase_add_test(tc_core, s21_sprintf_test58);
  tcase_add_test(tc_core, s21_sprintf_test59);
  tcase_add_test(tc_core, s21_sprintf_test60);
  suite_add_tcase(s, tc_core);
  return s;
}
