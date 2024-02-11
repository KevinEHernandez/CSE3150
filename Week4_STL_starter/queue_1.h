#ifndef __QUEUE_1_H
#define __QUEUE_1_H

#include <queue>
#include <string>
#include <fstream>

using namespace std;

struct node {
    string name;
    int number;
};

queue<int> get_queue(const int n);
queue<node> get_queue_node(const int n);
void pop_queue(queue<int>& queue_int);
void pop_queue_node(queue<node>& queue_node);
void push_queue(queue<int>& queue_int, const string& input_file);
void push_queue_node(queue<node>& queue_node, const string& input_file);
int queue_sum(queue<int>& queue_int);
int queue_sum_node(queue<node>& queue_node);

#endif
