#ifndef INCLUDE_LICENSE
#define INCLUDE_LICENSE

#include <config.h>
#include <stdio.h>

void print_version();

void print_version() {
  // const char PROGRAM[] = "temper";
  // const char VERSION[] = "0.1.1";
  // const char DATES[] = "2020";

  printf("%s %s\n", PACKAGE, PACKAGE_VERSION);
  printf("Copyright © %s by Stephen Ramsay\n", COPYRIGHT_DATES);
  printf(
      "License GPVv3+: GNU GPL version 3 or later "
      "<https://gnu.org/licenses.gpl.html>.\n");
  printf(
      "This is free software: you are free to change and redistribute it.\n");
  printf("There is NO WARRANTY, to the extent permitted by law.\n");
}

#endif
