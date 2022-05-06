#pragma once

#include <stdio.h>
#include <stdbool.h>


typedef struct{
	int StartIndex;
	int EndIndex;
	int NumOfReadingsInRange;
}RangeReading;

extern int numberofContinuousRange( int *InputReadings, int numOfCCReadings);
extern bool validateInput(int *InputSequence , int length);
extern void sortInput(int *InputSequence , int length);
RangeReading detectRangeandOutputInCSVFormat( int min, int max, int numberInRange);
void printOutputInCSV(char  InputReadings);; 
