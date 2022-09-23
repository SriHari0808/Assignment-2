
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

struct STUDENT_DATA  //Created a struct STUDENT_DATA that contains the first and last names of the students.
{
	string fname;
	string lname;
};

int main()
{
	ifstream fin;
	vector<STUDENT_DATA> student_vector;
	STUDENT_DATA stud;
	fin.open("StudentData.txt");              //Opening the file
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			string str;
			getline(fin, str);                //Reading the lines from the file

			istringstream ss(str);
			string fname, lname;
			getline(ss, stud.lname, ',');       //Parsing the data
			getline(ss, stud.fname);

			student_vector.push_back(stud);     //Pushing the data to vector
		}
		fin.close();
	}
	else
	{
		cout << "Oops! Cannot open StudentData file" << endl;
	}

#ifdef _DEBUG
	for (int i = 0; i < student_vector.size(); i++)  //Printing the student data only in debug mode
	{
		cout << student_vector[i].fname << " " << student_vector[i].lname << endl;
	}
#endif // DEBUG
	return 0;
}
