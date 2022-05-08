#include "ADCInput.h"

int ScalingFactor(int ADC_Resolution)
{
	return (pow(2,ADC_Resolution) - 2);
}

void ConvertAnalogToDigital(int ADCInput[], int numberOfSamples, int ADC_Resolution, int maxCurrentValue, int* currentConversionValues)
{	
	float currentValue, ConversionFactor;	
	for (int i=0; i< numberOfSamples; i++)
	{
		ConversionFactor = (ADCInput[i]) / (ScalingFactor(ADC_Resolution));
		currentValue = (maxCurrentValue * ConversionFactor) / (ScalingFactor(ADC_Resolution));
		currentConversionValues[i] = round(currentValue);
		if(currentConversionValues[i] < 0)
			currentConversionValues[i] = abs(currentConversionValues[i]);
	}	
}

void ChargingCurrentSenseValue(int ADCInput[], int numberOfSamples, int ADC_Resolution, int maxCurrentValue, int* currentSenseValues)
{
	int errorValue;
	errorValue = (pow(2,ADC_Resolution) - 1);
	for (int i=0; i< numberOfSamples; i++)
	{
		if(ADCInput[i] != errorValue)
		{
			ConvertAnalogToDigital(ADCInput, numberOfSamples, ADC_Resolution, maxCurrentValue,currentSenseValues);
		}
	}
	
}
