#include <iostream>
#include <cstdlib>
#include "fisher_yates.h"

using namespace std;

int main() {
    string string_n;
    cout << "Enter the number of open-parens: " << endl;
    cin >> string_n;

    int n = stoi(string_n);

    int arrayValues[2 * n];

    for (int i = 0; i < n; i++) {
        arrayValues[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        arrayValues[i + n] = -1;
    }

    print_array(arrayValues, 2 * n);

    int len = 2 * n;
    int valid_lists = 0;
    int total_lists = len;

    double avg_ratio = 0;
    int numerator = 0;
    int iterations = 0;
    int max_iterations;

    cout << "Enter the maximum number of iterations: ";
    cin >> max_iterations;

    int* array;
    for (iterations = 1; iterations <= max_iterations; iterations++) {
        array = make_array(len);

        numerator += fisher_yates(array, len, rand);
        avg_ratio = static_cast<double>(numerator) / iterations;

        delete[] array;
    }

    cout << "Final average ratio: " << avg_ratio << " after " << iterations - 1 << " iterations." << endl;

    return 0;
}
