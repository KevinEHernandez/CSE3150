#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct student {
  int id;
  string name;
  int final;
  int midterm;
  vector<int> hw_grades;
};

student get_a_student();
void print_student(student s);
double studentGrade(const student& s);

#endif
