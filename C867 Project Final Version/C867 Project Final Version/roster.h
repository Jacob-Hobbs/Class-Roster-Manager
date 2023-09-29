#pragma once
#include "student.h"

class Roster {
	//Define data elements of the roster:
		// indexFinal = the last element position of the roster array; the last student
		// volume = assigned capacity of roster
		// classRosterArray = array of pointers as required
public:
	int indexFinal;
	int volume;
	Student** classRosterArray;

	//Roster Empty Constructor
	Roster();

	//Roster Full Constructor
	Roster(int volume);

//Roster Setter Methods
	void parseDataAndAdd(string dataConstruct);
	DegreeProgram convert(string abc);
	void add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void printAll();
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	//Roster Deconstructor
	~Roster();
};
