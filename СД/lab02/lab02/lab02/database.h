#pragma once

#include <vector>
#include <string>

#include "datatypes.h"


class Database {
private:

	int last_group_index = 0;
	int last_lecturel_index = 0;
	int last_subject_index = 0;
	int last_info_index = 0;

	std::vector<Group> group_data = {};
	std::vector<Lecturel> lecturel_data = {};
	std::vector<Subject> subject_data = {};
	std::vector<Info> info_data = {};

public:

	Group createGroup(std::string speciality, std::string department, int students);
	Lecturel createLecturel(std::string last_name, std::string first_name, std::string surname, std::string phone);
	Subject createSubject(std::string name, std::string abbreviation);
	Info createInfo(int subject_id, int lecturel_id, int group_id, int class_hours, int lecture_hours, int practice_hours, float hour_cost);

	Group getGroupById(int group_id);
	Lecturel getLecturelById(int lecturel_id);
	Subject getSubjectById(int subject_id);
	Info getInfoById(int info_id);

	void updateGroupById(int group_id, std::string speciality, std::string department, int students);
	void updateLecturelById(int lecturel_id, std::string last_name, std::string first_name, std::string surname, std::string phone);
	void updateSubjectById(int subject_id, std::string name, std::string abbreviation);
	void updateInfoById(int info_id, int subject_id, int lecturel_id, int group_id, int class_hours, int lecture_hours, int practice_hours, float hour_cost);

	std::vector<Info> getInfoByGroupId(int group_id);
	std::vector<Info> getInfoByLecturelId(int lecturel_id);
	std::vector<Info> getInfoBySubjectId(int subject_id);

	std::vector<Group> getAllGroups();
	std::vector<Lecturel> getAllLecturels();
	std::vector<Subject> getAllSubjects();
	std::vector<Info> getAllInfo();

	void deleteGroup(int group_id);
	void deleteLecturel(int lecturel_id);
	void deleteSubject(int subject_id);
	void deleteInfo(int info_id);

	void deleteAllGroups();
	void deleteAllLecturels();
	void deleteAllSubjects();
	void deleteAllInfo();

	void dropDatabase();

	void saveToFile(std::string filename);
	void loadFromFile(std::string filename);
};


class database_exception : public std::exception {
public:
	database_exception() : msg("database exception") {}
	database_exception(const std::string& msg) : msg(msg) {}
	virtual const char* what() const noexcept {
		return msg.c_str();
	}
private:
	std::string msg;
};


class not_found_exception : public database_exception {
public:
	not_found_exception() : database_exception("not found exception") {}
	not_found_exception(const std::string& msg) : database_exception(msg) {}
};


class reference_exception : public database_exception {
public:
	reference_exception() : database_exception("reference exception") {}
	reference_exception(const std::string& msg) : database_exception(msg) {}
};


class file_exception : public database_exception {
public:
	file_exception() : database_exception("file exceptiont") {};
	file_exception(const std::string& msg) : database_exception(msg) {}
};
