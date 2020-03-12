#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conversions.h"
#include "license.h"

void print_output(double raw_temp, double f, double c, unsigned precision);
void print_usage(void);

int main(int argc, char* argv[argc + 1]) {
  if (argc == 1) {
    print_usage();
    exit(EXIT_SUCCESS);
  }

  /* The fundamental problem is that when getopt sees something like -42, it
   * thinks that's a switch.  Worse, it thinks it's two switches (-4 and -2).
   * So basically, we're going to take anything that looks like a temperature
   * out of argv.  To be safe, we're going to make a copy of argv without the
   * temperature and let getopt process that.
   */
  char* args[argc];

  regex_t regex = {0};
  signed regex_return_flag = 0;
  double raw_temp = 0;

  regex_return_flag = regcomp(&regex, "^[0-9-]+[.]?[0-9]*$", REG_EXTENDED);
  if (regex_return_flag) {  // Non-zero values indicate failure
    fprintf(stderr, "Could not compile regex\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < argc; ++i) {
    // Check to see if it's a temperature-like thing
    regex_return_flag = regexec(&regex, argv[i], 0, (void*)0, 0);
    if (!regex_return_flag) {  // 0 indicates successful match
      // Okay, but is it actually an opt arg?
      if (strcmp(argv[i - 1], "--precision") == 0 ||
          strcmp(argv[i - 1], "-p") == 0) {
        args[i] = argv[i];
      } else {
        char* end = (void*)0;
        raw_temp = strtod(argv[i], &end);
        if (*end) {
          printf("Could not parse %s", argv[i]);
          exit(EXIT_FAILURE);
        }
      }
    } else {
      args[i] = argv[i];
    }
  }

  regfree(&regex);

  static struct option long_options[] = {
      {"help", no_argument, (void*)0, 'h'},
      {"version", no_argument, (void*)0, 'V'},
      {"precision", required_argument, (void*)0, 'p'},
      {0, 0, 0, 0}};

  signed opt = 0;
  signed option_index = 0;
  unsigned precision = 1;

  while ((opt = getopt_long_only(argc, args, "hVp:", &long_options[0],
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
      case 'p': {
        char* end = (void*)0;
        precision = strtol(optarg, &end, 10);
        if (*end) {
          printf("Could not parse %s", optarg);
          exit(EXIT_FAILURE);
        }
        break;
      }
      default:
        print_usage();
        exit(EXIT_SUCCESS);
    }
  }

  if (regex_return_flag == 0) {
    double f = 0;
    double c = 0;

    f = ftemp(raw_temp);
    c = ctemp(raw_temp);
    print_output(raw_temp, f, c, precision);
  }

  return EXIT_SUCCESS;
}

void print_output(double raw_temp, double f, double c, unsigned precision) {
  printf("%.*f\u00B0F is %.*f\u00B0C\n", precision, raw_temp, precision, c);
  printf("%.*f\u00B0C is %.*f\u00B0F\n", precision, raw_temp, precision, f);
}

void print_usage(void) {
  puts("Usage: temper [num]");
  puts("  --help       Print this message");
  puts("  --version    Print the version number");
}
