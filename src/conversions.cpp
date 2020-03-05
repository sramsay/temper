double cTemp(double rawTemp) {
  auto cTemp{(rawTemp - 32.0) * 5.0 / 9.0};
  return cTemp;
}

double fTemp(double rawTemp) {
  auto fTemp{rawTemp * 9.0 / 5.0 + 32};
  return fTemp;
}
