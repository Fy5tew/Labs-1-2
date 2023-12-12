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
	separateSection("ВЫХОД");
	cout << "Выход из программы..." << endl;
	exit(0);
}


void inputGroupData(Database& db) {
	cout << separateSubsection("ВВОД:ГРУППЫ") << endl;
	int input_count = inputInteger("Введите количество групп для ввода (0 для отмены): ");
	if (input_count <= 0) {
		cout << "Отмена действия..." << endl;
		return;
	}
	for (int i = 1; i <= input_count; i++) {
		cout << separateBlock("ВВОД:ГРУППЫ:", i) << endl;
		Group group = inputGroup(db);
		cout << "[Сохранено с ID " << group.id << ']' << endl;
	}
}

void inputLecturelData(Database& db) {
	cout << separateSubsection("ВВОД:ЛЕКТОРЫ") << endl;
	int input_count = inputInteger("Введите количество лекторов для ввода (0 для отмены): ");
	if (input_count <= 0) {
		cout << "Отмена действия..." << endl;
		return;
	}
	for (int i = 1; i <= input_count; i++) {
		cout << separateBlock("ВВОД:ЛЕКТОРЫ:", i) << endl;
		Lecturel lecturel = inputLecturel(db);
		cout << "[Сохранено с ID " << lecturel.id << ']' << endl;
	}
}

void inputSubjectData(Database& db) {
	cout << separateSubsection("ВВОД:ПРЕДМЕТЫ") << endl;
	int input_count = inputInteger("Введите количество предметов для ввода (0 для отмены): ");
	if (input_count <= 0) {
		cout << "Отмена действия..." << endl;
		return;
	}
	for (int i = 1; i <= input_count; i++) {
		cout << separateBlock("ВВОД:ПРЕДМЕТЫ:", i) << endl;
		Subject subject = inputSubject(db);
		cout << "[Сохранено с ID " << subject.id << ']' << endl;
	}
}

void inputInfoData(Database& db) {
	cout << separateSubsection("ВВОД:ЗАПИСИ") << endl;
	int input_count = inputInteger("Введите количество записей для ввода (0 для отмены): ");
	if (input_count <= 0) {
		cout << "Отмена действия..." << endl;
		return;
	}
	for (int i = 1; i <= input_count; i++) {
		cout << separateBlock("ВВОД:ЗАПИСИ:", i) << endl;
		try {
			Info info = inputInfo(db);
			cout << "[Сохранено с ID " << info.id << ']' << endl;
		}
		catch (const not_found_exception& e) {
			cout << "[Невозможно добавить запись: " << e.what() << ']' << endl;
		}
	}
}

void inputData(Database& db) {
	while (true) {
		int opcode;
		cout << separateSection("ВВОД ДАННЫХ") << endl
			<< "Выберите действие:" << endl
			<< "[0] Выход в меню" << endl
			<< "[1] Ввод групп" << endl
			<< "[2] Ввод лекторов" << endl
			<< "[3] Ввод предметов" << endl
			<< "[4] Ввод записей" << endl
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
			cout << "Нет действия с таким номером" << endl;
			break;
		}
	}
}


void outputGroupData(Database& db) {
	cout << separateSubsection("ВЫВОД:ГРУППЫ") << endl;
	vector<Group> groups = db.getAllGroups();
	if (groups.size() == 0) {
		cout << "В базе нет сохраненных групп" << endl;
		return;
	}
	for (int i = 0; i < groups.size(); i++) {
		cout << separateBlock("ВЫВОД:ГРУППЫ:", i + 1) << endl
			<< groups[i] << endl;
	}
}

void outputLecturelData(Database& db) {
	cout << separateSubsection("ВЫВОД:ЛЕКТОРЫ") << endl;
	vector<Lecturel> lecturels = db.getAllLecturels();
	if (lecturels.size() == 0) {
		cout << "В базе нет сохраненных лекторов" << endl;
		return;
	}
	for (int i = 0; i < lecturels.size(); i++) {
		cout << separateBlock("ВЫВОД:ЛЕКТОРЫ:", i + 1) << endl
			<< lecturels[i] << endl;
	}
}

void outputSubjectData(Database& db) {
	cout << separateSubsection("ВЫВОД:ПРЕДМЕТЫ") << endl;
	vector<Subject> subjects = db.getAllSubjects();
	if (subjects.size() == 0) {
		cout << "В базе нет сохраненных предметов" << endl;
		return;
	}
	for (int i = 0; i < subjects.size(); i++) {
		cout << separateBlock("ВЫВОД:ПРЕДМЕТЫ:", i + 1) << endl
			<< subjects[i] << endl;
	}
}

void outputInfoData(Database& db) {
	cout << separateSubsection("ВЫВОД:ЗАПИСИ") << endl;
	vector<Info> info = db.getAllInfo();
	if (info.size() == 0) {
		cout << "В базе нет сохраненных записей" << endl;
		return;
	}
	for (int i = 0; i < info.size(); i++) {
		cout << separateBlock("ВЫВОД:ЗАПИСИ:", i + 1) << endl
			<< info[i] << endl;
	}
}

void outputData(Database& db) {
	while (true) {
		int opcode;
		cout << separateSection("ВЫВОД ДАННЫХ") << endl
			<< "Выберите действие:" << endl
			<< "[0] Выход в меню" << endl
			<< "[1] Вывод групп" << endl
			<< "[2] Вывод лекторов" << endl
			<< "[3] Вывод предметов" << endl
			<< "[4] Вывод записей" << endl
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
			cout << "Нет действия с таким номером" << endl;
			break;
		}
	}
}


void searchGroupData(Database& db) {
	cout << separateSubsection("ПОИСК:ГРУППЫ") << endl;
	while (true) {
		cout << separateBlock("ПОИСК:ГРУППЫ") << endl;
		int search_id = inputInteger("Введите ID группы для поиска (0 для выхода): ");
		if (search_id == 0) {
			cout << "Выход..." << endl;
			break;
		}
		try {
			Group group = db.getGroupById(search_id);
			cout << group << endl;
		}
		catch (const not_found_exception& e) {
			cout << "Ошибка: " << e.what() << endl;
		}
	}
}

void searchLecturelData(Database& db) {
	cout << separateSubsection("ПОИСК:ЛЕКТОРЫ") << endl;
	while (true) {
		cout << separateBlock("ПОИСК:ЛЕКТОРЫ") << endl;
		int search_id = inputInteger("Введите ID лектора для поиска (0 для выхода): ");
		if (search_id == 0) {
			cout << "Выход..." << endl;
			break;
		}
		try {
			Lecturel lecturel = db.getLecturelById(search_id);
			cout << lecturel << endl;
		}
		catch (const not_found_exception& e) {
			cout << "Ошибка: " << e.what() << endl;
		}
	}
}

void searchSubjectData(Database& db) {
	cout << separateSubsection("ПОИСК:ПРЕДМЕТЫ") << endl;
	while (true) {
		cout << separateBlock("ПОИСК:ПРЕДМЕТЫ") << endl;
		int search_id = inputInteger("Введите ID предмета для поиска (0 для выхода): ");
		if (search_id == 0) {
			cout << "Выход..." << endl;
			break;
		}
		try {
			Subject subject = db.getSubjectById(search_id);
			cout << subject << endl;
		}
		catch (const not_found_exception& e) {
			cout << "Ошибка: " << e.what() << endl;
		}
	}
}

void searchInfoData(Database& db) {
	cout << separateSubsection("ПОИСК:ЗАПИСИ") << endl;
	while (true) {
		cout << separateBlock("ПОИСК:ЗАПИСИ") << endl;
		int search_id = inputInteger("Введите ID записи для поиска (0 для выхода): ");
		if (search_id == 0) {
			cout << "Выход..." << endl;
			break;
		}
		try {
			Info info = db.getInfoById(search_id);
			cout << info << endl;
		}
		catch (const not_found_exception& e) {
			cout << "Ошибка: " << e.what() << endl;
		}
	}
}

void searchData(Database& db) {
	while (true) {
		int opcode;
		cout << separateSection("ПОИСК ДАННЫХ") << endl
			<< "Выберите действие:" << endl
			<< "[0] Выход в меню" << endl
			<< "[1] Поиск групп" << endl
			<< "[2] Поиск лекторов" << endl
			<< "[3] Поиск предметов" << endl
			<< "[4] Поиск записей" << endl
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
			cout << "Нет действия с таким номером" << endl;
			break;
		}
	}
}


void updateGroupData(Database& db) {
	cout << separateSubsection("ОБНОВЛЕНИЕ:ГРУППЫ") << endl;
	while (true) {
		cout << separateBlock("ОБНОВЛНИЕ:ГРУППЫ") << endl;
		int update_id = inputInteger("Введите ID группы для обновления (0 для выхода): ");
		if (update_id == 0) {
			cout << "Выход..." << endl;
			break;
		}
		try {
			db.getGroupById(update_id);
			updateGroup(db, update_id);
		}
		catch (const not_found_exception& e) {
			cout << "Ошибка: " << e.what() << endl;
		}
	}
}

void updateLecturelData(Database& db) {
	cout << separateSubsection("ОБНОВЛЕНИЕ:ЛЕКТОРЫ") << endl;
	while (true) {
		cout << separateBlock("ОБНОВЛНИЕ:ЛЕКТОРЫ") << endl;
		int update_id = inputInteger("Введите ID лектора для обновления (0 для выхода): ");
		if (update_id == 0) {
			cout << "Выход..." << endl;
			break;
		}
		try {
			db.getLecturelById(update_id);
			updateLecturel(db, update_id);
		}
		catch (const not_found_exception& e) {
			cout << "Ошибка: " << e.what() << endl;
		}
	}
}

void updateSubjectData(Database& db) {
	cout << separateSubsection("ОБНОВЛЕНИЕ:ПРЕДМЕТЫ") << endl;
	while (true) {
		cout << separateBlock("ОБНОВЛНИЕ:ПРЕДМЕТЫ") << endl;
		int update_id = inputInteger("Введите ID предмета для обновления (0 для выхода): ");
		if (update_id == 0) {
			cout << "Выход..." << endl;
			break;
		}
		try {
			db.getSubjectById(update_id);
			updateSubject(db, update_id);
		}
		catch (const not_found_exception& e) {
			cout << "Ошибка: " << e.what() << endl;
		}
	}
}

void updateInfoData(Database& db) {
	cout << separateSubsection("ОБНОВЛЕНИЕ:ЗАПИСИ") << endl;
	while (true) {
		cout << separateBlock("ОБНОВЛНИЕ:ЗАПИСИ") << endl;
		int update_id = inputInteger("Введите ID записи для обновления (0 для выхода): ");
		if (update_id == 0) {
			cout << "Выход..." << endl;
			break;
		}
		try {
			db.getInfoById(update_id);
			updateInfo(db, update_id);
		}
		catch (const not_found_exception& e) {
			cout << "Ошибка: " << e.what() << endl;
		}
	}
}

void updateData(Database& db) {
	while (true) {
		int opcode;
		cout << separateSection("ОБНОВЛЕНИЕ ДАННЫХ") << endl
			<< "Выберите действие:" << endl
			<< "[0] Выход в меню" << endl
			<< "[1] Обновление групп" << endl
			<< "[2] Обновление лекторов" << endl
			<< "[3] Обновление предметов" << endl
			<< "[4] Обновление записей" << endl
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
			cout << "Нет действия с таким номером" << endl;
			break;
		}
	}
}


void deleteGroupData(Database& db) {
	cout << separateSubsection("УДАЛЕНИЕ:ГРУППЫ") << endl;
	while (true) {
		cout << separateBlock("УДАЛЕНИЕ:ГРУППЫ") << endl;
		int delete_id = inputInteger("Введите ID группы для удаления (0 для выхода, -1 для удаления всех групп): ");
		if (delete_id == 0) {
			cout << "Выход..." << endl;
			break;
		}
		if (delete_id == -1) {
			try {
				db.deleteAllGroups();
				cout << "Список групп очищен" << endl;
				break;
			}
			catch (const reference_exception& e) {
				cout << "Невозможно очистить список групп: " << e.what() << endl;
				continue;
			}
		}
		try {
			db.deleteGroup(delete_id);
			cout << "Группа с ID " << delete_id << " удалена" << endl;
		}
		catch (const database_exception& e) {
			cout << "Ошибка удаления: " << e.what() << endl;
		}
	}
}

void deleteLecturelData(Database& db) {
	cout << separateSubsection("УДАЛЕНИЕ:ЛЕКТОРЫ") << endl;
	while (true) {
		cout << separateBlock("УДАЛЕНИЕ:ЛЕКТОРЫ") << endl;
		int delete_id = inputInteger("Введите ID лектора для удаления (0 для выхода, -1 для удаления всех лекторов): ");
		if (delete_id == 0) {
			cout << "Выход..." << endl;
			break;
		}
		if (delete_id == -1) {
			try {
				db.deleteAllLecturels();
				cout << "Список лекторов очищен" << endl;
				break;
			}
			catch (const reference_exception& e) {
				cout << "Невозможно очистить список лекторов: " << e.what() << endl;
				continue;
			}
		}
		try {
			db.deleteLecturel(delete_id);
			cout << "Лектор с ID " << delete_id << " удален" << endl;
		}
		catch (const database_exception& e) {
			cout << "Ошибка удаления: " << e.what() << endl;
		}
	}
}

void deleteSubjectData(Database& db) {
	cout << separateSubsection("УДАЛЕНИЕ:ПРЕДМЕТЫ") << endl;
	while (true) {
		cout << separateBlock("УДАЛЕНИЕ:ПРЕДМЕТЫ") << endl;
		int delete_id = inputInteger("Введите ID предмета для удаления (0 для выхода, -1 для удаления всех предметов): ");
		if (delete_id == 0) {
			cout << "Выход..." << endl;
			break;
		}
		if (delete_id == -1) {
			try {
				db.deleteAllSubjects();
				cout << "Список предметов очищен" << endl;
				break;
			}
			catch (const reference_exception& e) {
				cout << "Невозможно очистить список предметов: " << e.what() << endl;
				continue;
			}
		}
		try {
			db.deleteSubject(delete_id);
			cout << "Предмет с ID " << delete_id << " удален" << endl;
		}
		catch (const database_exception& e) {
			cout << "Ошибка удаления: " << e.what() << endl;
		}
	}
}

void deleteInfoData(Database& db) {
	cout << separateSubsection("УДАЛЕНИЕ:ЗАПИСИ") << endl;
	while (true) {
		cout << separateBlock("УДАЛЕНИЕ:ЗАПИСИ") << endl;
		int delete_id = inputInteger("Введите ID записи для удаления (0 для выхода, -1 для удаления всех записей): ");
		if (delete_id == 0) {
			cout << "Выход..." << endl;
			break;
		}
		if (delete_id == -1) {
			db.deleteAllSubjects();
			cout << "Список записей очищен" << endl;
			break;
		}
		try {
			db.deleteSubject(delete_id);
			cout << "Запись с ID " << delete_id << " удалена" << endl;
		}
		catch (const not_found_exception& e) {
			cout << "Ошибка удаления: " << e.what() << endl;
		}
	}
}

void deleteAllData(Database& db) {
	cout << separateSubsection("УДАЛЕНИЕ:ОЧИСТКА") << endl;
	string confirm = inputString("Все данные будут удалены [y/n]: ");
	if (confirm != "y") {
		cout << "Удаление данных отменено" << endl;
		return;
	}
	db.dropDatabase();
	cout << "Все данные удалены" << endl;
}

void deleteData(Database& db) {
	while (true) {
		int opcode;
		cout << separateSection("УДАЛЕНИЕ ДАННЫХ") << endl
			<< "Выберите действие:" << endl
			<< "[-1] Очистить все данные" << endl
			<< "[0] Выход в меню" << endl
			<< "[1] Удаление групп" << endl
			<< "[2] Удаление лекторов" << endl
			<< "[3] Удаление предметов" << endl
			<< "[4] Удаление записей" << endl
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
			cout << "Нет действия с таким номером" << endl;
			break;
		}
	}
}


void loadData(Database& db) {
	cout << separateSection("ЗАГРУЗКА ДАННЫХ") << endl;
	string filename = inputString("Введите название файла (- для использования файла по умолчанию): ");
	if (filename == "-") {
		filename = DEFAULT_DATABASE_FILE;
		cout << "Используется файл по умолчанию" << endl;
	}
	string confirm = inputString("Текущие данные будут переписаны содержимым файла [y/n]: ");
	if (confirm != "y") {
		cout << "Загрузка данных из файла отменена" << endl;
		return;
	}
	try {
		db.loadFromFile(filename);
		cout << "Данные загружены из файла " << filename << endl;
	}
	catch (const file_exception& e) {
		cout << "Не удалось загрузить данные: " << e.what() << endl;
	}
}


void saveData(Database& db) {
	cout << separateSection("СОХРАНЕНИЕ ДАННЫХ") << endl;
	string filename = inputString("Введите название файла (- для использования файла по умолчанию): ");
	if (filename == "-") {
		filename = DEFAULT_DATABASE_FILE;
		cout << "Используется файл по умолчанию" << endl;
	}
	string confirm = inputString("Данные файла будут переписаны [y/n]: ");
	if (confirm != "y") {
		cout << "Запись данных в файл отменена" << endl;
		return;
	}
	try {
		db.saveToFile(filename);
		cout << "Данные сохранены в файл " << filename << endl;
	}
	catch (const file_exception& e) {
		cout << "Не удалось сохранить данные: " << e.what() << endl;
	}
}
