#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "stack_1.h"


TEST_CASE("Stack tester") {
    
    SUBCASE("size checking") {

        const int my_stack_size_Zero = 0;
        stack<int> s0 = get_stack(my_stack_size_Zero);
        CHECK(s0.size() == my_stack_size_Zero);

        const int my_stack_size = 6;
        stack<int> s1 = get_stack(my_stack_size);
        CHECK(s1.size() == my_stack_size);

        const int my_stack_size_node = 5;
        stack<node> s2 = get_stack_node(my_stack_size_node);
        CHECK(s2.size() == my_stack_size_node);

        node test = s2.top();
        string top_name = test.name;
        int top_number = test.number;
        CHECK(top_name == "Ada Lovelace");
        CHECK(top_number == 4);

    };

    SUBCASE("stack copying") {

        const int my_stack_size = 6;
        stack<int> s = get_stack(my_stack_size);
        stack<int> t = s;
        CHECK(s == t);

        s.push(99);

        CHECK_FALSE(s.size() == t.size());

        CHECK_FALSE(s == t);

    }

    SUBCASE("push + sum")
{
    const int my_stack_size = 5;
    stack<int> my_stack;

    push_stack(my_stack, "stack.txt");
    CHECK(my_stack.size() == my_stack_size);

    CHECK(stack_sum_int(my_stack) == 10);

}

SUBCASE("pop")
{
    const int my_stack_size = 5;
    stack<int> my_stack = get_stack(my_stack_size);

    pop_stack(my_stack);
    CHECK(my_stack.size() == my_stack_size - 1);

}

SUBCASE("sum")
{
    const int my_stack_size = 5;
    stack<int> my_stack = get_stack(my_stack_size);

    int expected_sum = 10;
    int sum = 0;
    while (!my_stack.empty()) {
        sum += my_stack.top();
        my_stack.pop();
    }

    CHECK(sum == expected_sum);
}


};