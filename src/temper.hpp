#ifndef __TEMPER_INCLUDED__
#define __TEMPER_INCLUDED__

#include <boost/program_options.hpp>

std::vector<boost::program_options::option> ignore_numbers(
    std::vector<std::string> &argv);

#endif
