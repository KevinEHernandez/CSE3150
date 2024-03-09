#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "perfect.h"

TEST_CASE("Test perfect numbers") {
  
  int known_perf[4] = {6, 28, 496, 8128};
  int known_imperf[4] = {1, 2, 3, 4};

  SUBCASE("Known perfect numbers") {
    int size = sizeof(known_perf) / sizeof(known_perf[0]);
    for(int i = 0; i < size; i++)
        CHECK(check_perfect(known_perf[i]));
  };

    SUBCASE("Known imperfect numbers") {
    int size = sizeof(known_imperf) / sizeof(known_imperf[0]);
    for(int i = 0; i < size; i++)
        CHECK_FALSE(check_perfect(known_imperf[i]));
  };

}





