
AC_PREREQ([2.69])
AC_INIT([temper], [1.0.3], [https://github.com/sramsay/temper/issues])
AC_CONFIG_SRCDIR([src/temper.c])
AC_DEFINE([COPYRIGHT_DATES], ["2020"], [current copyright dates])
AC_CONFIG_AUX_DIR([build-aux])

# Checkss for programs
AC_PROG_CC
AC_PROG_CC_C99

# Checks for library headers
AC_CHECK_HEADER([check.h])
AC_CHECK_HEADER([regex.h])
AC_CHECK_HEADER([getopt.h])

# Checks for library functions
AC_CHECK_FUNCS([regcomp])
AC_FUNC_STRTOD

AM_INIT_AUTOMAKE([-Wall subdir-objects foreign])

# Output files
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile
                 src/Makefile])

AC_OUTPUT
