# Process this file with autoconf to produce a configure script.

# Prelude.
AC_PREREQ([2.69])
AC_INIT([check_conversions], [0.1.0], [https://github.com/sramsay/temper/issues])
AM_PROG_AR
AC_CONFIG_MACRO_DIRS([m4])

# unique source file --- primitive safety check 
AC_CONFIG_SRCDIR([../src/temper.c])

# fairly severe build strictness
AM_INIT_AUTOMAKE([-Wall -Werror subdir-objects foreign])

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL
AC_PROG_CXX
LT_INIT

# Checks for libraries.
PKG_CHECK_MODULES([CHECK], [check])
AM_PROG_CC_C_O

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([float.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC

# Output files
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
