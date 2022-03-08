#include <stdio.h>
#include "CurrentRangeandSamples.h"

currentrange getrange(int *CurrentSamples){
  currentrange range;
  range.min = findminvalue;
  range.max = findmaxvalue;
  range.count = getcountofcontinousrange;
  return range;
}


int getcountofcontinousrange(int *CurrentSamples){
  int totallengthofinput;
  int diff = 1;
  int continuouscount;
  totallengthofinput = sizeof(CurrentSamples) / sizeof(CurrentSamples[0]);
  for(i=0; i<= totallengthofinput ;i++){
     diff = CurrentSamples[i+1]- CurrentSamples[i];
     if((diff == 0) || (diff == 1) || diff(==2)
        {
          continuouscount++;
        }
        else
        {
          continuouscount = 0;
        }
    }
  return continuouscount;
}
