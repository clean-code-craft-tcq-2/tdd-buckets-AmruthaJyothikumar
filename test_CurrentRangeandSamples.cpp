#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"

TEST_CASE("test the current range and samples") {
  REQUIRE(getrange({4,5}) == {4,5});
  REQUIRE(getcount({4,5}) == 2);
}
  
