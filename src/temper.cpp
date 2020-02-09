/*
 * temper.cpp
 *
 * temper - a blazingly minimalistic Fahrenheit to Celcius converter
 *
 * Main and associated functions
 *
 * Written and maintained by Stephen Ramsay <sramsay@protonmail.com>
 *
 * Last Modified: Sun Feb 09 07:12:52 CST 2020
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

#include "temper.hpp"

#include <stdlib.h>

#include <boost/lexical_cast/bad_lexical_cast.hpp>
#include <boost/lexical_cast/try_lexical_convert.hpp>
#include <boost/program_options.hpp>
#include <boost/type_index/type_index_facade.hpp>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>

#include "license.hpp"

/*
// A Debug macro in case of emergency
#ifdef DEBUG_BUILD
#define DEBUG(x) std::cerr << x << std::endl
#else
#define DEBUG(x)
  do {
  } while (0)
#endif
*/

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::fixed;
using std::setprecision;
using std::string;
using std::stringstream;
using std::vector;

namespace bpo = boost::program_options;
namespace bc = boost::conversion;

int main(int argc, char *argv[]) {
  auto exitStatus{0};
  try {
    bpo::options_description desc("temper [num]");
    desc.add_options()("help,h", "Print this message")(
        "version,V", "Print the version number");

    bpo::options_description hidden("Hidden options");
    hidden.add_options()("input-value", bpo::value<string>(), "input value");

    bpo::options_description cmdline_options;
    cmdline_options.add(desc).add(hidden);
    bpo::positional_options_description cmdline_values;
    cmdline_values.add("input-value", -1);

    bpo::variables_map vm;

    bpo::store(bpo::command_line_parser(argc, argv)
                   .extra_style_parser(&ignore_numbers)
                   .options(cmdline_options)
                   .positional(cmdline_values)
                   .run(),
               vm);
    bpo::notify(vm);

    if (vm.count("version") != 0) {
      cout << printVersion();
      exit(0);
    }

    if (vm.count("help") != 0) {
      cout << desc << endl;
      exit(0);
    }

    if (vm.count("input-value") != 0) {
      const auto c1{32};
      const auto c2{5.0};
      const auto c3{9.0};

      stringstream input;
      input << vm["input-value"].as<string>();
      float rawtemp;
      input >> rawtemp;
      auto ctemp{(rawtemp - c1) * c2 / c3};
      auto ftemp{rawtemp * c3 / c2 + c1};
      cout << fixed << setprecision(1) << rawtemp << "\u00B0F is " << ctemp
           << "\u00B0C" << endl;
      cout << fixed << setprecision(1) << rawtemp << "\u00B0C is " << fixed
           << setprecision(1) << ftemp << "\u00B0F" << endl;
    } else {
      cout << desc << endl;
      exit(0);
    }
  } catch (exception &e) {
    cerr << "Error: " << e.what() << endl;
    exitStatus = 1;
  }

  return exitStatus;
}

vector<bpo::option> ignore_numbers(vector<string> &argv) {
  vector<bpo::option> result;
  int pos = 0;
  while (!argv.empty()) {
    const auto &arg = argv[0];
    float num;
    if (bc::try_lexical_convert(arg, num)) {
      result.emplace_back(bpo::option());
      bpo::option &opt = result.back();

      opt.position_key = pos++;
      opt.value.push_back(arg);
      opt.original_tokens.push_back(arg);

      argv.erase(argv.begin());
    } else {
      break;
    }
  }
  return result;
}
