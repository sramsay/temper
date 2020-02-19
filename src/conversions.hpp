#ifndef __CONVERSIONS_INCLUDED__
#define __CONVERSIONS_INCLUDED__

double cTemp(double rawTemp);
double fTemp(double rawTemp);

constexpr auto c1{32};
constexpr auto c2{5.0};
constexpr auto c3{9.0};

inline double cTemp(double rawTemp) {
  auto cTemp{(rawTemp - c1) * c2 / c3};
  return cTemp;
}

inline double fTemp(double rawTemp) {
  auto fTemp{rawTemp * c3 / c2 + c1};
  return fTemp;
}

#endif
