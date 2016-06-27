
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
        switch (d){
        case '+': gpa += 0.4; break;
        case '-': gpa -= 0.3; break;
        }

        return gpa;
}

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

					sumGPA = sumGPA + gpa;
				}

			}
			if (counter > 0) {
				aveGPA = sumGPA / counter;

				students[i].setGPA(aveGPA);
			}
		}
	}
}

void outputStudents(vector<Student> students, vector<Grade> grades, vector<string> query, char* argv[]) {

	ofstream out;
	out.open(argv[4]);
	
//Student output
                for (Student s : students) {
                        out << s.getName() << endl;
                        out << s.getId() << endl;
                        out << s.getPhone() << endl;
                        out << s.getAddress() << endl;
		}
	out << endl;
//Grade output
                for (Grade g : grades) {
                        out << g.getId() << "\t" << g.getGrade() << "\t" << g.getCourseId() << endl;
		}
	out << endl;
//GPA output	
                for (string q : query) {

                        for (Student s : students) {
			
                                        if (q == s.getId()) {
                                                out << s.getId() << "\t" << fixed << setprecision(2) << setfill('0') << s.getGPA() << "\t" << s.getName() << endl;
						break;
					}
			}
		}
}

int main(int argc, char* argv[]){

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
	in.open(argv[1]);
	
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
	
	in.open(argv[2]);

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
	
	in.open(argv[3]);

	while (getline(in, id)) {
		query.push_back(id);
	}
	in.close();

//Output Grades to File
	
	outputStudents(students, grades, query, argv);

	return 0;
}
