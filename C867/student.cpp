//
//  student.cpp
//  C867
//
//  Created by Drew Brokamp on 1/13/21.
//
//
//
// C867: Scripting and Programming - Applications


#include "student.h"
//#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

// MARK: Constructors
Student::Student(string id, string name1, string name2, string address, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program) {
    studentID = id;
    firstName = name1;
    lastName = name2;
    emailAddress = address;
    age = studentAge;
    daysInCourses[0] = daysInCourse1;
    daysInCourses[1] = daysInCourse2;
    daysInCourses[2] = daysInCourse3;
    degree = program;
}

// MARK: Deconstructor
Student::~Student() {
    cout << "Student removed from memory" << endl;
}

// MARK: Prints
void Student::print(StudentInfo info) const {
    switch (info) {
        case STUDENTID:
            cout << studentID << endl;
            break;
        case FIRSTNAME:
            cout << firstName << endl;
            break;
        case LASTNAME:
            cout << lastName << endl;
            break;
        case EMAIL:
            cout << emailAddress << endl;
            break;
        case AGE:
            cout << age << endl;
            break;
        case DEGREE:
            cout << degree << endl;
            break;
        case DAYSTOCOMPLETECOURSES:
            for (int i = 0; i < 3; i ++) {
                cout << "{" << daysInCourses[i] << ", ";
                cout << "}" << endl;
            }
        case ALL:
            cout << "Student ID: " << studentID << setw(10);
            cout << "Name: " << firstName << " " << lastName << setw(20);
            cout << "Email: " << emailAddress << setw(20);
            cout << "Age: " << age << setw(30);
            cout << "Days In Courses: {";
            cout << daysInCourses[0] << ", ";
            cout << daysInCourses[1] << ", ";
            cout << daysInCourses[2] << "}" << setw(30);
            cout << "Degree Program: " << printDegree(degree) << setw(10);
            cout << endl;
        default:
            break;

    }
}

string Student::printDegree(DegreeProgram program) const {
    string degree = " ";
    switch (program) {
        case SOFTWARE:
            return "Software";
            break;
        case SECURITY:
            return "Security";
            break;
        case NETWORK:
            return "Network";
            break;
        case NONE:
            return "None";
            break;
    }
}

// MARK: Mutators
void Student::setStudentID(string id) {
    studentID = id;
}

void Student::setFirstName(string name) {
    firstName = name;
}

void Student::setLastName(string name) {
    lastName = name;
}

void Student::setEmailAddress(string address) {
    emailAddress = address;
}

void Student::setAge(int studentAge) {
    age = studentAge;
}

void Student::setDaysInCourses(int days[3]) {
    for(int i = 0; i < 3; i++) {
        daysInCourses[i] = days[i];
    }
}

void Student::setDegreeProgram(DegreeProgram program) {
    degree = program;
}

int Student::calculateAveregeDaysInCourse() {
    int avg = 0;
    for(int i = 0; i < 3; i++) {
        avg = avg + daysInCourses[i];
    }
    
    return int (ceil(avg / 3));
}

// MARK: Accessors
string Student::getStudentID() const {
    return studentID;
}

string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

string Student::getEmailAddress() const {
    return emailAddress;
}

int Student::getAge() const {
    return age;
}

int *Student::getDaysInCourses() {
    return daysInCourses;
}

DegreeProgram Student::getDegree() const {
    return degree;
}
