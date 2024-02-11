#ifndef __STACK_1_H
#define __STACK_1_H

#include <stack>
#include <fstream>
#include <string>

using namespace std;

struct node {
  string name;
  int number;
};


stack<int> get_stack(const int n);
stack<node> get_stack_node(const int n);
void pop_stack(stack<int>& stack_int);
void pop_stack_node(stack<node>& stack_node);
void push_stack(stack<int>& stack_int, const string& input_file);
void push_stack_node(stack<node>& stack_node, const string& input_file);
int stack_sum_node(stack<node>& stack_node);
int stack_sum_int(stack<int>& stack_int);

#endif