#include <stdio.h>
#include "CurrentRangeandSamples.h"

int NumberofContRange = 0;
int count = 1;

bool validateInput(int *InputSequence , int length)
{
	int i;
	for(i= 0; i < length; i++)
	{
		if(InputSequence[i] >= 0)
		{
			sortInput(InputSequence, length);			
			return true;
		}	
		else
		{
			return false;
		}
	}
}

void sortInput(int *InputSequence , int length)
{
	int i , j , temp ;
	for(i=0; i< length; i++)
	{
		for(j=i+1; j< length; j++)
		{
			if(InputSequence[i] > InputSequence[j])
			{
				temp = InputSequence[i];
				InputSequence[i] = InputSequence[j];
				InputSequence[j] = temp; 
			}
		}	
	}
}

int numberofContinuousRange(int *InputReadings, int numOfCCReadings)
{
    int i, j, curRead;
    if(validateInput(InputReadings, numOfCCReadings) == true)
    {
	    for(i = 0; i < numOfCCReadings; i++)
	    {
		curRead = (InputReadings[i+1] -  InputReadings[i]);
		if((curRead == 0) || (curRead == 1))
		{
			count++;
		}
		
	    }
	   return count;
    }
}

RangeReading detectRangeandOutputInCSVFormat( int min, int max, int numberInRange)
{
	RangeReading rangeReading;
	char InputReadings;
	rangeReading.StartIndex=min;
	rangeReading.EndIndex= max;
	rangeReading.NumOfReadingsInRange= numberInRange;
	printf( " %d - %d , %d",  min, max , numberInRange); 
	return rangeReading;
}


