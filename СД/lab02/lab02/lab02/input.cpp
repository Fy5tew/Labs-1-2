#include <iostream>
#include <string>

#include "datatypes.h"
#include "database.h"

using namespace std;


string inputString(string placeholder = "") {
	string value;
	cout << placeholder;
	cin >> value;
	return value;
}


int inputInteger(string placeholder = "") {
	while (true) {
		string str_value = inputString(placeholder);
		try {
			int int_value = atoi(str_value.c_str());
			return int_value;
		}
		catch (invalid_argument) {
			cout << "��������� ������ �� �������� ������" << endl;
		}
		catch (out_of_range) {
			cout << "��������� ����� ������� �������" << endl;
		}
	}
}


float inputFloat(string placeholder = "") {
	while (true) {
		string str_value = inputString(placeholder);
		try {
			float float_value = atof(str_value.c_str());
			return float_value;
		}
		catch (invalid_argument) {
			cout << "��������� ������ �� �������� ������" << endl;
		}
		catch (range_error) {
			cout << "��������� ����� ������� �������" << endl;
		}
	}
}


Group inputGroup(Database& db) {
	string speciality = inputString("�������������: ");
	string department = inputString("�������: ");
	int students = inputInteger("���������� ���������: ");

	return db.createGroup(speciality, department, students);
}


void updateGroup(Database& db, int group_id) {
	string speciality = inputString("�������������: ");
	string department = inputString("�������: ");
	int students = inputInteger("���������� ���������: ");

	db.updateGroupById(group_id, speciality, department, students);
}


Lecturel inputLecturel(Database& db) {
	string last_name = inputString("�������: ");
	string first_name = inputString("���: ");
	string surname = inputString("��������: ");
	string phone = inputString("����� ��������: ");

	return db.createLecturel(last_name, first_name, surname, phone);
}


void updateLecturel(Database& db, int lecturel_id) {
	string last_name = inputString("�������: ");
	string first_name = inputString("���: ");
	string surname = inputString("��������: ");
	string phone = inputString("����� ��������: ");

	db.updateLecturelById(lecturel_id, last_name, first_name, surname, phone);
}


Subject inputSubject(Database& db) {
	string name = inputString("���: ");
	string abbreviation = inputString("������������: ");

	return db.createSubject(name, abbreviation);
}


void updateSubject(Database& db, int subject_id) {
	string name = inputString("���: ");
	string abbreviation = inputString("������������: ");

	db.updateSubjectById(subject_id, name, abbreviation);
}


Info inputInfo(Database& db) {
	int subject_id = inputInteger("ID ��������: ");
	int lecturel_id = inputInteger("ID �������: ");
	int group_id = inputInteger("ID ������: ");
	int class_hours = inputInteger("���� �������: ");
	int lecture_hours = inputInteger("���� ������: ");
	int practice_hours = inputInteger("���� ��������: ");
	float hour_cost = inputFloat("��������� ����: ");

	return db.createInfo(subject_id, lecturel_id, group_id, class_hours, lecture_hours, practice_hours, hour_cost);
}


void updateInfo(Database& db, int info_id) {
	int subject_id = inputInteger("ID ��������: ");
	int lecturel_id = inputInteger("ID �������: ");
	int group_id = inputInteger("ID ������: ");
	int class_hours = inputInteger("���� �������: ");
	int lecture_hours = inputInteger("���� ������: ");
	int practice_hours = inputInteger("���� ��������: ");
	float hour_cost = inputFloat("��������� ����: ");

	db.updateInfoById(info_id, subject_id, lecturel_id, group_id, class_hours, lecture_hours, practice_hours, hour_cost);
}
