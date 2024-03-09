#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "edep.h"

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& my_vector) {
    for (size_t i = 0; i < my_vector.size(); ++i) {
        os << my_vector[i];
        if (i != my_vector.size() - 1) {
            os << " ";
        }
    }
    return os;
}

ostream& operator<<(ostream& os, const vector<vector<int>>& my_matrix) {
    for (size_t i = 0; i < my_matrix.size(); ++i) {
        os << my_matrix[i];
        if (i != my_matrix.size() - 1) {
            os << "\n";
        }
    }
    return os;
}

vector<int> ints_read_vector(istream& in_stream) {
    vector<int> res;
    for (int i; in_stream >> i;) {
        res.push_back(i);
    }
    return res;
}

vector<vector<int>> ints_read_matrix(istream& in_stream) {
    vector<vector<int>> matrix;
    string line;
    while (!in_stream.eof()) {
        getline(in_stream, line);
        istringstream is_line(line);
        matrix.push_back(ints_read_vector(is_line));
    }
    return matrix;
}

void Expensive_Digraph_exact_paths(vector<vector<int>>& A,vector<vector<int>>& B, vector<vector<int>>& C)
{
//A = D-1, B = D0, C = D1
int n = B.size();

for(int l = 2; l <= 3*n*n + 1; l++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    if(((A[i][k] + C[k][j]) == 0) || ((A[k][j] + C[i][k]) == 0))
                    {B[i][j] = 0;}

                    if(((C[i][k] + B[k][j]) == 1) || ((C[k][j] + B[i][k]) == 1))
                    {C[i][j] = 1;}

                    if(((A[i][k] + B[k][j]) == -1) || ((A[k][j] + B[i][k]) == -1))
                    {A[i][j] = -1;}

                }
            }
        }
    }

}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& my_vector : matrix){
        for (const auto& element : my_vector){
            cout << element << " ";
        }
        cout << endl;
    }
}

