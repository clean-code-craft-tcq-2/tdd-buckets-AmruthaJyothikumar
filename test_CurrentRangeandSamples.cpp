#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentRangeandSamples.h"
#include "ADCInput.h"

TEST_CASE("Check whether input sequence is valid, get continous range") {
  int InputReadings[] = {4,5,6};
  int NumberofReadings = sizeof(InputReadings) / sizeof(InputReadings[0]);
  REQUIRE(validateInput(InputReadings,NumberofReadings) == true);
  REQUIRE(findContinuousRangeCount(InputReadings, NumberofReadings) == 3);
}

TEST_CASE("Check for negative inputs") {
  int InputReadings[] = {-3,-4 ,-5, 4, 3, -11, 12};
  int NumberofReadings = sizeof(InputReadings) / sizeof(InputReadings[0]);
  REQUIRE(validateInput(InputReadings,NumberofReadings) == false);
}


TEST_CASE("Check for range to print") {
  int InputReadings[] = {3, 3 ,5, 4,3};
  int NumberofReadings = sizeof(InputReadings) / sizeof(InputReadings[0]);
	
  int expectedMin = 3;
  int expectedMax = 5; 
  int expectedNumOfReadingsInRange = 5;
	
  char *OutputReading ;
  char *expectedOutputReading = "3-5,5" ; 
  RangeReading rangeReading;
  rangeReading = detectRangeandOutputInCSVFormat(expectedMin,expectedMax,expectedNumOfReadingsInRange);
  REQUIRE(rangeReading.Min == expectedMin);
  REQUIRE(rangeReading.Max == expectedMax);
  REQUIRE(rangeReading.Count == expectedNumOfReadingsInRange);
}
  
TEST_CASE("Checks for ADC values") {
	
	int ADCValues[] = {512, 1140, 1220, 1560, 2048,4094};
	int numberOfSamples = sizeof(ADCValues) / sizeof(ADCValues[0]);
	int expectedCurrentSenseValues[] = {1, 2, 3, 4, 5, 10};
	int ADC_Resolution = 12;
	int maxCurrentValue = 10;
	int currentSenseValues[numberOfSamples];
	int expectedStartIndex = 1, expectedEndIndex = 5 , expectedNumOfReadingsInRange = 6;
	RangeReading rangeReading;
	GetCurrentSensorValue(ADCValues, numberOfSamples, ADC_Resolution, maxCurrentValue, currentSenseValues);
	 rangeReading = detectRangeandOutputInCSVFormat(expectedStartIndex,expectedEndIndex,expectedNumOfReadingsInRange);
 	 REQUIRE(rangeReading.Min == expectedStartIndex);
 	 REQUIRE(rangeReading.Max == expectedEndIndex);
 	 REQUIRE(rangeReading.Count == expectedNumOfReadingsInRange);

}

