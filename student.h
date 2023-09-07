//student.h File

#pragma once



#define RESET "\033[0m"
#define BOLDBLUE    "\033[1m\033[34m"
#define RED "\033[1;31m"
#define GREEN "\x1B[92m"


enum class printItemEnum { STUDENTID, FIRSTNAME, LASTNAME, EMAIL, AGE, DEGREEPROGRAM, DAYSTOCOMPLETE, ALL };

static const string degreeProgramStrings[] = { "Security", "Network", "Software", "None" };

class student      //D.created class 'student'
{
	private:
		int age;
		degreeProgramEnum degreeProgram;                      
		string studentID, firstName, lastName, email;
		vector<int> daysToComplete;
	
	public:
		//Accessor
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	degreeProgramEnum getDegreeProgram() const;
	vector<int> getdaysToComplete() const;

	//Mutator
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string email);
	void setAge(int age);
	void setDegreeProgram(degreeProgramEnum degreeProgram);
	void setdaysToComplete(vector<int> daysToComplete);

	//Contructor 
	student(
		string StudentID = "NEW",
		string firstName = "NEW",
		string lastName = "NEW",
		string email = "NEW",
		int age = 0,
		vector <int> daysToComplete = { 0, 0, 0, 0 },
		degreeProgramEnum degreeProgram = degreeProgramEnum::NONE);

	//Print
	void print(printItemEnum printItem) const;


	~student();

};




