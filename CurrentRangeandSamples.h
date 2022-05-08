#pragma once
#include <stdio.h>
#include <stdbool.h>

typedef struct{
	int StartIndex;
	int EndIndex;
	int NumOfReadingsInRange;
}RangeReading;

extern int findContinuousRangeCount( int *InputReadings, int NumberofReadings);
extern bool validateInput(int *InputSequence , int length);
extern void sortInput(int *InputSequence , int length);
RangeReading detectRangeandOutputInCSVFormat( int min, int max, int numberInRange,int *InputReadings, int NumberofReadings);
void printOutputInCSV(char  InputReadings);; 
