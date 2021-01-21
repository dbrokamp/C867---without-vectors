//
//  student.h
//  C867
//
//  Created by Drew Brokamp on 1/20/21.
//
//
//
// C867: Scripting and Programming - Applications

#ifndef student_h
#define student_h

#include "degree.h"
#include <iostream>
using namespace std;

class Student {
public:
    // Mutators
    void setStudentID(string id);
    void setFirstName(string name);
    void setLastName(string name);
    void setEmailAddress(string address);
    void setAge(int age);
    void setDegreeProgram(DegreeProgram program);
    void setDaysInCourses(int days[3]);
    
    // Accessors
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    int *getDaysInCourses();
    DegreeProgram getDegree() const;

    // Calculators
    int calculateAveregeDaysInCourse();

    // Prints
    void print(StudentInfo info) const;
    
    // Constructor
    Student(string id,
            string name1,
            string name2,
            string address,
            int studentAge,
            int daysInCourse1,
            int daysInCourse2,
            int daysInCourse3,
            DegreeProgram program);
    
    // Deconstructor
    ~Student();
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourses[3];
    DegreeProgram degree;
    string printDegree(DegreeProgram program) const;

};


#endif /* student_h */
