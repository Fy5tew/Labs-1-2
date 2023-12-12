#pragma once

#include <string>

#define SHORT_STRING_SIZE 15
#define LONG_STRING_SIZE 30



struct Group {
	int id;
	char speciality[LONG_STRING_SIZE];
	char department[LONG_STRING_SIZE];
	int students;

	Group(int id, std::string speciality, std::string department, int strudents);
	std::string toString();
};


struct Lecturel {
	int id;
	char last_name[LONG_STRING_SIZE];
	char first_name[LONG_STRING_SIZE];
	char surname[LONG_STRING_SIZE];
	char phone[SHORT_STRING_SIZE];

	Lecturel(int id, std::string last_name, std::string first_name, std::string surname, std::string phone);
	std::string toString();
};


struct Subject {
	int id;
	char name[LONG_STRING_SIZE];
	char abbreviation[SHORT_STRING_SIZE];

	Subject(int id, std::string name, std::string abbreviation);
	std::string toString();
};


struct Info {
	int id;
	int subject_id;
	int lecturel_id;
	int group_id;
	int class_hours;
	int lecture_hours;
	int practice_hours;
	float hour_cost;

	Info(int id, int subject_id, int lecturel_id, int group_id, int class_hours, int lecture_hours, int practice_hours, float hour_cost);
	std::string toString();
};
