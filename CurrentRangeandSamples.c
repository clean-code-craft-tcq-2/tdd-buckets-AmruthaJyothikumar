#include <stdio.h>
#include "CurrentRangeandSamples.h"

currentrange getrange(int *CurrentSamples){
  currentrange range;
  range = {4,5};
  return range;
}

int getcount(int *CurrentSamples){
  int count;
  count = sizeof(CurrentSamples) / sizeof(CurrentSamples[0]);
  return count;
}
