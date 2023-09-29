#include <iostream>
#include <iomanip>
#include "student.h"
#include "degree.h"
#include "roster.h"
using std::cout;
using std::endl;
using std::setw;
using std::left;

// Introducing main() function and required function calls
int main() {
    const int studentCount = 5;
    // Provided data for project from studentData Table
    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jacob,Hobbs,jhobb55@wgu.edu,24,31,28,30,SOFTWARE"
    };

    // Requirement Screen Print Out
    cout << left << setw(0) << " ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯";
    cout << left << setw(1) << "\n | Course Title: C867 Scripting and Programming - Applications |";
    cout << left << setw(2) << "\n | Programming Language Used: C++                              |";
    cout << left << setw(3) << "\n | WGU Student ID: 001543116                                   |";
    cout << left << setw(4) << "\n | Name: Jacob Hobbs                                           |";
    cout << left << setw(5) << "\n ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯";
    cout << endl << endl;
    cout << "Now parsing data and adding students to new roster..." << endl << endl;

    // New Roster Synthesis
    Roster* classRoster = new Roster(studentCount);

    // Students are added to the new roster
    // Raw data obtained from studentData Table is parsed
    for (int x = 0; x < studentCount; x++) {
        classRoster->parseDataAndAdd(studentData[x]);
    }

    // Notification of parsing and addition of students completion 
    cout << "Parsing complete. All students added successfully." << endl << endl;

    // Display of Parsed Data
    classRoster->printAll();
    classRoster->printInvalidEmails();

    // Looped for each item
    // Synthesis of error message displaying unfound student
    for (int x = 0; x < classRoster->volume; x++) {
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[x]->getStudentID());
    }

    classRoster->printByDegreeProgram(SOFTWARE);
    classRoster->remove("A3");
    classRoster->printAll();
    classRoster->remove("A3");

    return 0;
}