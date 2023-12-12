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
		return "ПК включен";
	case OFF:
		return "ПК выключен";
	case SLEEP:
		return "ПК в спящем режиме";
	default:
		return "Ошибка. Неизвестный статус ПК.";
	}
}


PC_STATUS get_pc_status() {
	cout << "Выберите режим работы ПК:" << endl
		<< "[1] Включен" << endl
		<< "[2] Выключен" << endl
		<< "[3] Спящий режим" << endl;
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
			cout << "Неверный режим. Выберите правильный вариант" << endl;;
			break;
		}
	}
}


void set_pc_status() {
	PC_STATUS status = get_pc_status();
	cout << get_pc_message(status) << endl;
}
