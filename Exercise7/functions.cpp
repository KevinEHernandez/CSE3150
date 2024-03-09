#include "perfect.h"
#include <vector>

bool check_perfect(int x){

    vector<int> divisors;
    vector<int> repeats(x-1, x);
    int i = 1;
    for_each(repeats.begin(), repeats.end(), [&divisors, &i, x](int &x) {
        if (x % i == 0) {
            divisors.push_back(i);
        }
        i++;
    });

    int sum = 0;
    for(int i = 0; i < divisors.size(); i++)
    {sum += divisors[i];}

    return sum == x;

}
