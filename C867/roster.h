//
//  roster.h
//  C867
//
//  Created by Drew Brokamp on 1/20/21.
//
//
//
// C867: Scripting and Programming - Applications


#ifndef roster_h
#define roster_h
#include "student.h"


class Roster {
public:
    // Accessors
    Student* getStudent(int index) const;

    // Mutators
    void add(int index,
             string studentID,
             string firstName,
             string lastName,
             string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             string degreeprogram);
    void remove(string studentID);
    
    // Prints
    void printAll();
    void printInvalidEmails();
    void printAverageDaysInCourse(string studentID);
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    // Constructors
    Roster();
    
    // Destructor
    ~Roster();
    
private:
    Student* classRosterArray[5];
};

#endif /* roster_h */
