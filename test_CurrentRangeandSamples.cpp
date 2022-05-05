#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentReading.h"
#include "ADCSensorReading.h"

TEST_CASE("Case for validate current reading input sequence and find the continuous range") {
  int ChargingCurrentReadings[] = {4,5};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  REQUIRE(validateCurrentReadingInputSequence(ChargingCurrentReadings,numOfCCReadings) == true);
  REQUIRE(numberofContinuousRange(ChargingCurrentReadings, numOfCCReadings) == 2);
}

TEST_CASE("Case for checking the given array is invalid with Negative numbers") {
  int ChargingCurrentReadings[] = {-3, 3 ,-5, -4, -3, 11, 12};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  REQUIRE(validateCurrentReadingInputSequence(ChargingCurrentReadings,numOfCCReadings) == false);
}

TEST_CASE("Case for checking the given array in the ascending order") {
  int ChargingCurrentReadings[] = {3, 3 ,5, 4};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  REQUIRE(validateCurrentReadingInputSequence(ChargingCurrentReadings,numOfCCReadings) == true);

}

TEST_CASE("Case checks the given current reading for csv format construction") {
  int ChargingCurrentReadings[] = {3, 3 ,5, 4};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  int expectedStartIndex = 3, expectedEndIndex = 5 , expectedNumOfReadingsInRange = 4;
  char *CurrentReading ;
  char *expectedCurrentReading = "3-5,4" ; 
  RangeReading rangeReading;
  rangeReading = detectCurrentReadingAndFormatOutputInCSVFormat(expectedStartIndex,expectedEndIndex,expectedNumOfReadingsInRange);
  REQUIRE(rangeReading.StartIndex == expectedStartIndex);
  REQUIRE(rangeReading.EndIndex == expectedEndIndex);
  REQUIRE(rangeReading.NumOfReadingsInRange == expectedNumOfReadingsInRange);

}
  
