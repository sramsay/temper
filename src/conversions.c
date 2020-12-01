#include "conversions.h"

#include <config.h>

#define C1 32.0
#define C2 5.0
#define C3 9.0

double ftemp(double raw_temp) {
  double f_temp = raw_temp * C3 / C2 + C1;
  return f_temp;
}

double ctemp(double raw_temp) {
  double c_temp = (raw_temp - C1) * C2 / C3;
  return c_temp;
}
