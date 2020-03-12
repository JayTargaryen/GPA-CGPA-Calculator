#include "Career.hpp"

void Career::setSemesters(string textfile) {

  ifstream inFS;
  inFS.open(textfile);
  string temps;
  getline(inFS,temps);
  int numSemesters;
  istringstream (temps) >> numSemesters;
  int i = 0;

  while(i < numSemesters) {
    Semester semester1;
    vector<Course>totalCourses;
    string temp;

    getline(inFS,semester1.semesterNum);
    getline(inFS,semester1.semesterType);
    getline(inFS,temp);
    int x;
    istringstream (temp) >> x;
    semester1.numClasses = x;
    for(int j = 0; j < semester1.numClasses; j++) {
      Course course1;
      getline(inFS, course1.name);
      getline(inFS, course1.grade);
      getline(inFS, course1.creditHours);
      course1.setCourseNumericalGrade();
      course1.setCourseWeight();
      totalCourses.push_back(course1);
    }
    semester1.courses = totalCourses;
    semester1.calcSemesterGPA();
    semesters.push_back(semester1);
    i++;
  }
}
void Career::displayAllCourses() {
  int size = semesters.size();

  for(int i = 0; i < size; i++) {
    Semester sem1 = semesters.at(i);
    sem1.printSemester();
    cout << endl;
  }
}
// float Career::clemsonGPA() {
// }
float Career::newCalcGPA() {

  float sum = 0;
  float totalCredits = 0;

  for(int i = 0; i < semesters.size(); i++) {
    Semester sem1 = semesters.at(i);
    vector<Course>courses = sem1.courses;
    int size = courses.size();
    for(int j = 0; j < size; j++) {
      Course course1 = courses.at(j);
      sum += course1.courseWeight;
      totalCredits += course1.creditHoursInt;
    }
  }
  float GPA = sum / totalCredits;
  return GPA;

}
void Career::menu() {

  int answer;
  int task;
  char done = 'n';
  string unavailable = "Sorry, that function isn't available at the moment\n";
  while(done == 'n') {
    cout << "So what would you like to do now?" << endl
         << "Task 1: Print a semester" << endl
         << "Task 2: Print entire academic career" << endl
         << "Task 3: Add a new semester" << endl
         << "Task 4: Print GPA" << endl;
         // << "Task 5: Print Life GPA" << endl;
    cin >> task;
    if(task == 1) {
      int semesterNum;
      cout << "Which semester would you like to print out?" << endl;
      cin >> semesterNum;
      semesterNum -= 1;
      Semester sem1 = semesters.at(semesterNum);
      sem1.printSemester();
    }
    else if(task == 2) {
      displayAllCourses();
    }
    else if(task == 3) {
      cout << unavailable;
    }
    else if(task == 4) {
      float count = newCalcGPA();
      cout << count << endl;
    }
    // else if(task == 5) {
    //   float count = lifeGPA();
    //   cout << count << endl;
    // }
    else {
      cout << "You didn't pick a valid entry" << endl;
    }
    cout << "All done?" << endl;
    cin >> done;
  }
}
