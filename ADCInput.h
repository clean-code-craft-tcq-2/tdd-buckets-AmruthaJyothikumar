#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ScalingFactor(int ADC_Resolution);
int stdAnalogToDigitalConvertedValue(int ADC_Resolution);
void ConvertAnalogToDigital(int ADCValues[], int numberOfSamples, int ADC_Resolution, int maxCurrentValue, int* currentConversionValues);
void ignoreError(void);
void GetCurrentSensorValue(int ADCValues[], int numberOfSamples, int ADC_Resolution, int maxCurrentValue, int* currentSenseValues);
