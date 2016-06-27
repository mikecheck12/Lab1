#pragma once

#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

class Student {
private:
	string id;
	string name;
	string address;
	string phone;
	double gpa;

public:
	Student();
	Student(string id, string name, string address, string phone);
	
	bool operator < (Student s2);

	string getName();
	string getId();
	string getAddress();
	string getPhone();
	void setGPA(double gpa);
	double getGPA();


};
