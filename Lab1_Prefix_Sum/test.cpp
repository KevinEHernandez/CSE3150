#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefix_sum.h"

int testary1[] = {1, -1, 1, -1}; //Never goes below 0
int testary2[] = {-1, 1, -1, 1}; //Never goes above 0
int testary3[] = {1, -1, -1, 1}; //False on both - above and below 0
int testary4[] = {0, 0}; //True on both

TEST_CASE("Nonpositive prefix & Nonnegative prefix functions on {1, -1, 1, -1}") {
    CHECK_FALSE(non_positive_prefix(testary1, sizeof(testary1) / sizeof(testary1[0])));
    CHECK(non_negative_prefix(testary1, sizeof(testary1) / sizeof(testary1[0])) == true);
}

TEST_CASE("Nonpositive prefix & Nonnegative prefix functions on {-1, 1, -1, 1}") {
    CHECK(non_positive_prefix(testary2, sizeof(testary2) / sizeof(testary2[0])) == true);
    CHECK_FALSE(non_negative_prefix(testary2, sizeof(testary2) / sizeof(testary2[0])));
}

TEST_CASE("Nonpositive prefix & Nonnegative prefix functions on {1, -1, -1, 1}") {
    CHECK_FALSE(non_positive_prefix(testary3, sizeof(testary3) / sizeof(testary3[0])));
    CHECK_FALSE(non_negative_prefix(testary3, sizeof(testary3) / sizeof(testary3[0])));
}

TEST_CASE("Nonpositive prefix & Nonnegative prefix functions on {0, 0}") {
    CHECK(non_positive_prefix(testary4, sizeof(testary4) / sizeof(testary4[0])));
    CHECK(non_negative_prefix(testary4, sizeof(testary4) / sizeof(testary4[0])));
}