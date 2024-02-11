#include <iostream>
#include <queue>
#include <string>

#include "queue_1.h"

using namespace std;


string names[]  = {"S. Ulam", "Alan Turing", "C. Babbage", "Grace Hopper", "Ada Lovelace"};

queue<node> get_queue_node(const int n) {
  queue<node> s;

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

queue<int> get_queue(const int n) {

  queue<int> s;

  for (int i=0; i < n; i++) {
    s.push(i);
  }

  return s;
}

void pop_queue_node(queue<node>& queue_node){
if(!queue_node.empty())
{queue_node.pop();}
}

void pop_queue(queue<int>& queue_int){
if(!queue_int.empty())
{queue_int.pop();}
}

void push_queue(queue<int>& queue_int, const string& input_file) {
  ifstream file(input_file);

  int value;
  while (file >> value)
  {queue_int.push(value);}

  file.close();   
}

void push_queue_node(queue<node>& queue_node, const string& input_file) {
    ifstream file(input_file);

    node data;
    while (file >> data.name >> data.number) {
        queue_node.push(data);
    }

    file.close();
}

int queue_sum(queue<int>& queue_int) {
    int sum = 0;

    while (!queue_int.empty()) {
        sum += queue_int.front();
        queue_int.pop();
    }

    if (sum < 0) {
        throw std::string("Sum of queue is negative");
    }

    return sum;
}

int queue_sum_node(queue<node>& queue_node) {
    int sum = 0;

    while (!queue_node.empty()) {
        sum += queue_node.front().number;
        queue_node.pop();
    }

    if (sum < 0) {
        throw std::string("Sum of queue is negative");
    }

    return sum;
}

