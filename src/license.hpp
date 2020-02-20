
#ifndef LICENSE_INCLUDED
#define LICENSE_INCLUDED

#include <iosfwd>

constexpr auto PROGRAM{"temper"};
constexpr auto VERSION{"1.2.1"};
constexpr auto DATES{"2019-2020"};

std::string printVersion();

inline std::string printVersion() {
  std::stringstream ss;

  ss << PROGRAM << " " << VERSION << "\n";
  ss << "Copyright © " << DATES << " by Stephen Ramsay"
     << "\n";
  ss << "This program comes with ABSOLUTELY NO WARRANTY."
     << "\n";
  ss << "This is free software, and you are welcome to redistribute it"
     << "\n";
  ss << "under the terms of the GNU General Public License version 3"
     << "\n";
  ss << "or (at your option) any later version.  See LICENSE for details,"
     << "\n";
  ss << "or visit <https://www.gnu.org/licenses/gpl.txt>." << std::endl;

  return ss.str();
}

#endif
