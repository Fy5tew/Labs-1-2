#include <iostream>
using namespace std;


enum PC_STATUS {
	ON,
	OFF,
	SLEEP,
};


const char* get_pc_message(PC_STATUS status) {
	switch (status)
	{
	case ON:
		return "�� �������";
	case OFF:
		return "�� ��������";
	case SLEEP:
		return "�� � ������ ������";
	default:
		return "������. ����������� ������ ��.";
	}
}


PC_STATUS get_pc_status() {
	cout << "�������� ����� ������ ��:" << endl
		<< "[1] �������" << endl
		<< "[2] ��������" << endl
		<< "[3] ������ �����" << endl;
	int user_choice;
	while (true) {
		cout << ">>> "; cin >> user_choice;
		switch (user_choice)
		{
		case 1:
			return ON;
		case 2:
			return OFF;
		case 3:
			return SLEEP;
		default:
			cout << "�������� �����. �������� ���������� �������" << endl;;
			break;
		}
	}
}


void set_pc_status() {
	PC_STATUS status = get_pc_status();
	cout << get_pc_message(status) << endl;
}
