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
			cout << "Введенные данные не являются числом" << endl;
		}
		catch (out_of_range) {
			cout << "Введенное число слишком большое" << endl;
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
			cout << "Введенные данные не являются числом" << endl;
		}
		catch (range_error) {
			cout << "Введенное число слишком большое" << endl;
		}
	}
}


Group inputGroup(Database& db) {
	string speciality = inputString("Специальность: ");
	string department = inputString("Кафедра: ");
	int students = inputInteger("Количество студентов: ");

	return db.createGroup(speciality, department, students);
}


void updateGroup(Database& db, int group_id) {
	string speciality = inputString("Специальность: ");
	string department = inputString("Кафедра: ");
	int students = inputInteger("Количество студентов: ");

	db.updateGroupById(group_id, speciality, department, students);
}


Lecturel inputLecturel(Database& db) {
	string last_name = inputString("Фамилия: ");
	string first_name = inputString("Имя: ");
	string surname = inputString("Отчество: ");
	string phone = inputString("Номер телефона: ");

	return db.createLecturel(last_name, first_name, surname, phone);
}


void updateLecturel(Database& db, int lecturel_id) {
	string last_name = inputString("Фамилия: ");
	string first_name = inputString("Имя: ");
	string surname = inputString("Отчество: ");
	string phone = inputString("Номер телефона: ");

	db.updateLecturelById(lecturel_id, last_name, first_name, surname, phone);
}


Subject inputSubject(Database& db) {
	string name = inputString("Имя: ");
	string abbreviation = inputString("Аббревиатура: ");

	return db.createSubject(name, abbreviation);
}


void updateSubject(Database& db, int subject_id) {
	string name = inputString("Имя: ");
	string abbreviation = inputString("Аббревиатура: ");

	db.updateSubjectById(subject_id, name, abbreviation);
}


Info inputInfo(Database& db) {
	int subject_id = inputInteger("ID Предмета: ");
	int lecturel_id = inputInteger("ID Лектора: ");
	int group_id = inputInteger("ID Группы: ");
	int class_hours = inputInteger("Часы занятий: ");
	int lecture_hours = inputInteger("Часы лекций: ");
	int practice_hours = inputInteger("Часы практики: ");
	float hour_cost = inputFloat("Стоимость часа: ");

	return db.createInfo(subject_id, lecturel_id, group_id, class_hours, lecture_hours, practice_hours, hour_cost);
}


void updateInfo(Database& db, int info_id) {
	int subject_id = inputInteger("ID Предмета: ");
	int lecturel_id = inputInteger("ID Лектора: ");
	int group_id = inputInteger("ID Группы: ");
	int class_hours = inputInteger("Часы занятий: ");
	int lecture_hours = inputInteger("Часы лекций: ");
	int practice_hours = inputInteger("Часы практики: ");
	float hour_cost = inputFloat("Стоимость часа: ");

	db.updateInfoById(info_id, subject_id, lecturel_id, group_id, class_hours, lecture_hours, practice_hours, hour_cost);
}
