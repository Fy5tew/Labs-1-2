#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "datatypes.h"
#include "database.h"

using namespace std;


Group Database::createGroup(string speciality, string department, int students) {
	int id = ++last_group_index;
	auto group = Group(id, speciality, department, students);
	group_data.push_back(group);
	return group;
}


Lecturel Database::createLecturel(string last_name, string first_name, string surname, string phone) {
	int id = ++last_lecturel_index;
	auto lecturel = Lecturel(id, last_name, first_name, surname, phone);
	lecturel_data.push_back(lecturel);
	return lecturel;
}


Subject Database::createSubject(string name, string abbreviation) {
	int id = ++last_subject_index;
	auto subject = Subject(id, name, abbreviation);
	subject_data.push_back(subject);
	return subject;
}


Info Database::createInfo(int subject_id, int lecturel_id, int group_id, int class_hours, int lecture_hours, int practice_hours, float hour_cost) {
	getGroupById(group_id);
	getLecturelById(lecturel_id);
	getSubjectById(subject_id);

	int id = ++last_info_index;
	auto info = Info(id, subject_id, lecturel_id, group_id, class_hours, lecture_hours, practice_hours, hour_cost);
	info_data.push_back(info);
	return info;
}


Group Database::getGroupById(int group_id) {
	for (Group group : group_data) {
		if (group.id == group_id) {
			return group;
		}
	}
	stringstream message;
	message << "В базе нет группы с id " << group_id;
	throw not_found_exception(message.str());
}


Lecturel Database::getLecturelById(int lecturel_id) {
	for (Lecturel lecturel : lecturel_data) {
		if (lecturel.id == lecturel_id) {
			return lecturel;
		}
	}
	stringstream message;
	message << "В базе нет лектора с id " << lecturel_id;
	throw not_found_exception(message.str());
}


Subject Database::getSubjectById(int subject_id) {
	for (Subject subject : subject_data) {
		if (subject.id == subject_id) {
			return subject;
		}
	}
	stringstream message;
	message << "В базе нет предмета с id " << subject_id;
	throw not_found_exception(message.str());
}


Info Database::getInfoById(int info_id) {
	for (Info info : info_data) {
		if (info.id == info_id) {
			return info;
		}
	}
	stringstream message;
	message << "В базе нет записи с id " << info_id;
	throw not_found_exception(message.str());
}


void Database::updateGroupById(int group_id, string speciality, string department, int students) {
	for (int i = 0; i < group_data.size(); i++) {
		if (group_data[i].id == group_id) {
			group_data[i] = Group(group_id, speciality, department, students);
			return;
		}
	}
	stringstream message;
	message << "В базе нет группы с ID " << group_id;
	throw not_found_exception(message.str());
}


void Database::updateLecturelById(int lecturel_id, string last_name, string first_name, string surname, string phone) {
	for (int i = 0; i < lecturel_data.size(); i++) {
		if (lecturel_data[i].id == lecturel_id) {
			lecturel_data[i] = Lecturel(lecturel_id, last_name, first_name, surname, phone);
			return;
		}
	}
	stringstream message;
	message << "В базе нет лектора с ID " << lecturel_id;
	throw not_found_exception(message.str());
}


void Database::updateSubjectById(int subject_id, string name, string abbreviation) {
	for (int i = 0; i < subject_data.size(); i++) {
		if (subject_data[i].id == subject_id) {
			subject_data[i] = Subject(subject_id, name, abbreviation);
			return;
		}
	}
	stringstream message;
	message << "В базе нет предмета с ID " << subject_id;
	throw not_found_exception(message.str());
}


void Database::updateInfoById(int info_id, int subject_id, int lecturel_id, int group_id, int class_hours, int lecture_hours, int practice_hours, float hour_cost) {
	for (int i = 0; i < info_data.size(); i++) {
		if (info_data[i].id == info_id) {
			info_data[i] = Info(info_id, subject_id, lecturel_id, group_id, class_hours, lecture_hours, practice_hours, hour_cost);
			return;
		}
	}
	stringstream message;
	message << "В базе нет записи с ID " << info_id;
	throw not_found_exception(message.str());
}



vector<Info> Database::getInfoByGroupId(int group_id) {
	vector<Info> founded_info = {};
	for (Info info : info_data) {
		if (info.group_id == group_id) {
			founded_info.push_back(info);
		}
	}
	return founded_info;
}


vector<Info> Database::getInfoByLecturelId(int lecturel_id) {
	vector<Info> founded_info = {};
	for (Info info : info_data) {
		if (info.lecturel_id == lecturel_id) {
			founded_info.push_back(info);
		}
	}
	return founded_info;
}


vector<Info> Database::getInfoBySubjectId(int subject_id) {
	vector<Info> founded_info = {};
	for (Info info : info_data) {
		if (info.subject_id == subject_id) {
			founded_info.push_back(info);
		}
	}
	return founded_info;
}


vector<Group> Database::getAllGroups() {
	vector<Group> groups = group_data;
	return groups;
}


vector<Lecturel> Database::getAllLecturels() {
	vector<Lecturel> lecturels = lecturel_data;
	return lecturels;
}


vector<Subject> Database::getAllSubjects() {
	vector<Subject> subjects = subject_data;
	return subjects;
}


vector<Info> Database::getAllInfo() {
	vector<Info> info = info_data;
	return info;
}


void Database::deleteGroup(int group_id) {
	for (int i = 0; i < group_data.size(); i++) {
		if (group_data[i].id == group_id) {
			auto references = getInfoByGroupId(group_id);
			if (references.size() > 0) {
				stringstream message;
				message << "На группу с id " << group_id << " ссылается " << references.size() << " записей";
				throw reference_exception(message.str());
			}
			group_data.erase(group_data.begin() + i);
			return;
		}
	}
	stringstream message;
	message << "В базе нет группы с id " << group_id;
	throw not_found_exception(message.str());
}


void Database::deleteLecturel(int lecturel_id) {
	for (int i = 0; i < lecturel_data.size(); i++) {
		if (lecturel_data[i].id == lecturel_id) {
			auto references = getInfoByLecturelId(lecturel_id);
			if (references.size() > 0) {
				stringstream message;
				message << "На лектора с id " << lecturel_id << " ссылается " << references.size() << " записей";
			}
			lecturel_data.erase(lecturel_data.begin() + i);
			return;
		}
	}
	stringstream message;
	message << "В базе нет лектора с id " << lecturel_id;
	throw not_found_exception(message.str());
}


void Database::deleteSubject(int subject_id) {
	for (int i = 0; i < subject_data.size(); i++) {
		if (subject_data[i].id == subject_id) {
			auto references = getInfoBySubjectId(subject_id);
			if (references.size() > 0) {
				stringstream message;
				message << "На предмет с id " << subject_id << " ссылается " << references.size() << " записей";
				throw reference_exception(message.str());
			}
			subject_data.erase(subject_data.begin() + i);
			return;
		}
	}
	stringstream message;
	message << "В базе нет предмета с id " << subject_id;
	throw not_found_exception(message.str());
}


void Database::deleteInfo(int info_id) {
	for (int i = 0; i < info_data.size(); i++) {
		if (info_data[i].id == info_id) {
			info_data.erase(info_data.begin() + i);
			return;
		}
	}
	stringstream message;
	message << "В базе нет записи с id " << info_id;
	throw not_found_exception(message.str());
}


void Database::deleteAllGroups() {
	if (!info_data.empty()) {
		throw reference_exception("В базе есть записи, ссылающиеся на группы");
	}
	group_data.clear();
	last_group_index = 0;
}


void Database::deleteAllLecturels() {
	if (!info_data.empty()) {
		throw reference_exception("В базе есть записи, ссылающиеся на лекторов");
	}
	lecturel_data.clear();
	last_lecturel_index = 0;
}


void Database::deleteAllSubjects() {
	if (!info_data.empty()) {
		throw reference_exception("В базе есть записи, ссылающиеся на группы");
	}
	subject_data.clear();
	last_subject_index = 0;
}


void Database::deleteAllInfo() {
	info_data.clear();
	last_info_index = 0;
}


void Database::dropDatabase() {
	deleteAllInfo();
	deleteAllGroups();
	deleteAllLecturels();
	deleteAllSubjects();
}


void Database::saveToFile(string filename) {
	ofstream fout(filename, ios::binary);
	if (fout.fail()) {
		throw file_exception("Не удалось открыть файл");
	}

	int group_data_size = group_data.size();
	int lecturel_data_size = lecturel_data.size();
	int subject_data_size = subject_data.size();
	int info_data_size = info_data.size();

	fout.write((char*)&last_group_index, sizeof(last_group_index));
	fout.write((char*)&group_data_size, sizeof(group_data_size));
	fout.write((char*)&last_lecturel_index, sizeof(last_lecturel_index));
	fout.write((char*)&lecturel_data_size, sizeof(lecturel_data_size));
	fout.write((char*)&last_subject_index, sizeof(last_subject_index));
	fout.write((char*)&subject_data_size, sizeof(subject_data_size));
	fout.write((char*)&last_info_index, sizeof(last_info_index));
	fout.write((char*)&info_data_size, sizeof(info_data_size));
	for (Group group : group_data) {
		fout.write((char*)&group, sizeof(group));
	}
	for (Lecturel lecturel : lecturel_data) {
		fout.write((char*)&lecturel, sizeof(lecturel));
	}
	for (Subject subject : subject_data) {
		fout.write((char*)&subject, sizeof(subject));
	}
	for (Info info : info_data) {
		fout.write((char*)&info, sizeof(info));
	}

	fout.close();
}


void Database::loadFromFile(string filename) {
	ifstream fin(filename, ios::binary);
	if (fin.fail()) {
		throw file_exception("Не удалось открыть файл");
	}

	group_data.clear();
	lecturel_data.clear();
	subject_data.clear();
	info_data.clear();
	auto group = Group(0, "", "", 0);
	auto lecturel = Lecturel(0, "", "", "", "");
	auto subject = Subject(0, "", "");
	auto info = Info(0, 0, 0, 0, 0, 0, 0, 0);
	int group_data_size, lecturel_data_size, subject_data_size, info_data_size;

	fin.read((char*)&this->last_group_index, sizeof(this->last_group_index));
	fin.read((char*)&group_data_size, sizeof(group_data_size));
	fin.read((char*)&this->last_lecturel_index, sizeof(this->last_lecturel_index));
	fin.read((char*)&lecturel_data_size, sizeof(lecturel_data_size));
	fin.read((char*)&this->last_subject_index, sizeof(this->last_subject_index));
	fin.read((char*)&subject_data_size, sizeof(subject_data_size));
	fin.read((char*)&this->last_info_index, sizeof(this->last_info_index));
	fin.read((char*)&info_data_size, sizeof(info_data_size));
	for (int i = 0; i < group_data_size; i++) {
		fin.read((char*)&group, sizeof(group));
		group_data.push_back(group);
	}
	for (int i = 0; i < lecturel_data_size; i++) {
		fin.read((char*)&lecturel, sizeof(lecturel));
		lecturel_data.push_back(lecturel);
	}
	for (int i = 0; i < subject_data_size; i++) {
		fin.read((char*)&subject, sizeof(subject));
		subject_data.push_back(subject);
	}
	for (int i = 0; i < info_data_size; i++) {
		fin.read((char*)&info, sizeof(info));
		info_data.push_back(info);
	}

	fin.close();
}
