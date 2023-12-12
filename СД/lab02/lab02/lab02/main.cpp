#include <Windows.h>
#include <iostream>

#include "formatting.h"
#include "options.h"
#include "database.h"

using namespace std;


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Database database;

	while (true) {
		int opcode;
		cout << separateSection("МЕНЮ") << endl
			<< "Выберите действие:" << endl
			<< "[0] Выход из программы" << endl
			<< "[1] Ввод данных" << endl
			<< "[2] Вывод данных" << endl
			<< "[3] Поиск данных" << endl
			<< "[4] Обновление данных" << endl
			<< "[5] Удаление данных" << endl
			<< "[6] Дополнительное" << endl
			<< "[7] Загрузка данных" << endl
			<< "[8] Сохранение данных" << endl
			<< ">>> "; cin >> opcode;

		switch (opcode) {
		case 0:
			exitProgram();
			break;
		case 1:
			inputData(database);
			break;
		case 2:
			outputData(database);
			break;
		case 3:
			searchData(database);
			break;
		case 4:
			updateData(database);
			break;
		case 5:
			deleteData(database);
			break;
		case 6:
			additionalOptions(database);
			break;
		case 7:
			loadData(database);
			break;
		case 8:
			saveData(database);
			break;
		default:
			cout << "Нет действия с таким номером" << endl;
			break;
		}

		cout << endl;
	}
}
