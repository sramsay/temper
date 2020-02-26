#include <boost/lexical_cast/bad_lexical_cast.hpp>
#include <boost/lexical_cast/try_lexical_convert.hpp>
#include <boost/program_options.hpp>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>

#include "conversions.hpp"
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
        "precision", bpo::value<int>()->default_value(1),
        "Specify decimal precision of results")("version",
                                                "Print the version number");

    bpo::options_description hidden("Hidden options");
    hidden.add_options()("input-value", bpo::value<double>(), "input value");

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

    if (argc == 1 || vm.count("help") != 0) {
      cout << desc << endl;
    } else if (vm.count("version") != 0) {
      printVersion();
    } else if (vm.count("input-value") != 0) {
      const auto input{vm["input-value"].as<double>()};
      const auto c{cTemp(input)};
      const auto f{fTemp(input)};
      const auto precision{vm["precision"].as<int>()};

      cout << fixed << setprecision(precision) << input << "\u00B0F is " << c
           << "\u00B0C" << endl;
      cout << fixed << setprecision(precision) << input << "\u00B0C is " << f
           << "\u00B0F" << endl;
    }
  } catch (bpo::invalid_option_value &e) {
    cout << "Input must be a number." << endl;
  } catch (exception &e) {
    cerr << "Error: " << e.what() << endl;
  }
}
