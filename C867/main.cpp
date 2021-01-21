//
//  main.cpp
//  C867
//
//  Created by Drew Brokamp on 1/13/21.
//
//
//
// C867: Scripting and Programming - Applications


#include "roster.h"
#include <sstream>

int main(int argc, const char * argv[]) {
    
    // Required Info
    cout << "C867: Scripting and Programming - Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 001486248" << endl;
    cout << "Name: Drew Brokamp" << endl;
    cout << endl << endl;
    
    // Student Data Table
    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Drew,Brokamp,dbroka1@wgu.edu,34,18,19,20,SOFTWARE"};
    
    // Create instance of Roster
    Roster classRoster;
    
    // Parse studentData, create new Student objects and add to classRosterArray
    for (int i = 0; i < NUM_STUDENTS; i++) {
        stringstream newStudent(studentData[i]);
        string newStudentInfo[9];
        
        for (int t = 0; t < STUDENT_INFO_ITEMS; t++) {
            getline(newStudent, newStudentInfo[t], ',');
        }
        
        classRoster.add(i,
                        newStudentInfo[0],
                        newStudentInfo[1],
                        newStudentInfo[2],
                        newStudentInfo[3],
                        stoi(newStudentInfo[4]),
                        stoi(newStudentInfo[5]),
                        stoi(newStudentInfo[6]),
                        stoi(newStudentInfo[7]),
                        newStudentInfo[8]);
    }
    
    // Print all students
    classRoster.printAll();
    
    // Print all Invalid Emails
    classRoster.printInvalidEmails();
    cout << endl;
    
    // Print average days spent in a course by student
    cout << "Average days spent in a class by student:" << endl;;
    for(int i = 0; i < NUM_STUDENTS; i++) {
       classRoster.printAverageDaysInCourse(classRoster.getStudent(i)->getStudentID());
    }
    cout << endl;
    
    // Print students in SOFTWARE program
    cout << "Students in SOFTWARE degree program: " << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    
    // Remove student A3
    cout << "Remove student: A3" << endl;
    classRoster.remove("A3");
    cout << endl;
    
    // Print all stuents
    cout << endl;
    cout << "All students in roster: " << endl;
    classRoster.printAll();
    cout << endl;
    
    // Remove student A3
    cout << "Remove student: A3" << endl;
    classRoster.remove("A3");
    cout << endl;
    cout << endl;

    // Destroy classRoster
    return 0;
}



