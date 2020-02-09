/*
 * temper.hpp
 *
 * This file is part of temper.  It contains the headers for temper.cpp
 *
 * Written and maintained by Stephen Ramsay <sramsay@protonmail.com>
 *
 * Last Modified: Sun Feb 09 07:17:34 CST 2020
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

#ifndef __TEMPER_INCLUDED__
#define __TEMPER_INCLUDED__

#include <boost/program_options/option.hpp>
#include <iosfwd>
#include <vector>

std::vector<boost::program_options::option> ignore_numbers(
    std::vector<std::string> &argv);

#endif
