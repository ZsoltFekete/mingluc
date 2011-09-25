#!/bin/bash

if [ "$1" == "safe" ] ; then
  set -e
  set -u
fi

for i in $(ls ../bin/test/gtest_* | grep -v \.o$); do
  echo "$i"
  "$i"
  echo
done

exit

