
#ifndef LICENSE_INCLUDED
#define LICENSE_INCLUDED

#include <iosfwd>

constexpr auto PROGRAM{"temper"};
constexpr auto VERSION{"1.2.5"};
constexpr auto DATES{"2019-2020"};

void printVersion();

inline void printVersion() {

  std::cout << PROGRAM << " " << VERSION << std::endl;
  std::cout << "Copyright © " << DATES << " by Stephen Ramsay"
     << "\n";
  std::cout << "This program comes with ABSOLUTELY NO WARRANTY."
     << "\n";
  std::cout << "This is free software, and you are welcome to redistribute it"
     << "\n";
  std::cout << "under the terms of the GNU General Public License version 3"
     << "\n";
  std::cout << "or (at your option) any later version.  See LICENSE for details,"
     << "\n";
  std::cout << "or visit <https://www.gnu.org/licenses/gpl.txt>." << std::endl;

}

#endif
