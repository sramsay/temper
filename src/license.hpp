/*
 * license.hpp
 *
 * This file is part of temper.  It contains the headers for license.cpp
 *
 * Written and maintained by Stephen Ramsay <sramsay@protonmail.com>
 *
 * Last Modified: Sun Feb 09 07:16:59 CST 2020
 *
 * Copyright © 2020 Stephen Ramsay
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

#ifndef LICENSE_INCLUDED
#define LICENSE_INCLUDED

#include <iosfwd>

constexpr auto PROGRAM{"temper"};
constexpr auto VERSION{"1.1.0"};
constexpr auto DATES{"2019-2020"};

std::string printVersion();

#endif
