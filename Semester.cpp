#include "Semester.hpp"

void Semester::calcSemesterGPA() {

  float sum = 0;
  float totalCredits = 0;
  int size = courses.size();
  for(int i = 0; i < size; i++) {
    Course course1 = courses.at(i);
    sum += course1.courseWeight;
    totalCredits += course1.creditHoursInt;
  }
  GPA = sum / totalCredits;
}
void Semester::printSemester() {

  cout << "*******************************"
       << endl << semesterNum << endl
       << semesterType << endl << endl;
  for(int i = 0; i < numClasses; i++) {
    Course course1 = courses.at(i);
    cout << "*" << course1.name << "*" << endl
         << "Course Grade:  " << course1.grade << endl
         << "Credit Hours:  " << course1.creditHours << endl
         << fixed << setprecision(1)
         << "Course GPA:    " << course1.courseNG << endl
         << "Course Weight: " << course1.courseWeight << endl
         << endl;
  }
  cout << setprecision(2) << "Semester GPA:  " << GPA << endl;
}
