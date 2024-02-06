#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fisher_yates.h"

int arry_0[] = {};
int arry_1[] = {1, -1};

int first1 = -99;
int save_first1 = first1;
int second1 = 4;
int save_second1 = second1;

int i = swap(& first1, & second1);

TEST_CASE("Fisher-Yates")
{

SUBCASE("Swap tests"){

CHECK_EQ(save_first1, second1);
CHECK_EQ(first1, save_second1);


}



}
