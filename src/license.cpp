#include "license.hpp"

#include <sstream>
#include <string>

using std::endl;
using std::string;
using std::stringstream;

string printVersion() {
  stringstream ss;

  ss << PROGRAM << " " << VERSION << "\n";
  ss << "Copyright © " << DATES << " by Stephen Ramsay"
     << "\n";
  ss << "This program comes with ABSOLUTELY NO WARRANTY."
     << "\n";
  ss << "This is free software, and you are welcome to redistribute it"
     << "\n";
  ss << "under the terms of the GNU General Public License version 3"
     << "\n";
  ss << "or (at your option) any later version.  See COPYING for details,"
     << "\n";
  ss << "or visit <https://www.gnu.org/licenses/gpl.txt>." << endl;

  return ss.str();
}
