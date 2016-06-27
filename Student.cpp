#include "Student.h"

using namespace std;

Student::Student() {}

Student::Student(string id, string name, string address, string phone){
	this->id = id;
	this->name = name;
	this->address = address;
	this->phone = phone;
	gpa = 0.00;
}

bool Student::operator < (Student s2) {
	return this->id < s2.id;
}

string Student::getName() {
	return name;
}

string Student::getId() {
	return id;
}

string Student::getAddress() {
	return address;
}

string Student::getPhone() {
	return phone;
}

void Student::setGPA(double gpa) {
	this->gpa = gpa;
}

double Student::getGPA() {
	return gpa;
}