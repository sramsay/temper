/*
 * license.cpp
 *
 * This file is part of temper. It contains version macros and
 * the GNU license
 *
 * Written and maintained by Stephen Ramsay <sramsay@protonmail.com>
 *
 * Last Modified: Sun Feb 09 07:15:22 CST 2020
 *
 * Copyright © 2019-2020 Stephen Ramsay
 *
 * temper is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option) any
 * later version.
 *
 * temper is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with temper; see the file COPYING.  If not see
 * <http://www.gnu.org/licenses/>.
 */

#include "license.hpp"

#include <sstream>

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
