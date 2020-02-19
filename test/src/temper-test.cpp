#define CATCH_CONFIG_MAIN
#include "../../src/conversions.hpp"
#include "catch.hpp"

TEST_CASE("Fahrenheit conversions", "[fTemp]") {
  REQUIRE(fTemp(-273.15) == Approx(-459.67));  // Absolute zero
  REQUIRE(fTemp(-195.8) == -320.44);  // Boiling point of liquid nitrogen
  REQUIRE(fTemp(-78) == -108.4);      // Sublimation point of dry ice
  REQUIRE(fTemp(-40) ==
          -40.0);  // Intersection of Celcius and Fahrenheit scales
  REQUIRE(fTemp(-.0001) == 31.99982);  // Melting point of H₂O (purified ice)
  REQUIRE(fTemp(20) == 68.0);          // Room temperature (NIST standard)
  REQUIRE(fTemp(37) == 98.6);          // Normal body temperature (average)
  REQUIRE(
      fTemp(99.9839) ==
      211.97102);  // Approximate boiling point of water at 1 atm (101.325 kPa)
}

TEST_CASE("Celcius conversions", "[cTemp]") {
  REQUIRE(cTemp(-459.67) == -273.15);  // Absolute zero
  REQUIRE(cTemp(-320.4) ==
          Approx(-195.7777777778));  // Boiling point of liquid nitrogen
  REQUIRE(cTemp(-108.4) == -78);     // Sublimation point of dry ice
  REQUIRE(cTemp(-40) == -40);  // Intersection of Celcius and Fahrenheit scales
  REQUIRE(cTemp(31.9998) ==
          Approx(-0.0001111111));  // Melting point of H₂O (purified ice)
  REQUIRE(cTemp(68) == 20);        // Room temperature (NIST standard)
  REQUIRE(cTemp(98.6) == 37);      // Normal body temperature (average)
  REQUIRE(cTemp(211.971) ==
          Approx(99.9838888889));  // Approximate boiling point of water at 1
                                   // atm (101.325 kPa)
}
