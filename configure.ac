
AC_PREREQ([2.69])
AC_INIT([temper], [0.1.1], [sramsay@protonmail.com])
AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_CONFIG_SRCDIR([src/temper.c])
AC_DEFINE([COPYRIGHT_DATES], ["2020"], [current copyright dates])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])

# Checks for programs
AC_PROG_CC
AC_PROG_CC_C99

# Checks for library functions.
AC_CHECK_HEADER([regex.h])
AC_CHECK_HEADER([getopt.h])

AM_INIT_AUTOMAKE([-Wall foreign])

AC_OUTPUT
