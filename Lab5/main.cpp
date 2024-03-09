#include "edep.h"

int main() {
    //m1
    ifstream file1, file2, file3;
    file1.open("Matrix1.txt");
    vector<vector<int>> m1 = ints_read_matrix(file1);
    file1.close();

    //m2
    file2.open("Matrix2.txt");
    vector<vector<int>> m2 = ints_read_matrix(file2);
    file2.close();

    //m3
    file3.open("Matrix3.txt");
    vector<vector<int>> m3 = ints_read_matrix(file3);
    file3.close();

    cout << "Matrix1" << endl;
    printMatrix(m1);
    cout << "Matrix2" << endl;
    printMatrix(m2);
    cout << "Matrix3" << endl;
    printMatrix(m3);


    Expensive_Digraph_exact_paths(m1,m2,m3);
    cout << "Algo ran" << endl;

    cout << "g-" << endl;
    printMatrix(m1);
    cout << "g0" << endl;
    printMatrix(m2);
    cout << "g+" << endl;
    printMatrix(m3);
    
    return 0;
}