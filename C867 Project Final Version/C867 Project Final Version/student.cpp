#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"
#include "degree.h"
#include "degree.h"
using std::cout;
using std::left;
using std::setw;

// Student Class Empty Constructors
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = -1;
    for (int x = 0; x < courseDayArray; x++)
    {
        this->courseCompletionDays[x] = 0;
    }
    this->degreeProgram = UNDECIDED;
}

// Student Class Full Constructors
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompletionDays[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int x = 0; x < courseDayArray; x++) {
        this->courseCompletionDays[x] = courseCompletionDays[x];
    }
    this->degreeProgram = degreeProgram;
}

// Student Class Destructor
Student::~Student() {

};

// Student Class Getters
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
int* Student::getCourseCompletionDays() {
    return courseCompletionDays;
}
DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

// Student Class Setters
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
    this->age = age;
}
void Student::setCourseCompletionDays(int courseCompletionDays[]) {
    for (int x = 0; x < courseDayArray; x++) {
        this->courseCompletionDays[x] = courseCompletionDays[x];
    }
}
void Student::setDegreeProgram(DegreeProgram program) {
    this->degreeProgram = program;
}



void Student::print() {
    cout << studentID << "\t"
        << "First Name: " << firstName << "\t"
        << "Last Name: " << lastName << "\t"
        << "Age: " << age << "\t"
        << "Days In Course: {" << courseCompletionDays[0] << ", "
        << courseCompletionDays[1] << ", "
        << courseCompletionDays[2] << "} "
        << "Degree Program: " << degreeProgramStrings[getDegreeProgram()];
}