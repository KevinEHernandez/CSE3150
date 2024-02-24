#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "functions.h"

TEST_CASE("Testing functions") {
    SUBCASE("Check lowest depth") {
        int array[] = {1, 1, 1, -1, -1, -1, -1};
        int n = 3; // Half of the size of the array
        CHECK(min_depth(array, n) == -1);
    }

    SUBCASE("Check shuffle") {
        int n = 4;
        int* array = make_array(n);

        int* original = new int[2*n + 1];
        std::copy(array, array + 2*n + 1, original);
        
        fisher_yates(array, n, std::rand);
        bool same = true;
        for (int i = 0; i < 2*n + 1; ++i) {
            if (array[i] != original[i]) {
                same = false;
                break;
            }
        }
        CHECK(same);
    }

    SUBCASE("Check prefix sums ") {
        int n = 4;
        int* array = make_array(n);
        int* prefixSums = prefix_sum(array, n);
        int expected[] = {0, 1, 2, 3, 4, 3, 2, 1, 0};
        for (int i = 0; i < 2 * n + 1; i++) {
            CHECK(prefixSums[i] == expected[i]);
        }
    }

    SUBCASE("Check final list") {
        int n = 4;
        int* array = make_array(n);
        fisher_yates(array, n, std::rand);
        int* P1;
        int* P2;
        std::tie(P1, P2) = split_list(array, 2 * n + 1);
        int* finalList = merge_list(P1, P2, n, n + 1);
        CHECK(finalList[0] == 1);
        CHECK(finalList[2 * n - 1] == -1);
    }
}
