#include "functions.h"
#include <iostream>
#include <cstdlib>
#include <tuple>

int main() {
    int n = 2;
    int* array = make_array(n);
    std::cout << "Initial Array: ";
    print_array(array, 2 * n + 1);

    fisher_yates(array, n, std::rand);
    std::cout << "Shuffled Array: ";
    print_array(array, 2 * n + 1);

    int minDepth = min_depth(array, n);
    std::cout << "Lowest Depth: " << minDepth << std::endl;

    int* P1;
    int* P2;
    std::tie(P1, P2) = split_list(array, 2 * n + 1);
    std::cout << "P1: ";
    print_array(P1, n);
    std::cout << "P2: ";
    print_array(P2, n + 1);

    int* finalList = merge_list(P1, P2, n, n + 1);
    std::cout << "Balanced List: ";
    print_array(finalList, 2 * n);

    std::cout << "Prefix Sums: ";
    int* prefixSums = prefix_sum(finalList, n);
    print_array(prefixSums, 2 * n + 1);

}
