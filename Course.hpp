#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
using namespace std;

struct Course {

  string name;
  string grade;
  string creditHours;
  float creditHoursInt;
  float courseNG;
  float courseWeight;

  void setCourseNumericalGrade() {
    if(grade == "A") {
      courseNG = 4.0;
    }
    if(grade == "B") {
      courseNG = 3.0;
    }
    if(grade == "C") {
      courseNG = 2.0;
    }
    if(grade == "D") {
      courseNG = 1.0;
    }
    if(grade == "F") {
      courseNG = 0.0;
    }
  }
  void setCourseWeight() {

    istringstream (creditHours) >> creditHoursInt;
    courseWeight = courseNG * creditHoursInt;
  }
};

#endif
