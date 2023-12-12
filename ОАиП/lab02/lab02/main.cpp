#include <Windows.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


const int SEPARATOR_LENGTH = 20;
const char SECTION_SEPARATOR = '=';
const char BLOCK_SEPARATOR = '-';
const char* DATABASE_FILE = "data.bin";


enum class Airport {
	Minsk,
	Moscow,
	StPetersburg,
	Istanbul,
	Baku,
	Yerevan,
	Tbilisi,
	Dubai,
	UNKNOWN,
};


struct Price {
	enum { INTEGER, DOUBLE } type;
	union {
		int integer_value;
		double double_value;
	};
};


struct Time {
	unsigned hour : 5;
	unsigned minute : 6;
};


struct Date {
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 12;
	
	bool operator==(const Date& other) {
		return this->day == other.day 
			&& this->month == other.month
			&& this->year == other.year;
	}
};


struct Flight {
	unsigned flight_number;
	Airport destination;
	Date departure_date;
	Time departure_time;
	Price ticket_price;
	unsigned seats_number;
};


const char* getAirportName(Airport airport) {
	switch (airport) {
	case Airport::Minsk: return "Минск";
	case Airport::Moscow: return "Москва";
	case Airport::StPetersburg: return "Санкт-Петербург";
	case Airport::Istanbul: return "Стамбул";
	case Airport::Baku: return "Баку";
	case Airport::Yerevan: return "Ереван";
	case Airport::Tbilisi: return "Тбилиси";
	case Airport::Dubai: return "Дубай";
	default: return "[UNKNOWN AIRPORT]";
	}
}


Airport getAirport(string airport_name) {
	if (!airport_name.compare("Минск")) return Airport::Minsk;
	if (!airport_name.compare("Москва")) return Airport::Moscow;
	if (!airport_name.compare("Санкт-Петербург")) return Airport::StPetersburg;
	if (!airport_name.compare("Стамбул")) return Airport::Istanbul;
	if (!airport_name.compare("Баку")) return Airport::Baku;
	if (!airport_name.compare("Ереван")) return Airport::Yerevan;
	if (!airport_name.compare("Тбилиси")) return Airport::Tbilisi;
	if (!airport_name.compare("Дубай")) return Airport::Dubai;
	return Airport::UNKNOWN;
}


int inputInteger(const char* placeholder = "") {
	string str_value;
	while (true) {
		cout << placeholder; cin >> str_value;
		try {
			return stoi(str_value);
		}
		catch (invalid_argument) {
			cout << "Введенные данные не являются числом" << endl;
		}
		catch (out_of_range) {
			cout << "Введенное число слишком большое" << endl;
		}
	}
}


Airport inputAirport(const char* placeholder = "") {
	string airport_name;
	Airport airport;
	while (true) {
		cout << placeholder; cin >> airport_name;
		airport = getAirport(airport_name);
		if (airport == Airport::UNKNOWN) {
			cout << "Неверное название пункта назначения" << endl;
			continue;
		}
		return airport;
	}
}


Date inputDate(const char* placeholder = "") {
	string str_date;
	Date date;
	while (true) {
		cout << placeholder; cin >> str_date;
		if (str_date.find_first_of(".") == str_date.find_last_of(".")) {
			cout << "Неверный формат даты" << endl;
			continue;
		}
		try {
			string str_day = str_date.substr(0, 2);
			string str_month = str_date.substr(3, 5);
			string str_year = str_date.substr(6, 10);
			date.day = stoi(str_day);
			date.month = stoi(str_month);
			date.year = stoi(str_year);
			return date;
		}
		catch (invalid_argument) {
			cout << "Введенные данные не являются числовым значением даты" << endl;
		}
	}
}


Time inputTime(const char* placeholder = "") {
	string str_time;
	Time time;
	while (true) {
		cout << placeholder; cin >> str_time;
		if (str_time.find(":") == string::npos) {
			cout << "Неверный формат времени" << endl;
			continue;
		}
		try {
			string str_hour = str_time.substr(0, 2);
			string str_minute = str_time.substr(3, 5);
			time.hour = stoi(str_hour);
			time.minute = stoi(str_minute);
			return time;
		}
		catch (invalid_argument) {
			cout << "Введенные данные не являются числовым значением времени" << endl;
		}
	}
}


Price inputPrice(const char* placeholder = "") {
	string str_price;
	Price price;
	while (true) {
		cout << placeholder; cin >> str_price;
		try {
			if (str_price.find(".") != string::npos) {
				price.type = Price::DOUBLE;
				price.double_value = stod(str_price);
			}
			else {
				price.type = Price::INTEGER;
				price.integer_value = stoi(str_price);
			}
			return price;
		}
		catch (invalid_argument) {
			cout << "Введенное значение не является числом" << endl;
		}
		catch (out_of_range) {
			cout << "Введенное число слишком большое" << endl;
		}
	}
}


Flight inputFlight() {
	Flight flight;
	flight.flight_number = inputInteger("Номер рейса: ");
	flight.destination = inputAirport("Пункт назначения: ");
	flight.departure_date = inputDate("Дата отправления: ");
	flight.departure_time = inputTime("Время отправления: ");
	flight.ticket_price = inputPrice("Стоимость билета: ");
	flight.seats_number = inputInteger("Количество мест: ");
	return flight;
}


string toString(int value) {
	ostringstream ss;
	ss << value;
	return ss.str();
}


string toString(Airport airport) {
	return getAirportName(airport);
}


string toString(const Date& date) {
	ostringstream ss;
	ss << setw(2) << setfill('0') << date.day 
		<< "." 
		<< setw(2) << setfill('0') << date.month 
		<< "." 
		<< setw(4) << setfill('0') << date.year;
	return ss.str();
}


string toString(const Time& time) {
	ostringstream ss;
	ss << setw(2) << setfill('0') << time.hour 
		<< ':' 
		<< setw(2) << setfill('0') << time.minute;
	return ss.str();
}


string toString(const Price& price) {
	ostringstream ss;
	switch (price.type) {
	case Price::DOUBLE: 
		ss << price.double_value;
		break;
	case Price::INTEGER:
		ss << price.integer_value;
		break;
	}
	return ss.str();
}


string toString(const Flight& flight) {
	ostringstream ss;
	ss << "Номер рейса: " << toString(flight.flight_number) << endl
		<< "Пункт назначения: " << toString(flight.destination) << endl
		<< "Дата отправления: " << toString(flight.departure_date) << endl
		<< "Время отправления: " << toString(flight.departure_time) << endl
		<< "Стоимость билета: " << toString(flight.ticket_price) << endl
		<< "Количество мест: " << toString(flight.seats_number) << endl;
	return ss.str();
}


void separateSection(const char* section_title) {
	cout << setw(SEPARATOR_LENGTH) << setfill(SECTION_SEPARATOR) << SECTION_SEPARATOR
		<< "[" << section_title << "]"
		<< setw(SEPARATOR_LENGTH) << setfill(SECTION_SEPARATOR) << SECTION_SEPARATOR 
		<< endl;
}


void separateBlock(const char* block_title, int chapter = 0) {
	cout << setw(SEPARATOR_LENGTH) << setfill(BLOCK_SEPARATOR) << BLOCK_SEPARATOR
		<< "[" << block_title << (chapter > 0? toString(chapter) : "") << "]"
		<< setw(SEPARATOR_LENGTH) << setfill(BLOCK_SEPARATOR) << BLOCK_SEPARATOR
		<< endl;
}


void exitProgram() {
	separateSection("ВЫХОД");
	cout << "Выход из программы...";
	exit(0);
}


void inputData(vector<Flight>& flights) {
	separateSection("ВВОД ДАННЫХ");
	int add_count;
	cout << "Введите количество рейсов для ввода: "; cin >> add_count;
	for (int i = 1; i <= add_count; i++) {
		separateBlock("Ввод: Рейс#", i);
		flights.push_back(inputFlight());
	}
}


void outputData(const vector<Flight>& flights) {
	separateSection("ВЫВОД ДАННЫХ");
	if (flights.empty()) {
		cout << "Нет сохраненных данных" << endl;
		return;
	}
	for (Flight flight : flights) {
		separateBlock("Рейс#", flight.flight_number);
		cout << toString(flight);
	}
}


void deleteData(vector<Flight>& flights) {
	separateSection("УДАЛЕНИЕ ДАННЫХ");
	int delete_flight_number;
	bool found;
	cout << "Введите номер рейса для удаления (-1 для выхода): " << endl;
	while (true) {
		if (flights.empty()) {
			cout << "Не осталось сохраненных записей" << endl;
			break;
		}
		found = false;
		delete_flight_number = inputInteger(">>> ");
		if (delete_flight_number == -1) {
			cout << "Выход..." << endl;
			break;
		}
		for (int i = 0; i < flights.size(); i++) {
			Flight flight = flights[i];
			if (flights[i].flight_number == delete_flight_number) {
				found = true;
				cout << "Рейс#" << flight.flight_number << " успешно удален." << endl;
				flights.erase(flights.begin() + i);
			}
		}
		if (!found) {
			cout << "Рейс с таким номером не найден" << endl;
		}
	}
}


void searchByDate(const vector<Flight>& flights) {
	separateSection("ПОИСК ПО ДАТЕ");
	if (flights.empty()) {
		cout << "Нет сохраненных данных" << endl;
		return;
	}
	while (true) {
		Date search_date = inputDate("Введите дату для поиска: ");
		int found_flights_count = 0;
		for (Flight flight : flights) {
			if (flight.departure_date == search_date) {
				if (found_flights_count == 0) {
					cout << "Список рейсов на " << toString(search_date) << endl;
				}
				found_flights_count++;
				separateBlock("Рейс#", flight.flight_number);
				cout << toString(flight);
			}
		}
		if (found_flights_count == 0) {
			cout << "Не найдено рейсов на " << toString(search_date) << endl;
		}
		char continue_choice;
		cout << "Продолжить? [y/n, д/н]: "; cin >> continue_choice;
		if (continue_choice == 'y' || continue_choice == 'д') {
			continue;
		}
		break;
	}
}


void searchByDestination(const vector<Flight>& flights) {
	separateSection("ПОИСК ПО ПУНКТУ НАЗНАЧЕНИЯ");
	if (flights.empty()) {
		cout << "Нет сохраненных данных" << endl;
		return;
	}
	while (true) {
		Airport search_airport = inputAirport("Введите пункт назначения для поиска: ");
		int found_flights_count = 0;
		for (Flight flight : flights) {
			if (flight.destination == search_airport) {
				if (found_flights_count == 0) {
					cout << "Список рейсов в " << toString(search_airport) << endl;
				}
				found_flights_count++;
				separateBlock("Рейс#", flight.flight_number);
				cout << toString(flight);
			}
		}
		if (found_flights_count == 0) {
			cout << "Не найдено рейсов в " << toString(search_airport) << endl;
		}
		char continue_choice;
		cout << "Продолжить? [y/n, д/н]: "; cin >> continue_choice;
		if (continue_choice == 'y' || continue_choice == 'д') {
			continue;
		}
		break;
	}
}


void loadDataFromFile(vector<Flight>& flights) {
	separateSection("ЗАГРУЗКА ИЗ ФАЙЛА");
	char continue_choice;
	cout << "Данные в оперативной памяти будут перезаписаны. Продолжить? [y/n, д/н]: "; cin >> continue_choice;
	if (continue_choice != 'y' && continue_choice != 'д') {
		cout << "Операция отменена" << endl;
		return;
	}
	Flight buf;
	ifstream file;
	file.open(DATABASE_FILE, ios::binary);
	if (!file) {
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	flights.clear();
	file.read((char*)&buf, sizeof(buf));
	while (!file.eof()) {
		flights.push_back(buf);
		file.read((char*)&buf, sizeof(buf));
	}
	file.close();
	cout << "Загружено " << flights.size() << " записей" << endl;
}


void saveDataToFile(const vector<Flight>& flights) {
	separateSection("СОХРАНЕНИЕ В ФАЙЛ");
	char continue_choice;
	cout << "Данные в базе будут перезаписаны. Продолжить? [y/n, д/н]: "; cin >> continue_choice;
	if (continue_choice != 'y' && continue_choice != 'д') {
		cout << "Операция отменена" << endl;
		return;
	}
	ofstream file;
	file.open(DATABASE_FILE, ios::binary);
	if (!file) {
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	for (Flight flight : flights) {
		file.write((char*)&flight, sizeof(flight));
	}
	file.close();
	cout << "Сохранено " << flights.size() << " записей" << endl;
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Flight> flights;

	while (true) {
		separateSection("МЕНЮ");
		int opcode;
		cout << "Выберите желаемую операцию:" << endl
			<< "[0] Выход из программы" << endl
			<< "[1] Ввод данных" << endl
			<< "[2] Вывод данных" << endl
			<< "[3] Удаление данных" << endl
			<< "[4] Поиск по дате" << endl
			<< "[5] Поиск по пункту назначения" << endl
			<< "[6] Чтение данных из файла" << endl
			<< "[7] Запись данных в файл" << endl
			<< ">>> "; cin >> opcode;

		switch (opcode) {
		case 0:
			exitProgram();
			break;
		case 1:
			inputData(flights);
			break;
		case 2:
			outputData(flights);
			break;
		case 3:
			deleteData(flights);
			break;
		case 4:
			searchByDate(flights);
			break;
		case 5:
			searchByDestination(flights);
			break;
		case 6:
			loadDataFromFile(flights);
			break;
		case 7:
			saveDataToFile(flights);
			break;
		default:
			cout << "Неверный номер операции" << endl;
		}
	}
}
