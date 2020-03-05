
static double c1 = 32.0;
static double c2 = 5.0;
static double c3 = 9.0;

double ftemp(double raw_temp) {
  double f_temp = raw_temp * c3 / c2 + c1;
  return f_temp;
}

double ctemp(double raw_temp) {
  double c_temp = (raw_temp - c1) * c2 / c3;
  return c_temp;
}
