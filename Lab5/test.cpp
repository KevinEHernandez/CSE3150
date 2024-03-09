#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <fstream>
#include <algorithm> 
#include <iterator>
#include "edep.h"

TEST_CASE("EDEP before & afters") {
    vector<vector<int>> A = {
        {-1, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2}
    };

    vector<vector<int>> B = {
        {0, 2, 2, 2, 2, 2},
        {2, 0, 2, 2, 2, 2},
        {2, 2, 0, 2, 2, 2},
        {2, 2, 2, 0, 2, 2},
        {2, 2, 2, 2, 0, 2},
        {2, 2, 2, 2, 2, 0}
    };

    vector<vector<int>> C = {
        {2, 1, 2, 2, 2, 2},
        {2, 2, 1, 2, 2, 2},
        {2, 2, 2, 1, 2, 2},
        {2, 2, 2, 2, 1, 2},
        {2, 2, 2, 2, 2, 1},
        {1, 2, 2, 2, 2, 2}
    };

    vector<vector<int>> A2 = vector<vector<int>>(6, vector<int>(6, -1));
    vector<vector<int>> B2 = vector<vector<int>>(6, vector<int>(6, 0));
    vector<vector<int>> C2 = vector<vector<int>>(6, vector<int>(6, 1));

    Expensive_Digraph_exact_paths(A,B,C);
    CHECK(A == A2);
    CHECK(B == B2);
    CHECK(C == C2);
    }
