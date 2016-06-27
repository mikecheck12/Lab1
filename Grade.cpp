#include "Grade.h"

using namespace std;

Grade::Grade() {}

Grade::Grade(string courseId, string id, string grade) {
	this->courseId = courseId;
	this->id = id;
	this->grade = grade;
}

bool Grade::operator < (Grade g) const {
	return id < g.id ||
		(id == g.id && courseId < g.courseId) ||
		(id == g.id && courseId == g.courseId && grade < g.grade);
}

string Grade::getCourseId() {
	return courseId;
}

string Grade::getId() {
	return id;
}

string Grade::getGrade() {
	return grade;
}