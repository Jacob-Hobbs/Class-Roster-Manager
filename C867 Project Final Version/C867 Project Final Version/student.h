#pragma once
#include "degree.h"

class Student {
	// Days in course array size set as 3
public:
	const static int courseDayArray = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int courseCompletionDays[courseDayArray];
	DegreeProgram degreeProgram;

public:
	// Student Empty Constructor
	Student();

	// Student Full Constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompletionDays[], DegreeProgram degreeProgram);

	// Student Getter Methods
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int* getCourseCompletionDays();
	DegreeProgram getDegreeProgram() const;

	// Student Setter Methods
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setCourseCompletionDays(int courseCompletionDays[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print();

	// Student Deconstructor
	~Student();
};
