//roster.cpp file
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <regex>

using namespace std;

#include "degree.h"
#include "student.h"
#include "roster.h"

//Mutator
void roster::add(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3,
	degreeProgramEnum degreeprogram) {

	vector<int> addDaysInCourse{ daysInCourse1, daysInCourse2, daysInCourse3 };
	student* addStudent = new student(studentID, firstName, lastName, emailAddress, age, addDaysInCourse, degreeprogram);
	classRosterArray.push_back(addStudent);
}

void roster::remove(string studentID) {
	bool foundItem = false;
	cout << "--Attempting to delete student ID: " << RED << studentID << RESET << " from list--" << endl;
	for (size_t i = 0; i < classRosterArray.size(); i++)
	{
		if (studentID == classRosterArray.at(i)->getStudentID()) {
			cout << "  Successfully Removed student " << RED << studentID << RESET << "." << endl << endl;
			delete classRosterArray.at(i);
			classRosterArray.erase(classRosterArray.begin() + i);
			foundItem = true;
		}
	}
	if (!foundItem) {
		cout << "  No students found with that ID" << endl << endl;
	}
}

//print()
void roster::printAverageDaysInCourse(string studentID) {
	bool foundItem = false;
	float avgDaysResult = 0.00;
	cout << "The average days in course for student " << RED << studentID << RESET << " is: ";
	for (size_t i = 0; i < classRosterArray.size(); i++) {
		if (studentID == classRosterArray.at(i)->getStudentID()) {
			vector<int> avgDaysVec = classRosterArray.at(i)->getdaysToComplete();
			for (size_t i = 0; i < avgDaysVec.size(); i++) {
				avgDaysResult = avgDaysResult + avgDaysVec.at(i);
			}
			cout << setprecision(4) << avgDaysResult / avgDaysVec.size() << endl;
			foundItem = true;
		}
	}
	if (!foundItem) {
		cout << RED << "Error" << RESET << " - No students found with that ID" << endl << endl;
	}
}

void roster::printAll() const {
	cout << "------------PRINTING STUDENT LIST------------" << endl << endl;
	for (size_t i = 0; i < classRosterArray.size(); i++)
	{
		classRosterArray.at(i)->print(printItemEnum::ALL);
	}
	cout << endl;
}

void roster::printByDegreeProgram(degreeProgramEnum degreeProgram) {
	bool foundItem = false;
	cout << "-------PRINTING ALL STUDENTS IN " << RED << degreeProgramStrings[(int)degreeProgram] << RESET << "-------- " << endl << endl;
	for (size_t i = 0; i < classRosterArray.size(); i++) {
		if (degreeProgram == classRosterArray.at(i)->getDegreeProgram()) {
			classRosterArray.at(i)->print(printItemEnum::ALL);
		}
		foundItem = true;
	}
	if (!foundItem) {
		cout << RED << "Error" << RESET << " - No students found in that program" << endl;
	}
	cout << endl;
}

void roster::printInvalidEmails() {
	bool foundItem = false;
	cout << "------------PRINTING INVALID EMAILS------------" << endl << endl;
	for (size_t i = 0; i < classRosterArray.size(); i++) {
		const regex emailPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		if (!regex_match(classRosterArray.at(i)->getEmailAddress(), emailPattern)) {
			cout << "Invalid Email Address found for Student ID: " << RED << classRosterArray.at(i)->getStudentID() << RESET;
			cout << "<--" << RED << classRosterArray.at(i)->getEmailAddress() << RESET << endl;
			foundItem = true;
		}
	}
	if (!foundItem) {
		cout << "No invalid email addresses found" << endl;
	}
	cout << endl;
}

//Contructor 
roster::roster() {
	return;
}

//Copy Contructor
roster::roster(const roster& origRoster) {
	cout << GREEN << "Backend Info: copy contructor called" << RESET << endl << endl;
	for (size_t i = 0; i < origRoster.classRosterArray.size(); i++) {
		classRosterArray.push_back(new student(*origRoster.classRosterArray.at(i)));
	}
	return;
}

//Destructor
roster::~roster() {
	cout << GREEN << "Backend Info: roster destructor called" << RESET << endl << endl;
	for (size_t i = 0; i < classRosterArray.size(); i++) {
		delete classRosterArray.at(i);
	}
	return;
}
