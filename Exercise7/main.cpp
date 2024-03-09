#include <iostream>
#include <vector>
#include "perfect.h"

using namespace std;

int main()
{

    string line;
    int given_int;
    cout << "Enter an integer: ";
    cin >> line;
    given_int = stoi(line);

    if (check_perfect(given_int)) {
        cout << given_int << "is perfect" << endl;
    } else {
        cout << given_int << "is not perfect" << endl;
    }

}

