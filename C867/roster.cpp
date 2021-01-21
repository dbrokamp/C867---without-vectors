//
//  roster.cpp
//  C867
//
//  Created by Drew Brokamp on 1/13/21.
//
//
//
// C867: Scripting and Programming - Applications


#include "roster.h"
#include <regex>

// MARK: Constructors
Roster::Roster() {
    for(int i = 0; i < NUM_STUDENTS; i++) {
        classRosterArray[i] = nullptr;
    }
}

// MARK: Destructors
Roster::~Roster() {
    
    cout << "Roster destructor: " << endl;
    
    // Remove objects from classRosterArray
    for(int i = 0; i < NUM_STUDENTS; i++) {
        if (classRosterArray[i] == nullptr) {
            continue;
        } else {
            delete classRosterArray[i];
        }
    }
    
    cout << "Instance of Roster has been removed from memory." << endl << endl;
}

// MARK: Prints
void Roster::printAll() {
    
    for(int i = 0; i < NUM_STUDENTS; i++) {
        if (classRosterArray[i] == nullptr) {
            continue;
        } else {
            classRosterArray[i]->print(ALL);
        }
    }
    
}

void Roster::printInvalidEmails() {
    
    string explanation = "Email must in the format abc@def.efg and cannot include spaces.";
    
    cout << endl;
    cout << "Invalid emails: " << endl;
    
    const regex emailPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (!regex_match(classRosterArray[i]->getEmailAddress(), emailPattern)) {
            cout << classRosterArray[i]->getEmailAddress() << " is invalid. " << explanation << endl;;
        }
    }
}

void Roster::printAverageDaysInCourse(string id) {
    
    for(int i = 0; i < NUM_STUDENTS; i++) {
        if (classRosterArray[i]->getStudentID() == id) {
            cout << "Student: " << id << " averages " << classRosterArray[i]->calculateAveregeDaysInCourse() << " in a course." << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram program) {
    
    for(int i = 0; i < NUM_STUDENTS; i++) {
        if (classRosterArray[i]->getDegree() == program) {
            classRosterArray[i]->print(ALL);
        }
    }
}

// MARK: Mutators
void Roster::add(int index,
                 string id,
                 string name1,
                 string name2,
                 string address,
                 int studentAge,
                 int daysInCourse1,
                 int daysInCourse2,
                 int daysInCourse3,
                 string program) {
    
    DegreeProgram studentProgram = NONE;
    if (program == "SOFTWARE") {
        studentProgram = SOFTWARE;
    } else if (program == "NETWORK") {
        studentProgram = NETWORK;
    } else if (program == "SECURITY") {
        studentProgram = SECURITY;
    }

    classRosterArray[index] = new Student(id,
                                      name1,
                                      name2,
                                      address,
                                      studentAge,
                                      daysInCourse1,
                                      daysInCourse2,
                                      daysInCourse3,
                                      studentProgram);

}

void Roster::remove(string id) {
    bool studentExists = false;
    for(int i = 0; i < NUM_STUDENTS; i++) {
        if (classRosterArray[i] == nullptr) {
            studentExists = false;
        } else if (classRosterArray[i]->getStudentID() == id) {
            studentExists = true;
            classRosterArray[i] = nullptr;
        }
    }
    
    if (studentExists == true) {
        cout << "The student " << id << " was successfully removed from the roster.";
    }
    if (studentExists == false) {
        cout << "The student " << id << " does not exist in the roster.";
    }
}


// MARK: Accessors
Student* Roster::getStudent(int index) const {
    return classRosterArray[index];
}
