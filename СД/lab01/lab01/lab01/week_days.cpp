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
		return "понедельник";
	case TUESDAY:
		return "вторник";
	case WEDNESDAY:
		return "среда";
	case THURSDAY:
		return "четверг";
	case FRIDAY:
		return "пятница";
	case SATURDAY:
		return "суббота";
	case SUNDAY:
		return "воскресенье";
	default:
		return "неизвестный день";
	}
}


WEEK_DAY input_day() {
	cout << "Введите номер дня недели (1-7):" << endl;
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
			cout << "Неверный номер дня недели. Повторите ввод" << endl;
		}
	}
}


void number_to_day() {
	WEEK_DAY day = input_day();
	cout << "Вы указали " << get_day_name(day) << endl;
}
