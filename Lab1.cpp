
#include "Grade.h"
#include "Student.h"

#include<algorithm>
#include<iomanip>

using namespace std;

double convertGrade(vector<Grade> grades, int j) {
	string letterGrade = grades[j].getGrade();
	char c = letterGrade[0];
	double gpa = 0;
	
	switch (c) {
	case 'A': gpa = 4.00; break;
	case 'B': gpa = 3.00; break;
	case 'C': gpa = 2.00; break;
	case 'D': gpa = 1.00; break;
	case 'E': gpa = 0.00; break;
	}

	char d = letterGrade[1];
	//if (c == "+" || c == "-") {
	switch (d){
	case '+': gpa += 0.3;
	case '-': gpa -= 0.3;
	}
	//}
	return gpa;
}

/*
double convertGrade(vector<Grade> grades, int j) {
	
	double gpa;

	if (grades[j].getGrade() == "A") {
		gpa = 4.0;
	}
	else if (grades[j].getGrade() == "A-") {
		gpa = 3.7;
	}
	else if (grades[j].getGrade() == "B+") {
		gpa = 3.4;
	}
	else if (grades[j].getGrade() == "B") {
		gpa = 3.0;
	}
	else if (grades[j].getGrade() == "B-") {
		gpa = 2.7;
	}
	else if (grades[j].getGrade() == "C+") {
		gpa = 2.4;
	}
	else if (grades[j].getGrade() == "C") {
		gpa = 2.0;
	}
	else if (grades[j].getGrade() == "C-") {
		gpa = 1.7;
	}
	else if (grades[j].getGrade() == "D+") {
		gpa = 1.4;
	}
	else if (grades[j].getGrade() == "D") {
		gpa = 1.0;
	}
	else if (grades[j].getGrade() == "D-") {
		gpa = 0.7;
	}
	else if (grades[j].getGrade() == "E") {
		gpa = 0.0;
	}
	return gpa;
}
*/

void gpaCalc(vector<Student>& students, vector<Grade> grades) {

	double gpa;
	double sumGPA;
	int counter;
	double aveGPA;

	if (grades.size() > 0 && students.size() > 0) {
		
		for (int i = 0; i < students.size(); i++) {

			sumGPA = 0;
			counter = 0;

			for (int j = 0; j < grades.size(); j++) {

				if (students[i].getId() == grades[j].getId()) {
					gpa = convertGrade(grades, j);
					counter++;
					//cerr << "GPA" << gpa << endl;

					sumGPA = sumGPA + gpa;
					//cerr << "SUM" << sumGPA << endl;
				}

			}
			if (counter > 0) {
				aveGPA = sumGPA / counter;
				//cerr << "AVE" << aveGPA << endl;

				students[i].setGPA(aveGPA);
			}
		}
	}
}

void outputStudents(vector<Student> students, vector<Grade> grades, vector<string> query){

	ofstream out;
	out.open("output.txt");
	
//Student output
		for (Student s : students) {
			out << s.getName() << endl;
			out << s.getId() << endl;
			out << s.getPhone() << endl;
			out << s.getAddress() << endl;
		}
	out << endl;
//Grade output
		for (auto grades : grades) {
			out << grades.getId() << "\t" << grades.getGrade() << "\t" << grades.getCourseId() << endl;
		}
	out << endl;
//GPA output	
		for (auto query : query) {

			for (auto students : students) {
			
					if (query == students.getId()) {
						out << students.getId() << "\t" << fixed << setprecision(2) << setfill('0') << students.getGPA() << "\t" << students.getName() << endl;
						break;
					}
			}
		}
}

//int main(int argc, char* argv[]){
int main(){

	vector<Student> students;
	vector<Grade> grades;
	vector<string> query;

	string id;
	string name;
	string address;
	string phone;

	string courseId;
	string grade;

//Open and retrieve studenet info
	ifstream in;
	in.open("Student.txt");
	
	while (getline(in, id)) {
		getline(in, name);
		getline(in, address);
		getline(in, phone);

		Student firstStudent(id, name, address, phone);
		students.push_back(firstStudent);
	}

	in.close();

//Sort Students by ID

	sort(students.begin(), students.end());

//Open and retrieve grade info
	
	in.open("Grade.txt");

	while (getline(in, courseId)) {
		getline(in, id);
		getline(in, grade);

		Grade firstGrade(courseId, id, grade);
		grades.push_back(firstGrade);
	}

	in.close();


//Sort Grades by student ID

	sort(grades.begin(), grades.end());

//Calc GPAs
	gpaCalc(students, grades);
	
//Open and retrieve query info
	
	in.open("Query.txt");

	while (getline(in, id)) {
		query.push_back(id);
	}
	in.close();

//Output Grades to File
	
	outputStudents(students, grades, query);

	return 0;
}
