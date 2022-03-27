#include <stdio.h>
#include "CurrentRangeandSamples.h"

bool validateInput(int *Input , int length)
{
	int i;
  bool validity;
	for(i= 0; i < length; i++)
	{
		if(Input[i] >= 0)
		{
			sortInput(Input, length);			
			validity =  true;
		}	
		else
		{
			validity =  false;
		}
	}
  if(validity == true){
    sortInput(Input, length);		
  }
  else{
  }
return validity;
}

void sortInput(int *Input , int length)
{
	int i , j , temp ;
	for(i=0; i< length; i++)
	{
		for(j=i+1; j< length; j++)
		{
			if(Input[i] > Input[j])
			{
				temp = Input[i];
				Input[i] = Input[j];
				Input[j] = temp; 
			}
		}	
	}
}

int findContinousCount(int *InputSamples, int NoofSamples)
{
    int i, j, SampleDiff;
    if(validateInput(InputSamples, NoofSamples) == true)
    {
	    for(i = 0; i < NoofSamples; i++)
	    {
		  SampleDiff = (InputSamples[i+1] -  InputSamples[i]);
		  if((SampleDiff == 0) || (SampleDiff == 1))
		  {
			  Continouscount++;
	  	}
		
	    }
	   return Continouscount;
    }
}

RangeReading GetCurrentRange( int *InputSamplesSorted)
{
 int ContinousCount = findContinousCount;
	RangeReading rangeReading;
	rangeReading.StartIndex= InputSamplesSorted[0];
	rangeReading.EndIndex= InputSamplesSorted[ContinousCount-1];
	rangeReading.NumOfReadingsInRange= ContinousCount;
	printf(" %d - %d , %d\n",  rangeReading.StartIndex,rangeReading.EndIndex , rangeReading.NumOfReadingsInRange);	 
	return rangeReading;
}


