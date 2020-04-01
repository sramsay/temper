
#include <config.h>
#include <float.h>
#include <stdlib.h>
#include <check.h>
#include <stdio.h>
#include "../src/conversions.h"


START_TEST(test_fahrenheit_conversions)
{
  char f[80];
  char c[80];

  // Absolute zero
  sprintf(f, "%f.2", ftemp(-273.15));
  sprintf(c, "%f.2", -459.67);
  ck_assert_float_eq(atof(c), atof(f));

  // Boiling point of liquid nitrogen
  sprintf(f, "%f.2", ftemp(-195.8));
  sprintf(c, "%f.2", -320.44);
  ck_assert_float_eq(atof(c), atof(f));

	// Sublimation point of dry ice
  sprintf(f, "%f.2", ftemp(-78.0));
  sprintf(c, "%f.2", -108.4);
  ck_assert_float_eq(atof(c), atof(f));

	// Intersection pf Celcius and Fahrenheit scales
  sprintf(f, "%f.2", ftemp(-40.0));
  sprintf(c, "%f.2", -40.0);
  ck_assert_float_eq(atof(c), atof(f));

	// Melting point of H₂O (purified ice)
  sprintf(f, "%f.2", ftemp(-0.0001));
  sprintf(c, "%f.2", 31.99982);
  ck_assert_float_eq(atof(c), atof(f));

	// Room temperature (NIST standard)
  sprintf(f, "%f.2", ftemp(20.0));
  sprintf(c, "%f.2", 68.0);
  ck_assert_float_eq(atof(c), atof(f));

	// Normal body temperature (average)
  sprintf(f, "%f.2", ftemp(37.0));
  sprintf(c, "%f.2", 98.6);
  ck_assert_float_eq(atof(c), atof(f));

	// Approximate boiling point of water at 1 atm (101.325 kPa)
  sprintf(f, "%f.2", ftemp(99.9839));
  sprintf(c, "%f.2", 211.97102);
  ck_assert_float_eq(atof(c), atof(f));

	// Totally bogus numbers that shouldn't align
  sprintf(f, "%f.2", ftemp(12.9839));
  sprintf(c, "%f.2", 205.97102);
  ck_assert_float_ne(atof(c), atof(f));
}
END_TEST

START_TEST(test_celcius_conversions)
{
  char f[80];
  char c[80];

  // Absolute zero
  sprintf(c, "%f.2", ctemp(-459.67));
  sprintf(f, "%f.2", -273.15);
  ck_assert_float_eq(atof(c), atof(f));

  // Boiling point of liquid nitrogen
  sprintf(c, "%f.2", ctemp(-320.44));
  sprintf(f, "%f.2", -195.8);
  ck_assert_float_eq(atof(c), atof(f));

	// Sublimation point of dry ice
  sprintf(c, "%f.2", ctemp(-108.4));
  sprintf(f, "%f.2", -78.0);
  ck_assert_float_eq(atof(c), atof(f));

	// Intersection pf Celcius and Fahrenheit scales
  sprintf(c, "%f.2", ctemp(-40.0));
  sprintf(f, "%f.2", -40.0);
  ck_assert_float_eq(atof(c), atof(f));

	// Melting point of H₂O (purified ice)
  sprintf(c, "%f.2", ctemp(31.99982));
  sprintf(f, "%f.2", -0.0001);
  ck_assert_float_eq(atof(c), atof(f));

	// Room temperature (NIST standard)
  sprintf(c, "%f.2", ctemp(68.0));
  sprintf(f, "%f.2", 20.0);
  ck_assert_float_eq(atof(c), atof(f));

	// Normal body temperature (average)
  sprintf(c, "%f.2", ctemp(98.6));
  sprintf(f, "%f.2", 37.0);
  ck_assert_float_eq(atof(c), atof(f));

	// Approximate boiling point of water at 1 atm (101.325 kPa)
  sprintf(c, "%f.2", ctemp(211.97102));
  sprintf(f, "%f.2", 99.9839);
  ck_assert_float_eq(atof(c), atof(f));

	// Totally bogus numbers that shouldn't align
  sprintf(c, "%f.2", ctemp(205.97102));
  sprintf(f, "%f.2", 12.9839);
  ck_assert_float_ne(atof(c), atof(f));
}
END_TEST

Suite * conversions_suite(void)
{
  Suite *s;
  TCase *tc_f;
  TCase *tc_c;

  s = suite_create("Conversions");

  /* Fahrenheit test cases */
  tc_f = tcase_create("Fahrenheit");

  tcase_add_test(tc_f, test_fahrenheit_conversions);
  suite_add_tcase(s, tc_f);

  /* Fahrenheit test case */
  tc_c = tcase_create("Celcius");

  tcase_add_test(tc_c, test_celcius_conversions);
  suite_add_tcase(s, tc_c);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = conversions_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
