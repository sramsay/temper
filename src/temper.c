#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#include "conversions.h"
#include "license.h"

void print_output(double raw_temp, double f, double c, int precision);
void print_usage(void);

int main(int argc, char* argv[argc + 1]) {
  if (argc == 1) {
    print_usage();
    exit(EXIT_SUCCESS);
  }

  regex_t regex;
  int reti = 0;
  double raw_temp = 0;

  reti = regcomp(&regex, "^[0-9-]+$", REG_EXTENDED);
  if (reti) {
    fprintf(stderr, "Could not compile regex\n");
    exit(EXIT_FAILURE);
  }

  reti = regexec(&regex, argv[argc - 1], 0, NULL, 0);
  if (!reti) {
    char* end = NULL;
    raw_temp = strtod(argv[argc - 1], &end);  // TODO: check
    argc--;
  }

  regfree(&regex);

  static struct option long_options[] = {
      {"help", no_argument, NULL, 'h'},
      {"version", no_argument, NULL, 'V'},
      {"precision", required_argument, 0, 'p'},
      {0, 0, 0, 0}};

  int opt = 0;
  int option_index = 0;
  int precision = 1;

  while ((opt = getopt_long_only(argc, argv, "hVp:", &long_options[0],
                                 &option_index)) != -1) {
    switch (opt) {
      case '?':
        break;
      case 'V':
        print_version();
        exit(EXIT_SUCCESS);
      case 'h':
        print_usage();
        exit(EXIT_SUCCESS);
      case 'p':
        precision = atoi(optarg);
        break;
      default:
        print_usage();
        exit(EXIT_SUCCESS);
    }
  }

  if (reti == 0) {
    double f = 0;
    double c = 0;

    f = ftemp(raw_temp);
    c = ctemp(raw_temp);
    print_output(raw_temp, f, c, precision);
  }

  return EXIT_SUCCESS;
}

void print_output(double raw_temp, double f, double c, int precision) {
  printf("%.*f\u00B0F is %.*f\u00B0C\n", precision, raw_temp, precision, c);
  printf("%.*f\u00B0C is %.*f\u00B0F\n", precision, raw_temp, precision, f);
}

void print_usage(void) {
  puts("Usage: temper [num]");
  puts("  --help       Print this message");
  puts("  --version    Print the version number");
}