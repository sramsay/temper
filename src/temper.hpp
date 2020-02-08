#ifndef __TEMPER_INCLUDED__
#define __TEMPER_INCLUDED__

#include <iosfwd>
#include <vector>
#include <boost/program_options/option.hpp>

std::vector<boost::program_options::option> ignore_numbers(
    std::vector<std::string> &argv);

#endif
