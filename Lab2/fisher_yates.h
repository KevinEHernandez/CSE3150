#ifndef _FISHER_YATES_H_
#define _FISHER_YATES_H_

void print_array(int ary[], int len);
/*{
for (int i = 0; i < len; i++){
std::cout << ary[i] << " ";
}
std::cout << std::end;

}*/

int swap(int * first, int * second);
int fisher_yates(int array[], const int length, int (* random_fcn)());


bool non_negative_prefix(int ary[], int length);
bool non_positive_prefix(int ary[], int length);
bool valid(int ary[], int length);
int* make_array(int length);

#endif