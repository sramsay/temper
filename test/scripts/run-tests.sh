#!/bin/sh 

if [ -d build ]
then
  meson --reconfigure build
  ninja -C build
else 
  meson build
  ninja -C build
fi

./build/temper-test
./scripts/bats ./scripts/temper_cli_tests
