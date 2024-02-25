#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "student.h"

TEST_CASE("Student Grade function") {
    SUBCASE("100 midterm & final, {100, 100, 55} hw")
    {student s;
    s.midterm = 100;
    s.final = 100;
    s.hw_grades = {100, 100, 55};

    double expected_score = 0.3*(100+100) + 0.4* (100 + 100 + 55)/3; 
    double actual_score = studentGrade(s);
    CHECK(actual_score == expected_score);
    }

    SUBCASE ("70 midterm & final, {100, 100} hw")
    {student s;
    s.midterm = 70;
    s.final = 70;
    s.hw_grades = {100, 100};

    double expected_score = 0.3*(70+70) + 0.4* (100 + 100)/2; 
    double actual_score = studentGrade(s);
    CHECK(actual_score == expected_score);    
    }

    SUBCASE ("100 midterm & final, {0, 0} hw")
    {student s;
    s.midterm = 100;
    s.final = 100;
    s.hw_grades = {0, 0};

    double expected_score = 0.3*(100+100) + 0.4* (0+0)/2; 
    double actual_score = studentGrade(s);
    CHECK(actual_score == expected_score);    
    }

}