#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "queue_1.h"

TEST_CASE("Queue tester")
{
    SUBCASE("size testing")
    {
        const int my_queue_size_Zero = 0;
        queue<int> s0 = get_queue(my_queue_size_Zero);
        CHECK(s0.size() == my_queue_size_Zero);

        const int my_queue_size = 6;
        queue<int> s1 = get_queue(my_queue_size);
        CHECK(s1.size() == my_queue_size);

        const int my_queue_size_node = 5;
        queue<node> s2 = get_queue_node(my_queue_size_node);
        CHECK(s2.size() == my_queue_size_node);

        node test = s2.back();
        string top_name = test.name;
        int top_number = test.number;
        CHECK(top_name == "Ada Lovelace");
        CHECK(top_number == 4);

    }
    SUBCASE("queue copying")
    {
        const int my_queue_size_Zero = 0;
        queue<int> s0 = get_queue(my_queue_size_Zero);
        CHECK(s0.size() == my_queue_size_Zero);

        const int my_queue_size = 6;
        queue<int> s1 = get_queue(my_queue_size);
        CHECK(s1.size() == my_queue_size);

        const int my_queue_size_node = 5;
        queue<node> s2 = get_queue_node(my_queue_size_node);
        CHECK(s2.size() == my_queue_size_node);

        node test = s2.back();
        string top_name = test.name;
        int top_number = test.number;
        CHECK(top_name == "Ada Lovelace");
        CHECK(top_number == 4);
    }
    SUBCASE("push + sum")
{
    const int my_queue_size = 5;
    queue<int> my_queue;

    push_queue(my_queue, "queue.txt");
    CHECK(my_queue.size() == my_queue_size);

    CHECK(queue_sum(my_queue) == 10);

}

SUBCASE("pop")
{
    const int my_queue_size = 5;
    queue<int> my_queue = get_queue(my_queue_size);

    pop_queue(my_queue);
    CHECK(my_queue.size() == my_queue_size - 1);

}

SUBCASE("sum")
{
    const int my_queue_size = 5;
    queue<int> my_queue = get_queue(my_queue_size);

    int expected_sum = 10;
    int sum = 0;
    while (!my_queue.empty()) {
        sum += my_queue.front();
        my_queue.pop();
    }

    CHECK(sum == expected_sum);
}


}