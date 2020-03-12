#ifndef CAREER_H
#define CAREER_H

#include "Semester.hpp"

class Career {

public:

  vector<Semester>semesters;

  void setSemesters(string textfile);
  void displayAllCourses();
  float newCalcGPA();
  // float lifeGPA();
  void menu();
};

#endif
