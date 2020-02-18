#include <boost/lexical_cast/bad_lexical_cast.hpp>
#include <boost/lexical_cast/try_lexical_convert.hpp>
#include <boost/program_options.hpp>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>

#include "license.hpp"

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::fixed;
using std::setprecision;
using std::string;
using std::stringstream;

namespace bpo = boost::program_options;
namespace bps = boost::program_options::command_line_style;

int main(int argc, char *argv[]) {
  try {
    bpo::options_description desc("temper [num]");
    desc.add_options()("help", "Print this message")(
        "version", "Print the version number");

    bpo::options_description hidden("Hidden options");
    hidden.add_options()("input-value", bpo::value<float>(), "input value");

    bpo::options_description cmdline_options;
    cmdline_options.add(desc).add(hidden);
    bpo::positional_options_description cmdline_values;
    cmdline_values.add("input-value", -1);

    bpo::variables_map vm;

    bpo::store(bpo::command_line_parser(argc, argv)
                   .options(cmdline_options)
                   .style(bps::unix_style ^ bps::allow_short)
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
      constexpr auto c1{32};
      constexpr auto c2{5.0};
      constexpr auto c3{9.0};

      const auto rawTemp{vm["input-value"].as<float>()};
      auto cTemp{(rawTemp - c1) * c2 / c3};
      auto fTemp{rawTemp * c3 / c2 + c1};
      cout << fixed << setprecision(1) << rawTemp << "\u00B0F is " << cTemp
           << "\u00B0C" << endl;
      cout << fixed << setprecision(1) << rawTemp << "\u00B0C is " << fixed
           << setprecision(1) << fTemp << "\u00B0F" << endl;
    } else {
      cout << desc << endl;
      exit(0);
    }
  } catch (bpo::invalid_option_value &e) {
    cout << "Input must be a number." << endl;
  } catch (exception &e) {
    cerr << "Error: " << e.what() << endl;
  }
}
