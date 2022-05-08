#include <stdio.h>
#include "CurrentRangeandSamples.h"

int Rangecount = 1;


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

int findContinuousRangeCount(int *InputReadings, int NumberofReadings)
{
    int i, j, ReadingDifference;
    if(validateInput(InputReadings, NumberofReadings) == true)
    {
	    for(i = 0; i < NumberofReadings; i++)
	    {
		ReadingDifference = (InputReadings[i+1] -  InputReadings[i]);
		if((ReadingDifference == 0) || (ReadingDifference == 1))
		{
			Rangecount++;
		}
		
	    }
	   return Rangecount;
    }
}

RangeReading detectRangeandOutputInCSVFormat( int min, int max, int numberInRange)
{
	RangeReading rangeReading;
	rangeReading.Min=min;
	rangeReading.Max= max;
	rangeReading.Count= numberInRange;
	printf( " %d - %d , %d",  min, max , numberInRange); 
	return rangeReading;
}


