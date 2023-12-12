#include <iostream>
#include <string>

#include "input.h"
#include "formatting.h"
#include "datatypes.h"
#include "database.h"

using namespace std;


vector<Info> selectionSortInfoByGroupId(vector<Info> data) {
	int smallest_id;
	for (int i = 0; i < data.size(); i++) {
		smallest_id = i;
		for (int j = i + 1; j < data.size(); j++) {
			if (data[j].group_id < data[smallest_id].group_id) {
				smallest_id = j;
			}
		}
		auto tmp = data[i];
		data[i] = data[smallest_id];
		data[smallest_id] = tmp;
	}
	return data;
}


vector<Info> bubleSortInfoByLecturelId(vector<Info> data) {
	for (int i = 0; i < data.size(); i++) {
		for (int j = i + 1; j < data.size(); j++) {
			if (data[i].lecturel_id > data[j].lecturel_id) {
				auto tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
		}
	}
	return data;
}


vector<Lecturel> bubleSortLecturelByFirstName(vector<Lecturel> data) {
	for (int i = 0; i < data.size(); i++) {
		for (int j = i + 1; j < data.size(); j++) {
			if (data[i].first_name > data[j].first_name) {
				auto tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
		}
	}
	return data;
}


int interpreterSearchInfoById(vector<Info> data, int find_id) {
	int x = 0;
	int a = 0;
	int b = data.size() - 1;
	bool found = false;
	
	while  ((data[a].id < find_id) && (data[b].id > find_id) && !found) {
		x = a + ((find_id - data[a].id) * (b - a)) / (data[b].id - data[a].id);
		if (data[x].id < find_id) {
			a = x + 1;
		}
		else if (data[x].id > find_id) {
			b = x - 1;
		}
		else {
			found = true;
		}
	}

	if (data[a].id == find_id) return a;
	if (data[b].id == find_id) return b;
	if (data[x].id == find_id) return x;
	return -1;
}


int binarySearchLecturelByFirstName(vector<Lecturel> data, string find_name) {
	int midd = 0;
	int left = 0;
	int right = data.size() - 1;
	while (true)
	{
		midd = (left + right) / 2;

		if (find_name < data[midd].first_name)
			right = midd - 1;      
		else if (find_name > data[midd].first_name)  
			left = midd + 1;	   
		else                     
			return midd;           

		if (left > right)        
			return -1;
	}
}


void sortInfoByGroupId(Database& db) {
	cout << separateSubsection("����������:������:������:ID") << endl;
	vector<Info> data = db.getAllInfo();
	vector<Info> sorted_data = selectionSortInfoByGroupId(data);
	for (Info info : sorted_data) {
		cout << separateBlock("����������:������:������:", info.id) << endl
			<< info << endl;
	}
}


void sortInfoByLecturelId(Database& db) {
	cout << separateSubsection("����������:������:�������:ID") << endl;
	vector<Info> data = db.getAllInfo();
	vector<Info> sorted_data = bubleSortInfoByLecturelId(data);
	for (Info info : sorted_data) {
		cout << separateBlock("����������:������:�������:", info.id) << endl
			<< info << endl;
	}
}


void filterLecturelsByLastName(Database& db) {
	cout << separateSubsection("����������:�������:�������") << endl;
	string substr = inputString("������� ��������� ��� ������: ");
	bool found = false;
	vector<Lecturel> data = db.getAllLecturels();
	for (Lecturel lecturel : data) {
		string last_name = lecturel.last_name;
		if (last_name.find(substr) != string::npos) {
			cout << separateBlock("����������:�������:�������:", lecturel.id) << endl
				<< lecturel << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "������ �� �������" << endl;
	}
}


void searchInfoById(Database& db) {
	cout << separateSubsection("�����:������:ID") << endl;
	vector<Info> data = db.getAllInfo();
	while (true) {
		cout << separateBlock("�����:������:ID") << endl;
		int find_id = inputInteger("������� ID ������ ��� ������ (-1 ��� ������): ");
		if (find_id == -1) {
			cout << "�����..." << endl;
			break;
		}
		int found_id = interpreterSearchInfoById(data, find_id);
		if (found_id == -1) {
			cout << "�� ������� ������� � ID " << find_id << endl;
		}
		else {
			cout << data[found_id] << endl;
		}
	}
}


void searchLecturelByFirstName(Database& db) {
	cout << separateSubsection("�����:�������:���") << endl;
	vector<Lecturel> data = db.getAllLecturels();
	vector<Lecturel> sorted_data = bubleSortLecturelByFirstName(data);
	while (true) {
		cout << separateBlock("�����:�������:���") << endl;
		string find_name = inputString("������� ��� ������� ��� ������ (- ��� ������): ");
		if (find_name == "-") {
			cout << "�����..." << endl;
			break;
		}
		int found_id = binarySearchLecturelByFirstName(sorted_data, find_name);
		if (found_id == -1) {
			cout << "�� ������� ������� � ������ " << find_name << endl;
		}
		else {
			cout << sorted_data[found_id] << endl;
		}
	}
}


void additionalOptions(Database& db) {
	while (true) {
		int opcode;
		cout << separateSubsection("��������������") << endl
			<< "[0] ����� � ����" << endl
			<< "[1] ���������� ������� �� ID �����" << endl
			<< "[2] ���������� ������� �� ID ��������" << endl
			<< "[3] ���������� �������� �� �������" << endl
			<< "[4] ���������������� ����� ������� �� ID" << endl
			<< "[5] �������� ����� ������� �� �����" << endl
			<< ">>> "; cin >> opcode;
		switch (opcode) {
		case 0:
			return;
		case 1:
			sortInfoByGroupId(db);
			break;
		case 2:
			sortInfoByLecturelId(db);
			break;
		case 3:
			filterLecturelsByLastName(db);
			break;
		case 4:
			searchInfoById(db);
			break;
		case 5:
			searchLecturelByFirstName(db);
			break;
		default:
			cout << "��� �������� � ����� �������" << endl;
			break;
		}
	}
}