#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
#define PRE_RELEASE

struct STUDENT_DATA                 //Created a struct STUDENT_DATA that contains the first and last names of the students.
{
	string fname;
	string lname;

#ifdef PRE_RELEASE
	string email;
#endif
};

int main()
{
#ifdef PRE_RELEASE                                    //checking the application running in standard or pre-release source code
	cout << "PreRelease is running" << endl;
#else
	cout << "Standard version is running" << endl;
#endif // PRE_RELEASE

	ifstream fin;
	vector<STUDENT_DATA> student_vector;
	STUDENT_DATA stud;
	string filename;

#ifdef PRE_RELEASE                                    
	filename = "StudentData_Emails.txt";
#else
	filename = "StudentData.txt";
#endif // PRE_RELEASE

	fin.open(filename);									 //Opening the initilized filename 
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			string str;
			getline(fin, str);                          //Reading the lines from the file

			istringstream ss(str);
			string fname, lname;
			getline(ss, stud.lname, ',');               //Parsing the data
			getline(ss, stud.fname, ',');

#ifdef PRE_RELEASE
			getline(ss, stud.email);
#endif
			student_vector.push_back(stud);             //Pushing the data to vector
		}
		fin.close();
	}
	else
	{
		cout << "Oops! Cannot open " << filename << endl;
	}

#ifdef _DEBUG
	for (int i = 0; i < student_vector.size(); i++)      //Printing the student data only in debug mode
	{
#ifdef PRE_RELEASE
		cout << student_vector[i].fname << " " << student_vector[i].lname << " " << student_vector[i].email << endl;
#else
		cout << student_vector[i].fname << " " << student_vector[i].lname << endl;
#endif
	}
#endif // DEBUG
}
