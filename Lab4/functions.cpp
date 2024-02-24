#include "functions.h"
#include <iostream>
#include <utility>

/*1. Given a list of 2𝑛 + 1 integers, fill the first 𝑛 elements with 1 and the next 𝑛+1 elements with -1.
2. Use the Fisher-Yates algorithm to randomly scramble this list of 2𝑛 + 1 elements
3. Find the lowest depth of any valley in this list of 2𝑛 + 1 elements
4. Let P1 be the path down to the first occurrence of the lowest valley
5. Let P2 be the start of the lowest valley to the end of the +1, -1 path
6. Drop the last -1 edge from P1 give P1’
7. Put P2 in the front of a new list and attach the end of P2 to the start of P1’
a. This new list is a well-balanced list
b. Also all well-balanced lists of length 2𝑛 are generated with the same uniform probability*/

/*1. Given a list of 2𝑛 + 1 integers, fill the first 𝑛 elements with 1 and the next 𝑛+1 elements with -1.*/
int* make_array(int n) {
    int* arrayValues = new int[2*n+1];

    for (int i = 0; i < n; i++) {
        arrayValues[i] = 1;
    }

    for (int i = n; i < 2*n+1; i++) {
        arrayValues[i] = -1;
    }

    return arrayValues;
}

/*2. Use the Fisher-Yates algorithm to randomly scramble this list of 2𝑛 + 1 elements*/
int swap(int * first, int * second){
    int temp = * first;
    *first = *second;
    *second = temp;
    return 0;
}

void fisher_yates(int* array, const int n, int (*random_fcn)()){
    int length = 2 * n + 1;
    for(int i = 0; i < length - 1; i++) {
        int rnd_location = random_fcn() % (length - i) + i;
        swap(&array[i], &array[rnd_location]);
    }
}

/*3. Find the lowest depth of any valley in this list of 2𝑛 + 1 elements*/
int min_depth(int* array, int n) {

    int length = 2*n + 1;
    int lowest = 0;
    int prefixsum = 0;

    for(int i = 0; i < length; i++) {
        prefixsum += array[i];

        if(prefixsum < lowest) {
            lowest = prefixsum;
        }
    }
    return lowest;
}

int* prefix_sum(int* array, int n) {
    int length = 2 * n + 1;
    int* PSarray = new int[length];
    int sum = 0;

    PSarray[0] = 0;

    for(int i = 1; i < length; i++) {
        sum += array[i - 1];
        PSarray[i] = sum;
    }
    
    return PSarray;
}


/*4. Let P1 be the path down to the first occurrence of the lowest valley
5. Let P2 be the start of the lowest valley to the end of the +1, -1 path*/
/*6. Drop the last -1 edge from P1 give P1’
7. Put P2 in the front of a new list and attach the end of P2 to the start of P1’
a. This new list is a well-balanced list
b. Also all well-balanced lists of length 2𝑛 are generated with the same uniform probability*/

std::pair<int*, int*> split_list(const int* list, int length) {
    int sum = 0;
    int lowest_depth = 0;
    int lowest_depth_index = 0;
    for (int i = 0; i < length; i++) {
        sum += list[i];
        if (sum < lowest_depth) {
            lowest_depth = sum;
            lowest_depth_index = i;
        }
    }
    int* P1 = new int[lowest_depth_index + 1];
    int* P2 = new int[length - lowest_depth_index - 1];
    for (int i = 0; i <= lowest_depth_index; ++i) {
        P1[i] = list[i];
    }
    for (int i = lowest_depth_index + 1; i < length; ++i) {
        P2[i - lowest_depth_index - 1] = list[i];
    }
    return std::make_pair(P1, P2);
}

/*6. Drop the last -1 edge from P1 give P1’
7. Put P2 in the front of a new list and attach the end of P2 to the start of P1’
a. This new list is a well-balanced list
b. Also all well-balanced lists of length 2𝑛 are generated with the same uniform probability*/

int* merge_list(int* P1, int* P2, int P1_size, int P2_size) {
    //Drop last -1
    P1_size--;
    
    int* final_list = new int[P1_size + P2_size];
    int index = 0;
    for (int i = 0; i < P2_size; ++i) {
        final_list[index++] = P2[i];
    }
    for (int i = 0; i < P1_size; ++i) {
        final_list[index++] = P1[i];
    }
    return final_list;
}

void print_array(int ary[], int len)
{
for (int i = 0; i < len; i++)
{std::cout << ary[i] << " ";}
std::cout << std::endl;
}

