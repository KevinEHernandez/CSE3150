/*1. Given a list of 2𝑛 + 1 integers, fill the first 𝑛 elements with 1 and the next 𝑛+1 elements with -1.
2. Use the Fisher-Yates algorithm to randomly scramble this list of 2𝑛 + 1 elements
3. Find the lowest depth of any valley in this list of 2𝑛 + 1 elements
4. Let P1 be the path down to the first occurrence of the lowest valley
5. Let P2 be the start of the lowest valley to the end of the +1, -1 path
6. Drop the last -1 edge from P1 give P1’
7. Put P2 in the front of a new list and attach the end of P2 to the start of P1’
a. This new list is a well-balanced list
b. Also all well-balanced lists of length 2𝑛 are generated with the same uniform probability*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <utility>
int* make_array(int n);
void fisher_yates(int* array, const int n, int (*random_fcn)());
int min_depth(int* array, int n);
int* prefix_sum(int* array, int n);
std::pair<int*, int*> split_list(const int* list, int length);
int* merge_list(int* P1, int* P2, int P1_size, int P2_size);
void print_array(int ary[], int len);

#endif
