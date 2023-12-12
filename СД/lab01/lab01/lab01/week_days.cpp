#include <iostream>
using namespace std;


enum WEEK_DAY {
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY,
};


const char* get_day_name(WEEK_DAY day) {
	switch (day)
	{
	case MONDAY:
		return "�����������";
	case TUESDAY:
		return "�������";
	case WEDNESDAY:
		return "�����";
	case THURSDAY:
		return "�������";
	case FRIDAY:
		return "�������";
	case SATURDAY:
		return "�������";
	case SUNDAY:
		return "�����������";
	default:
		return "����������� ����";
	}
}


WEEK_DAY input_day() {
	cout << "������� ����� ��� ������ (1-7):" << endl;
	int user_choice;
	while (true) {
		cout << ">>> "; cin >> user_choice;
		switch (user_choice)
		{
		case 1:
			return MONDAY;
		case 2:
			return TUESDAY;
		case 3:
			return WEDNESDAY;
		case 4:
			return THURSDAY;
		case 5:
			return FRIDAY;
		case 6:
			return SATURDAY;
		case 7:
			return SUNDAY;
		default:
			cout << "�������� ����� ��� ������. ��������� ����" << endl;
		}
	}
}


void number_to_day() {
	WEEK_DAY day = input_day();
	cout << "�� ������� " << get_day_name(day) << endl;
}
