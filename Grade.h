#pragma once

#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

class Grade {
private:
	string courseId;
	string id;
	string grade;

public:
	Grade();
	Grade(string courseId, string id, string grade);

	bool operator < (Grade g) const;

	string getCourseId();
	string getId();
	string getGrade();

};
