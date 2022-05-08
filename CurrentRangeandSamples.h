#pragma once
#include <stdio.h>
#include <stdbool.h>

typedef struct{
	int Min;
	int Max;
	int Count;
}RangeReading;

extern int findContinuousRangeCount( int *InputReadings, int NumberofReadings);
extern bool validateInput(int *InputSequence , int length);
extern void sortInput(int *InputSequence , int length);
RangeReading detectRangeandOutputInCSVFormat( int min, int max, int numberInRange);
void printOutputInCSV(char  InputReadings);; 
