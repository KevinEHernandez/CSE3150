#include <iostream>
#include <stack>
#include <string>

#include "stack_1.h"

using namespace std;


string names[]  = {"S. Ulam", "Alan Turing", "C. Babbage", "Grace Hopper", "Ada Lovelace"};

stack<node> get_stack_node(const int n) {
  stack<node> s;

  for (int i=0; i < n; i++) {
    if (i >= sizeof(names)) {
      node my_node;
      my_node.name = "Plato";
      my_node.number = i;
      
      s.push(my_node);
    } else {
      node my_node;
      my_node.name = names[i];
      my_node.number = i;
      
      s.push(my_node);
    }
  }

  return s;
}

stack<int> get_stack(const int n) {

  stack<int> s;

  for (int i=0; i < n; i++) {
    s.push(i);
  }

  return s;
}

void pop_stack_node(stack<node>& stack_node){

if(!stack_node.empty())
{stack_node.pop();}
}

void pop_stack(stack<int>& stack_int){
if(!stack_int.empty())
{stack_int.pop();}
}

void push_stack(stack<int>& stack_int, const string& input_file) {
    ifstream file(input_file);

    int value;
    while (file >> value) {
        stack_int.push(value);
    }

    file.close();
}

void push_stack_node(stack<node>& stack_node, const string& input_file) {
    ifstream file(input_file);

    node data;
    while (file >> data.name >> data.number) {
        stack_node.push(data);
    }

    file.close();
}

int stack_sum_int(stack<int>& stack_int) {
    int sum = 0;

    while (!stack_int.empty()) {
        sum += stack_int.top();
        stack_int.pop();
    }

    if (sum < 0) {
        throw std::string("Sum of stack is negative");
    }

    return sum;
}

int stack_sum_node(stack<node>& stack_node) {
    int sum = 0;

    while (!stack_node.empty()) {
        sum += stack_node.top().number;
        stack_node.pop();
    }

    if (sum < 0) {
        throw std::string("Sum of stack is negative");
    }

    return sum;
}