#include <Windows.h>
#include <iostream>
#include "List.h"
using namespace std;


const int STRING_SIZE = 25;


struct Student {
	char last_name[STRING_SIZE];
	char first_name[STRING_SIZE];
	char surname[STRING_SIZE];
	char grade[STRING_SIZE];
	float averange_mark;
};


void print(void* data) {
	Student* student = (Student*)data;
	cout << student->last_name << " "
		<< student->first_name << " "
		<< student->surname << " "
		<< "(" << student->grade << ")"
		<< " - " << student->averange_mark
		<< endl;
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Student s1 = { "Турчинович", "Никита", "Александрович", "11Б", 9.3 };
	Student s2 = { "Янукович", "Евгений", "Дмитриевич", "11Б", 9.9 };
	Student s3 = { "Авдей", "Алексей", "Юрьевич", "11А", 8.5 };

	Object list = Create();

	while (true) {
		int opcode;
		cout << "------------------------------" << endl;
		cout << "Выберите действие:" << endl
			<< "[0] Выход" << endl
			<< "[1] Вставка элементов в список" << endl
			<< "[2] Вывод списка" << endl
			<< "[3] Поиск элементов" << endl
			<< "[4] Количество элементов в списке" << endl
			<< "[5] Очистка списка" << endl
			<< ">>> "; cin >> opcode;
		switch (opcode) {
		case 0: {
			cout << "Выход..." << endl;
			exit(0);
		}
		case 1: {
			list.Insert(&s2);
			list.Insert(&s3);
			list.InsertEnd(&s1);
			cout << "Элементы добавлены" << endl;
			break;
		}
		case 2: {
			cout << "Элементы списка:" << endl;
			list.PrintList(print);
			break;
		}
		case 3: {
			Element* el = list.Search(&s1);
			cout << "Найдено: ";
			print(el->Data);
			break;
		}
		case 4: {
			cout << "Количество элементов в списке: " << list.CountList() << endl;
			break;
		}
		case 5: {
			if (list.DeleteList()) {
				cout << "Список очищен" << endl;
			}
			else {
				cout << "Что-то пошло не так..." << endl;
			}
			break;
		}
		default:
			cout << "Нет действия с таким номером" << endl;
		}
	}
	list.DeleteList();
}
