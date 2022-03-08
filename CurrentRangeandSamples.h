#pragma once

typedef struct {
  int min;
  int max;
  int count;
} currentrange;

currentrange getrange(int *CurrentSamples);
int getcount(int *CurrentSamples); 
