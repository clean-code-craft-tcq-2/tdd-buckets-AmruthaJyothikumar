#pragma once

typedef struct {
  double lowerlimit;
  double upperlimit;
} currentrange;

currentrange getrange(int *CurrentSamples);
