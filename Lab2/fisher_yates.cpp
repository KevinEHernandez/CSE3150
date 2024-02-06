#include "fisher_yates.h"
#include <iostream>

void print_array(int ary[], int len)
{
for (int i = 0; i < len; i++)
{std::cout << ary[i] << " ";}
std::cout << std::endl;
}

int swap(int * first, int * second){
int temp = * first;
*first = *second;
*second = temp;

return 0;
}

int fisher_yates(int* array, const int length, int (* random_fcn)()){

double valid_count = 0;

for(int i = 0; i < length; i++)
{int rnd_location = random_fcn() % (length - i);
swap(&array[i], &array[rnd_location + i]);

if(valid(array, length))
{valid_count++;}
}

return valid_count/length;

}

//Prefix sums
bool non_positive_prefix(int ary[], int length)
{
    bool non_positive = true;
    int sum = 0;

    for (int index = 0; index < length; index++)
    {
        sum += ary[index];
        if (sum > 0)
        {
            non_positive = false;
            break;
        }
    }
    return non_positive;
}

bool non_negative_prefix(int ary[], int length)
{
    bool non_negative = true;
    int sum = 0;

    for (int index = 0; index < length; index++)
    {
        sum += ary[index];
        if (sum < 0)
        {
            non_negative = false;
            break;
        }
    }
    return non_negative;
}

bool valid(int ary[], int length)
{
return non_negative_prefix(ary, length) || non_positive_prefix(ary,length);
}

int* make_array(int length) {
    int* arrayValues = new int[length];

    for (int i = 0; i < length / 2; i++) {
        arrayValues[i] = 1;
    }

    for (int i = 0; i < length / 2; i++) {
        arrayValues[i + length / 2] = -1;
    }

    return arrayValues;
}