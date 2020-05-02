#ifndef SEMESTER_H
#define SEMESTER_H

#include "Course.hpp"

class Semester {

public:

  float GPA;
  string semesterNum;
  string semesterType;
  int numClasses;
  vector<Course>courses;
  
  void calcSemesterGPA();
  void printSemester();
};

#endif
