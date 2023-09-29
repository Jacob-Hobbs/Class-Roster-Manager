#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"
using std::cout;
using std::endl;

// Roster Blank Class Constructor
Roster::Roster() {
    this->volume = 0;
    this->indexFinal = -1;
    this->classRosterArray = nullptr;
}

// Implementation of the destructor to release memory that was allocated dynamically
Roster::~Roster() {
    for (int x = 0; x < volume; x++) {
        // Removes rosterArray memory that is allocated dynamically 
        delete this->classRosterArray[x];
    }
    delete this;
}

//Roster Full Class Constructor
Roster::Roster(int volume) {
    this->volume = volume;
    this->indexFinal = -1;
    this->classRosterArray = new Student * [volume];
}

//Roster Class Methods
    //0 => student ID
    //1 => first name
    //2 => last name
    //3 => email address
    //4 => student age
    //5 => days in course (1)
    //6 => days in course (2)
    //7 => days in course (3)
    //8 => degree program
void Roster::parseDataAndAdd(string rawData) {
    std::vector<string> dataPoints;
    std::stringstream inputSStream(rawData);

    while (inputSStream.good()) {
        string data;
        getline(inputSStream, data, ',');
        dataPoints.push_back(data);
    }
    add(dataPoints.at(0),
        dataPoints.at(1),
        dataPoints.at(2),
        dataPoints.at(3),
        stoi(dataPoints.at(4)),
        stoi(dataPoints.at(5)),
        stoi(dataPoints.at(6)),
        stoi(dataPoints.at(7)),
        convert(dataPoints.at(8))
    );
}

// Convert the string passed from the add function into an enum
DegreeProgram Roster::convert(string str) { 
    if (str == "SECURITY") return SECURITY;
    else if (str == "NETWORK") return NETWORK;
    else if (str == "SOFTWARE") return SOFTWARE;
    else return UNDECIDED;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    if (indexFinal < volume) {
        indexFinal++;
        this->classRosterArray[indexFinal] = new Student();
        this->classRosterArray[indexFinal]->setStudentID(studentID);
        this->classRosterArray[indexFinal]->setFirstName(firstName);
        this->classRosterArray[indexFinal]->setLastName(lastName);
        this->classRosterArray[indexFinal]->setEmailAddress(emailAddress);
        this->classRosterArray[indexFinal]->setAge(age);
        int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
        this->classRosterArray[indexFinal]->setCourseCompletionDays(days);
        this->classRosterArray[indexFinal]->setDegreeProgram(degreeProgram);
    }

    // Error message is displayed if the defined student count limit is exceeded
    else {
        std::cerr << std::endl << "Error! You have exceeded your defined student count limit!" << std::endl << std::endl;
    }

}

// Allows all roster data to be put to output
void Roster::printAll() {
    cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
    std::cout << "All students:" << std::endl << std::endl;
    for (int x = 0; x <= this->indexFinal; x++) {

        (this->classRosterArray)[x]->print();
        std::cout << std::endl;
    }
    std::cout << std::endl;

}

// Allows certain roster entries to be removed in realation to their student ID
void Roster::remove(string studentID) {
    bool found = false;
    for (int x = 0; x <= indexFinal; x++) {
        if (this->classRosterArray[x]->getStudentID() == studentID) {
            found = true;
            delete this->classRosterArray[x];
            // Replaces the removed element in the roster array with the last element
            this->classRosterArray[x] = this->classRosterArray[indexFinal];
            indexFinal--;
            std::cout << "Successfully removed student " << studentID << " from roster." << std::endl << std::endl;
        }
    }
    if (!found) { // If the student ID does not exist, the function prints an error message indicating that the student was not found.
        std::cerr << "Error! Student " << studentID << " was not found!" << std::endl << std::endl;
    }

}

// Puts to output the average days in course
void Roster::printAverageDaysInCourse(string studentID) {
    bool found = false;

    for (int x = 0; x <= indexFinal; x++) {
        if (this->classRosterArray[x]->getStudentID() == studentID) {
            found = true;
            int* days = this->classRosterArray[x]->getCourseCompletionDays();
            // Calculates the average number of days in course
            double averageDays = static_cast<double>(days[0] + days[1] + days[2]) / 3.0;
            std::cout << "Average course completion days for student " << studentID << " is: "
                << averageDays << std::endl << std::endl;
        }
    }
    if (!found) {
        std::cerr << "ERROR! Student: " << studentID << " NOT FOUND!" << std::endl << std::endl;
    }

}

// Finding invalid roster email entries 
// Qualifiers: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ')
// Students "John Smith" & "Suzan Erickson" should display as with error with below defined parameters
void Roster::printInvalidEmails() {
    std::cout << "Students With Invalid Email Addresses:" << std::endl << std::endl;
    bool found = false;

    for (int x = 0; x <= indexFinal; x++) {
        string email = this->classRosterArray[x]->getEmailAddress();
        if ((email.find('.') == string::npos) || (email.find('@') == string::npos) || !(email.find(' ') == string::npos)) {
            found = true;
            this->classRosterArray[x]->print();
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    if (!found) {
        std::cout << "No Invalid emails found!" << std::endl << std::endl;
    }
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    std::cout << "Students in the " << degreeProgramStrings[degreeProgram] << " degree program:" << std::endl << std::endl;
    for (int x = 0; x <= indexFinal; x++) {
        if (this->classRosterArray[x]->getDegreeProgram() == degreeProgram) {
            this->classRosterArray[x]->print();
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}