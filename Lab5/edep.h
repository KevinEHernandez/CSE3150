#ifndef _EDEP_H_
#define _EDEP_H_
#include <iostream>
using namespace std;

#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& my_vector);
ostream& operator<<(ostream& os, const vector<vector<int>>& my_matrix);
vector<int> ints_read_vector(istream& in_stream);
vector<vector<int>> ints_read_matrix(istream& in_stream);
void Expensive_Digraph_exact_paths(vector<vector<int>>& A,vector<vector<int>>& B, vector<vector<int>>& C);
void printMatrix(const vector<vector<int>>& matrix);

#endif
