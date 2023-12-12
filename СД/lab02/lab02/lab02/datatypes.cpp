#include <string>
#include <sstream>

#include "datatypes.h"

using namespace std;


Group::Group(int id, string speciality, string department, int students) {
	this->id = id;
	strcpy_s(this->speciality, speciality.c_str());
	strcpy_s(this->department, department.c_str());
	this->students = students;
}


string Group::toString() {
	stringstream buf;
	buf << "ID: " << id << endl
		<< "�������������: " << speciality << endl
		<< "�������: " << department << endl
		<< "���������: " << students;
	return buf.str();
}


Lecturel::Lecturel(int id, string last_name, string first_name, string surname, string phone) {
	this->id = id;
	strcpy_s(this->last_name, last_name.c_str());
	strcpy_s(this->first_name, first_name.c_str());
	strcpy_s(this->surname, surname.c_str());
	strcpy_s(this->phone, phone.c_str());
}


string Lecturel::toString() {
	stringstream buf;
	buf << "ID: " << id << endl
		<< "���: " << last_name << " " << first_name << " " << surname << endl
		<< "�������: " << phone;
	return buf.str();
}


Subject::Subject(int id, string name, string abbreviation) {
	this->id = id;
	strcpy_s(this->name, name.c_str());
	strcpy_s(this->abbreviation, abbreviation.c_str());
}


string Subject::toString() {
	stringstream buf;
	buf << "ID: " << id << endl
		<< "��������: " << name << endl
		<< "������������: " << abbreviation;
	return buf.str();
}


Info::Info(int id, int subject_id, int lecturel_id, int group_id, int class_hours, int lecture_hours, int practice_hours, float hour_cost) {
	this->id = id;
	this->subject_id = subject_id;
	this->lecturel_id = lecturel_id;
	this->group_id = group_id;
	this->class_hours = class_hours;
	this->lecture_hours = lecture_hours;
	this->practice_hours = practice_hours;
	this->hour_cost = hour_cost;
}


string Info::toString() {
	stringstream buf;
	buf << "ID: " << id << endl
		<< "ID ��������: " << subject_id << endl
		<< "ID �������: " << lecturel_id << endl
		<< "ID ������: " << group_id << endl
		<< "���� �������: " << practice_hours << endl
		<< "���� ������: " << lecture_hours << endl
		<< "���� ��������: " << practice_hours << endl
		<< "��������� ����: " << hour_cost;
	return buf.str();
}
