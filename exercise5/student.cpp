#include <iostream>
#include <string>
#include <vector>
#include "student.h"

using namespace std;

double studentGrade(const student& s) {
    double grade = 0.3 * (s.midterm + s.final);
    double hw = 0.0;
    for (int hwgrade : s.hw_grades) {
        hw += hwgrade;
    }
    hw /= s.hw_grades.size();
    
    grade += 0.4 * hw;
    
    return grade;
}


student get_a_student() {
    string name = "Kevin Hernandez";
    vector<int> hws = {100, 0, 0, 100};

    student student = {1, name, 100, 100, hws};

    return student;
}

void print_student(student s) {
    std::cout << "Student ID: " << s.id << std::endl;
    std::cout << "Student Name: " << s.name << std::endl;
    std::cout << "Final Exam Score: " << s.final << std::endl;
    std::cout << "Midterm Exam Score: " << s.midterm << std::endl;
    std::cout << "Homework Grades: ";
    for (int grade : s.hw_grades) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
    std::cout << "Total Class Score: " << studentGrade(s) << std::endl; // Changed calculateTotalScore to studentGrade
}
