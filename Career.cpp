#include "Career.hpp"

void Career::buildCareer() {

  string temp;
  bool done = false;
  bool coursesDone = false;
  Semester semester1;
  int semesterCount = 0;
  int courseCount = 0;

  cout << "Welcome! We'll now build your career." << endl;
  while(done == false) {
    cout << "Which term is this? Exmaple: Fall 2016" << endl;
    cin >> ws;
    getline(cin, semester1.semesterType);
    vector<Course>totalCourses;
    semesterCount++;
    //cout << "semseter count: " << semesterCount << endl;
    semester1.semesterNum = "Semester " + to_string(semesterCount);

    cout << "Now it's time to enter the information for your courses." << endl;
    while(coursesDone == false) {
      Course course1;
      courseCount++;
      cout << "Course name: " << endl;
      getline(cin, course1.name);
      cout << "Course Grade A-F: " << endl;
      getline(cin, course1.grade);
      cout << "Course credit hours: " << endl;
      getline(cin, course1.creditHours);
      course1.setCourseNumericalGrade();
      course1.setCourseWeight();
      totalCourses.push_back(course1);
      cout << "Do you want to add another course?" << endl;

      getline(cin, temp);
      if(!(temp == "yes" || temp == "y")) {
        coursesDone = true;
      }
    }
    coursesDone = false;
    semester1.courses = totalCourses;
    semester1.numClasses = courseCount;
    courseCount = 0;
    semester1.calcSemesterGPA();
    semesters.push_back(semester1);
    cout << "Would you like to add another semester?" << endl;
    cin >> ws;
    getline(cin, temp);
    if(!(temp == "yes" || temp == "y")) {
      done = true;
    }
  }
  numSemesters = semesterCount;
}
void Career::setSemesters(string textfile) {

  fileName = textfile;
  ifstream inFS;
  inFS.open(textfile);
  string temps;
  getline(inFS,temps);
  // int numSemesters;
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
  int size = numSemesters;

  for(int i = 0; i < size; i++) {
    Semester sem1 = semesters.at(i);
    sem1.printSemester();
    cout << endl;
  }
}
float Career::clemsonGPA() {

  float sum = 0;
  float totalCredits = 0;

  for(int i = 0; i < semesters.size(); i++) {
    Semester sem1 = semesters.at(i);
    if(!(sem1.semesterType[1] == 'u')) {
      vector<Course>courses = sem1.courses;
      int size = courses.size();
      for(int j = 0; j < size; j++) {
        Course course1 = courses.at(j);
        sum += course1.courseWeight;
        totalCredits += course1.creditHoursInt;
      }
    }
    else {
      //cout << sem1.semesterType << endl;
    }
  }
  float GPA = sum / totalCredits;
  return GPA;
}
float Career::lifeGPA() {

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
void Career::menu(string textfile) {
  //
  int answer;
  int task;
  char done = 'n';
  string unavailable = "Sorry, that function isn't available at the moment\n";
  cout << "\n*****HELLO! WELCOME TO YOUR GPA CALCULATOR!!*****" << endl;
  while(done == 'n') {
    cout << "So what would you like to do now?" << endl
         << "Task 1: Print a semester" << endl
         << "Task 2: Print entire academic career" << endl
         << "Task 3: Add a new semester" << endl
         << "Task 4: Print Clemson GPA" << endl
         << "Task 5: Print Life GPA" << endl;
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
      float count = clemsonGPA();
      cout << count << endl;
    }
    else if(task == 5) {
      float count = lifeGPA();
      cout << count << endl;
    }
    else {
      cout << "You didn't pick a valid entry" << endl;
    }
    cout << "All done?" << endl;
    cin >> done;
  }
  saveCareer();
}
void Career::saveCareer() {

  ofstream osFS;

  osFS.open("UserFiles/"  + fileName + ".txt");
  osFS << numSemesters << "\n";
  int i = 1;
  while(i <= numSemesters) {
    Semester semester1 = semesters.at(i - 1);
    osFS << "Semester " << i << "\n";
    osFS << semester1.semesterType << "\n";
    osFS << semester1.numClasses << "\n";
    for(int j = 0; j < semester1.numClasses; j++) {
      Course course1 = semester1.courses.at(j);
      osFS << course1.name << "\n"
           << course1.grade << "\n"
           << course1.creditHours << "\n";
    }
    i++;
  }
  osFS.close();
}
