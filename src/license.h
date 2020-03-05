#pragma once

#include <stdio.h>

void print_version();

void print_version() {
  const char PROGRAM[] = "temper";
  const char VERSION[] = "0.1.0";
  const char DATES[] = "2020";

  printf("%s %s\n", PROGRAM, VERSION);
  printf("Copyright © %s by Stephen Ramsay\n", DATES);
  /*
std::cout << "This program comes with ABSOLUTELY NO WARRANTY."
  << "\n";
std::cout << "This is free software, and you are welcome to redistribute it"
  << "\n";
std::cout << "under the terms of the GNU General Public License version 3"
  << "\n";
std::cout << "or (at your option) any later version.  See LICENSE for details,"
  << "\n";
std::cout << "or visit <https://www.gnu.org/licenses/gpl.txt>." << std::endl;
*/
}
