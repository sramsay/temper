
#include <config.h>
#include <float.h>
#include <stdlib.h>
#include <check.h>
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
}
END_TEST

Suite * conversions_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("Conversions");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_fahrenheit_conversions);
  suite_add_tcase(s, tc_core);

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
