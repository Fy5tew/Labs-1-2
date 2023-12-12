#include <iostream>
#include <vector>
#include <string>

#include "formatting.h"
#include "input.h"
#include "datatypes.h"
#include "database.h"

using namespace std;


const string DEFAULT_DATABASE_FILE = "data.bin";


void exitProgram() {
	separateSection("�����");
	cout << "����� �� ���������..." << endl;
	exit(0);
}


void inputGroupData(Database& db) {
	cout << separateSubsection("����:������") << endl;
	int input_count = inputInteger("������� ���������� ����� ��� ����� (0 ��� ������): ");
	if (input_count <= 0) {
		cout << "������ ��������..." << endl;
		return;
	}
	for (int i = 1; i <= input_count; i++) {
		cout << separateBlock("����:������:", i) << endl;
		Group group = inputGroup(db);
		cout << "[��������� � ID " << group.id << ']' << endl;
	}
}

void inputLecturelData(Database& db) {
	cout << separateSubsection("����:�������") << endl;
	int input_count = inputInteger("������� ���������� �������� ��� ����� (0 ��� ������): ");
	if (input_count <= 0) {
		cout << "������ ��������..." << endl;
		return;
	}
	for (int i = 1; i <= input_count; i++) {
		cout << separateBlock("����:�������:", i) << endl;
		Lecturel lecturel = inputLecturel(db);
		cout << "[��������� � ID " << lecturel.id << ']' << endl;
	}
}

void inputSubjectData(Database& db) {
	cout << separateSubsection("����:��������") << endl;
	int input_count = inputInteger("������� ���������� ��������� ��� ����� (0 ��� ������): ");
	if (input_count <= 0) {
		cout << "������ ��������..." << endl;
		return;
	}
	for (int i = 1; i <= input_count; i++) {
		cout << separateBlock("����:��������:", i) << endl;
		Subject subject = inputSubject(db);
		cout << "[��������� � ID " << subject.id << ']' << endl;
	}
}

void inputInfoData(Database& db) {
	cout << separateSubsection("����:������") << endl;
	int input_count = inputInteger("������� ���������� ������� ��� ����� (0 ��� ������): ");
	if (input_count <= 0) {
		cout << "������ ��������..." << endl;
		return;
	}
	for (int i = 1; i <= input_count; i++) {
		cout << separateBlock("����:������:", i) << endl;
		try {
			Info info = inputInfo(db);
			cout << "[��������� � ID " << info.id << ']' << endl;
		}
		catch (const not_found_exception& e) {
			cout << "[���������� �������� ������: " << e.what() << ']' << endl;
		}
	}
}

void inputData(Database& db) {
	while (true) {
		int opcode;
		cout << separateSection("���� ������") << endl
			<< "�������� ��������:" << endl
			<< "[0] ����� � ����" << endl
			<< "[1] ���� �����" << endl
			<< "[2] ���� ��������" << endl
			<< "[3] ���� ���������" << endl
			<< "[4] ���� �������" << endl
			<< ">>> "; cin >> opcode;
		switch (opcode) {
		case 0:
			return;
		case 1:
			inputGroupData(db);
			break;
		case 2:
			inputLecturelData(db);
			break;
		case 3:
			inputSubjectData(db);
			break;
		case 4:
			inputInfoData(db);
			break;
		default:
			cout << "��� �������� � ����� �������" << endl;
			break;
		}
	}
}


void outputGroupData(Database& db) {
	cout << separateSubsection("�����:������") << endl;
	vector<Group> groups = db.getAllGroups();
	if (groups.size() == 0) {
		cout << "� ���� ��� ����������� �����" << endl;
		return;
	}
	for (int i = 0; i < groups.size(); i++) {
		cout << separateBlock("�����:������:", i + 1) << endl
			<< groups[i] << endl;
	}
}

void outputLecturelData(Database& db) {
	cout << separateSubsection("�����:�������") << endl;
	vector<Lecturel> lecturels = db.getAllLecturels();
	if (lecturels.size() == 0) {
		cout << "� ���� ��� ����������� ��������" << endl;
		return;
	}
	for (int i = 0; i < lecturels.size(); i++) {
		cout << separateBlock("�����:�������:", i + 1) << endl
			<< lecturels[i] << endl;
	}
}

void outputSubjectData(Database& db) {
	cout << separateSubsection("�����:��������") << endl;
	vector<Subject> subjects = db.getAllSubjects();
	if (subjects.size() == 0) {
		cout << "� ���� ��� ����������� ���������" << endl;
		return;
	}
	for (int i = 0; i < subjects.size(); i++) {
		cout << separateBlock("�����:��������:", i + 1) << endl
			<< subjects[i] << endl;
	}
}

void outputInfoData(Database& db) {
	cout << separateSubsection("�����:������") << endl;
	vector<Info> info = db.getAllInfo();
	if (info.size() == 0) {
		cout << "� ���� ��� ����������� �������" << endl;
		return;
	}
	for (int i = 0; i < info.size(); i++) {
		cout << separateBlock("�����:������:", i + 1) << endl
			<< info[i] << endl;
	}
}

void outputData(Database& db) {
	while (true) {
		int opcode;
		cout << separateSection("����� ������") << endl
			<< "�������� ��������:" << endl
			<< "[0] ����� � ����" << endl
			<< "[1] ����� �����" << endl
			<< "[2] ����� ��������" << endl
			<< "[3] ����� ���������" << endl
			<< "[4] ����� �������" << endl
			<< ">>> "; cin >> opcode;
		switch (opcode) {
		case 0:
			return;
		case 1:
			outputGroupData(db);
			break;
		case 2:
			outputLecturelData(db);
			break;
		case 3:
			outputSubjectData(db);
			break;
		case 4:
			outputInfoData(db);
			break;
		default:
			cout << "��� �������� � ����� �������" << endl;
			break;
		}
	}
}


void searchGroupData(Database& db) {
	cout << separateSubsection("�����:������") << endl;
	while (true) {
		cout << separateBlock("�����:������") << endl;
		int search_id = inputInteger("������� ID ������ ��� ������ (0 ��� ������): ");
		if (search_id == 0) {
			cout << "�����..." << endl;
			break;
		}
		try {
			Group group = db.getGroupById(search_id);
			cout << group << endl;
		}
		catch (const not_found_exception& e) {
			cout << "������: " << e.what() << endl;
		}
	}
}

void searchLecturelData(Database& db) {
	cout << separateSubsection("�����:�������") << endl;
	while (true) {
		cout << separateBlock("�����:�������") << endl;
		int search_id = inputInteger("������� ID ������� ��� ������ (0 ��� ������): ");
		if (search_id == 0) {
			cout << "�����..." << endl;
			break;
		}
		try {
			Lecturel lecturel = db.getLecturelById(search_id);
			cout << lecturel << endl;
		}
		catch (const not_found_exception& e) {
			cout << "������: " << e.what() << endl;
		}
	}
}

void searchSubjectData(Database& db) {
	cout << separateSubsection("�����:��������") << endl;
	while (true) {
		cout << separateBlock("�����:��������") << endl;
		int search_id = inputInteger("������� ID �������� ��� ������ (0 ��� ������): ");
		if (search_id == 0) {
			cout << "�����..." << endl;
			break;
		}
		try {
			Subject subject = db.getSubjectById(search_id);
			cout << subject << endl;
		}
		catch (const not_found_exception& e) {
			cout << "������: " << e.what() << endl;
		}
	}
}

void searchInfoData(Database& db) {
	cout << separateSubsection("�����:������") << endl;
	while (true) {
		cout << separateBlock("�����:������") << endl;
		int search_id = inputInteger("������� ID ������ ��� ������ (0 ��� ������): ");
		if (search_id == 0) {
			cout << "�����..." << endl;
			break;
		}
		try {
			Info info = db.getInfoById(search_id);
			cout << info << endl;
		}
		catch (const not_found_exception& e) {
			cout << "������: " << e.what() << endl;
		}
	}
}

void searchData(Database& db) {
	while (true) {
		int opcode;
		cout << separateSection("����� ������") << endl
			<< "�������� ��������:" << endl
			<< "[0] ����� � ����" << endl
			<< "[1] ����� �����" << endl
			<< "[2] ����� ��������" << endl
			<< "[3] ����� ���������" << endl
			<< "[4] ����� �������" << endl
			<< ">>> "; cin >> opcode;
		switch (opcode) {
		case 0:
			return;
		case 1:
			searchGroupData(db);
			break;
		case 2:
			searchLecturelData(db);
			break;
		case 3:
			searchSubjectData(db);
			break;
		case 4:
			searchInfoData(db);
			break;
		default:
			cout << "��� �������� � ����� �������" << endl;
			break;
		}
	}
}


void updateGroupData(Database& db) {
	cout << separateSubsection("����������:������") << endl;
	while (true) {
		cout << separateBlock("���������:������") << endl;
		int update_id = inputInteger("������� ID ������ ��� ���������� (0 ��� ������): ");
		if (update_id == 0) {
			cout << "�����..." << endl;
			break;
		}
		try {
			db.getGroupById(update_id);
			updateGroup(db, update_id);
		}
		catch (const not_found_exception& e) {
			cout << "������: " << e.what() << endl;
		}
	}
}

void updateLecturelData(Database& db) {
	cout << separateSubsection("����������:�������") << endl;
	while (true) {
		cout << separateBlock("���������:�������") << endl;
		int update_id = inputInteger("������� ID ������� ��� ���������� (0 ��� ������): ");
		if (update_id == 0) {
			cout << "�����..." << endl;
			break;
		}
		try {
			db.getLecturelById(update_id);
			updateLecturel(db, update_id);
		}
		catch (const not_found_exception& e) {
			cout << "������: " << e.what() << endl;
		}
	}
}

void updateSubjectData(Database& db) {
	cout << separateSubsection("����������:��������") << endl;
	while (true) {
		cout << separateBlock("���������:��������") << endl;
		int update_id = inputInteger("������� ID �������� ��� ���������� (0 ��� ������): ");
		if (update_id == 0) {
			cout << "�����..." << endl;
			break;
		}
		try {
			db.getSubjectById(update_id);
			updateSubject(db, update_id);
		}
		catch (const not_found_exception& e) {
			cout << "������: " << e.what() << endl;
		}
	}
}

void updateInfoData(Database& db) {
	cout << separateSubsection("����������:������") << endl;
	while (true) {
		cout << separateBlock("���������:������") << endl;
		int update_id = inputInteger("������� ID ������ ��� ���������� (0 ��� ������): ");
		if (update_id == 0) {
			cout << "�����..." << endl;
			break;
		}
		try {
			db.getInfoById(update_id);
			updateInfo(db, update_id);
		}
		catch (const not_found_exception& e) {
			cout << "������: " << e.what() << endl;
		}
	}
}

void updateData(Database& db) {
	while (true) {
		int opcode;
		cout << separateSection("���������� ������") << endl
			<< "�������� ��������:" << endl
			<< "[0] ����� � ����" << endl
			<< "[1] ���������� �����" << endl
			<< "[2] ���������� ��������" << endl
			<< "[3] ���������� ���������" << endl
			<< "[4] ���������� �������" << endl
			<< ">>> "; cin >> opcode;
		switch (opcode) {
		case 0:
			return;
		case 1:
			updateGroupData(db);
			break;
		case 2:
			updateLecturelData(db);
			break;
		case 3:
			updateSubjectData(db);
			break;
		case 4:
			updateInfoData(db);
			break;
		default:
			cout << "��� �������� � ����� �������" << endl;
			break;
		}
	}
}


void deleteGroupData(Database& db) {
	cout << separateSubsection("��������:������") << endl;
	while (true) {
		cout << separateBlock("��������:������") << endl;
		int delete_id = inputInteger("������� ID ������ ��� �������� (0 ��� ������, -1 ��� �������� ���� �����): ");
		if (delete_id == 0) {
			cout << "�����..." << endl;
			break;
		}
		if (delete_id == -1) {
			try {
				db.deleteAllGroups();
				cout << "������ ����� ������" << endl;
				break;
			}
			catch (const reference_exception& e) {
				cout << "���������� �������� ������ �����: " << e.what() << endl;
				continue;
			}
		}
		try {
			db.deleteGroup(delete_id);
			cout << "������ � ID " << delete_id << " �������" << endl;
		}
		catch (const database_exception& e) {
			cout << "������ ��������: " << e.what() << endl;
		}
	}
}

void deleteLecturelData(Database& db) {
	cout << separateSubsection("��������:�������") << endl;
	while (true) {
		cout << separateBlock("��������:�������") << endl;
		int delete_id = inputInteger("������� ID ������� ��� �������� (0 ��� ������, -1 ��� �������� ���� ��������): ");
		if (delete_id == 0) {
			cout << "�����..." << endl;
			break;
		}
		if (delete_id == -1) {
			try {
				db.deleteAllLecturels();
				cout << "������ �������� ������" << endl;
				break;
			}
			catch (const reference_exception& e) {
				cout << "���������� �������� ������ ��������: " << e.what() << endl;
				continue;
			}
		}
		try {
			db.deleteLecturel(delete_id);
			cout << "������ � ID " << delete_id << " ������" << endl;
		}
		catch (const database_exception& e) {
			cout << "������ ��������: " << e.what() << endl;
		}
	}
}

void deleteSubjectData(Database& db) {
	cout << separateSubsection("��������:��������") << endl;
	while (true) {
		cout << separateBlock("��������:��������") << endl;
		int delete_id = inputInteger("������� ID �������� ��� �������� (0 ��� ������, -1 ��� �������� ���� ���������): ");
		if (delete_id == 0) {
			cout << "�����..." << endl;
			break;
		}
		if (delete_id == -1) {
			try {
				db.deleteAllSubjects();
				cout << "������ ��������� ������" << endl;
				break;
			}
			catch (const reference_exception& e) {
				cout << "���������� �������� ������ ���������: " << e.what() << endl;
				continue;
			}
		}
		try {
			db.deleteSubject(delete_id);
			cout << "������� � ID " << delete_id << " ������" << endl;
		}
		catch (const database_exception& e) {
			cout << "������ ��������: " << e.what() << endl;
		}
	}
}

void deleteInfoData(Database& db) {
	cout << separateSubsection("��������:������") << endl;
	while (true) {
		cout << separateBlock("��������:������") << endl;
		int delete_id = inputInteger("������� ID ������ ��� �������� (0 ��� ������, -1 ��� �������� ���� �������): ");
		if (delete_id == 0) {
			cout << "�����..." << endl;
			break;
		}
		if (delete_id == -1) {
			db.deleteAllSubjects();
			cout << "������ ������� ������" << endl;
			break;
		}
		try {
			db.deleteSubject(delete_id);
			cout << "������ � ID " << delete_id << " �������" << endl;
		}
		catch (const not_found_exception& e) {
			cout << "������ ��������: " << e.what() << endl;
		}
	}
}

void deleteAllData(Database& db) {
	cout << separateSubsection("��������:�������") << endl;
	string confirm = inputString("��� ������ ����� ������� [y/n]: ");
	if (confirm != "y") {
		cout << "�������� ������ ��������" << endl;
		return;
	}
	db.dropDatabase();
	cout << "��� ������ �������" << endl;
}

void deleteData(Database& db) {
	while (true) {
		int opcode;
		cout << separateSection("�������� ������") << endl
			<< "�������� ��������:" << endl
			<< "[-1] �������� ��� ������" << endl
			<< "[0] ����� � ����" << endl
			<< "[1] �������� �����" << endl
			<< "[2] �������� ��������" << endl
			<< "[3] �������� ���������" << endl
			<< "[4] �������� �������" << endl
			<< ">>> "; cin >> opcode;
		switch (opcode) {
		case -1:
			deleteAllData(db);
			break;
		case 0:
			return;
		case 1:
			deleteGroupData(db);
			break;
		case 2:
			deleteLecturelData(db);
			break;
		case 3:
			deleteSubjectData(db);
			break;
		case 4:
			deleteInfoData(db);
			break;
		default:
			cout << "��� �������� � ����� �������" << endl;
			break;
		}
	}
}


void loadData(Database& db) {
	cout << separateSection("�������� ������") << endl;
	string filename = inputString("������� �������� ����� (- ��� ������������� ����� �� ���������): ");
	if (filename == "-") {
		filename = DEFAULT_DATABASE_FILE;
		cout << "������������ ���� �� ���������" << endl;
	}
	string confirm = inputString("������� ������ ����� ���������� ���������� ����� [y/n]: ");
	if (confirm != "y") {
		cout << "�������� ������ �� ����� ��������" << endl;
		return;
	}
	try {
		db.loadFromFile(filename);
		cout << "������ ��������� �� ����� " << filename << endl;
	}
	catch (const file_exception& e) {
		cout << "�� ������� ��������� ������: " << e.what() << endl;
	}
}


void saveData(Database& db) {
	cout << separateSection("���������� ������") << endl;
	string filename = inputString("������� �������� ����� (- ��� ������������� ����� �� ���������): ");
	if (filename == "-") {
		filename = DEFAULT_DATABASE_FILE;
		cout << "������������ ���� �� ���������" << endl;
	}
	string confirm = inputString("������ ����� ����� ���������� [y/n]: ");
	if (confirm != "y") {
		cout << "������ ������ � ���� ��������" << endl;
		return;
	}
	try {
		db.saveToFile(filename);
		cout << "������ ��������� � ���� " << filename << endl;
	}
	catch (const file_exception& e) {
		cout << "�� ������� ��������� ������: " << e.what() << endl;
	}
}
