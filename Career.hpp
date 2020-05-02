#ifndef CAREER_H
#define CAREER_H

#include "Semester.hpp"

class Career {

public:

  vector<Semester>semesters;
  int numSemesters;
  string fileName;

  void setSemesters(string textfile);
  void buildCareer();
  void saveCareer();
  void displayAllCourses();
  float clemsonGPA();
  float lifeGPA();
  void menu(string textfile);
};

#endif
