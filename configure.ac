
AC_PREREQ([2.69])
AC_INIT([temper], [1.0.6], [https://github.com/sramsay/temper/issues])
AC_DEFINE([COPYRIGHT_DATES], ["2020-2021"], [current copyright dates])
AC_CONFIG_SRCDIR([src/temper.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])

# Checks for programs
AC_PROG_CC
AC_PROG_CC_C99

# Checks for library headers
AC_CHECK_HEADERS([stdlib.h string.h])
AC_CHECK_HEADER([check.h])
AC_CHECK_HEADER([regex.h])
AC_CHECK_HEADER([getopt.h])

# Checks for library functions
AC_CHECK_FUNCS([regcomp])
AC_CHECK_FUNCS([strtol])
AC_FUNC_STRTOD

AM_INIT_AUTOMAKE([-Wall subdir-objects foreign])

# Output files
AC_CONFIG_FILES([Makefile
                 src/Makefile])

AC_OUTPUT
