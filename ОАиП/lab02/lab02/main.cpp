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
	case Airport::Minsk: return "�����";
	case Airport::Moscow: return "������";
	case Airport::StPetersburg: return "�����-���������";
	case Airport::Istanbul: return "�������";
	case Airport::Baku: return "����";
	case Airport::Yerevan: return "������";
	case Airport::Tbilisi: return "�������";
	case Airport::Dubai: return "�����";
	default: return "[UNKNOWN AIRPORT]";
	}
}


Airport getAirport(string airport_name) {
	if (!airport_name.compare("�����")) return Airport::Minsk;
	if (!airport_name.compare("������")) return Airport::Moscow;
	if (!airport_name.compare("�����-���������")) return Airport::StPetersburg;
	if (!airport_name.compare("�������")) return Airport::Istanbul;
	if (!airport_name.compare("����")) return Airport::Baku;
	if (!airport_name.compare("������")) return Airport::Yerevan;
	if (!airport_name.compare("�������")) return Airport::Tbilisi;
	if (!airport_name.compare("�����")) return Airport::Dubai;
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
			cout << "��������� ������ �� �������� ������" << endl;
		}
		catch (out_of_range) {
			cout << "��������� ����� ������� �������" << endl;
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
			cout << "�������� �������� ������ ����������" << endl;
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
			cout << "�������� ������ ����" << endl;
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
			cout << "��������� ������ �� �������� �������� ��������� ����" << endl;
		}
	}
}


Time inputTime(const char* placeholder = "") {
	string str_time;
	Time time;
	while (true) {
		cout << placeholder; cin >> str_time;
		if (str_time.find(":") == string::npos) {
			cout << "�������� ������ �������" << endl;
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
			cout << "��������� ������ �� �������� �������� ��������� �������" << endl;
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
			cout << "��������� �������� �� �������� ������" << endl;
		}
		catch (out_of_range) {
			cout << "��������� ����� ������� �������" << endl;
		}
	}
}


Flight inputFlight() {
	Flight flight;
	flight.flight_number = inputInteger("����� �����: ");
	flight.destination = inputAirport("����� ����������: ");
	flight.departure_date = inputDate("���� �����������: ");
	flight.departure_time = inputTime("����� �����������: ");
	flight.ticket_price = inputPrice("��������� ������: ");
	flight.seats_number = inputInteger("���������� ����: ");
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
	ss << "����� �����: " << toString(flight.flight_number) << endl
		<< "����� ����������: " << toString(flight.destination) << endl
		<< "���� �����������: " << toString(flight.departure_date) << endl
		<< "����� �����������: " << toString(flight.departure_time) << endl
		<< "��������� ������: " << toString(flight.ticket_price) << endl
		<< "���������� ����: " << toString(flight.seats_number) << endl;
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
	separateSection("�����");
	cout << "����� �� ���������...";
	exit(0);
}


void inputData(vector<Flight>& flights) {
	separateSection("���� ������");
	int add_count;
	cout << "������� ���������� ������ ��� �����: "; cin >> add_count;
	for (int i = 1; i <= add_count; i++) {
		separateBlock("����: ����#", i);
		flights.push_back(inputFlight());
	}
}


void outputData(const vector<Flight>& flights) {
	separateSection("����� ������");
	if (flights.empty()) {
		cout << "��� ����������� ������" << endl;
		return;
	}
	for (Flight flight : flights) {
		separateBlock("����#", flight.flight_number);
		cout << toString(flight);
	}
}


void deleteData(vector<Flight>& flights) {
	separateSection("�������� ������");
	int delete_flight_number;
	bool found;
	cout << "������� ����� ����� ��� �������� (-1 ��� ������): " << endl;
	while (true) {
		if (flights.empty()) {
			cout << "�� �������� ����������� �������" << endl;
			break;
		}
		found = false;
		delete_flight_number = inputInteger(">>> ");
		if (delete_flight_number == -1) {
			cout << "�����..." << endl;
			break;
		}
		for (int i = 0; i < flights.size(); i++) {
			Flight flight = flights[i];
			if (flights[i].flight_number == delete_flight_number) {
				found = true;
				cout << "����#" << flight.flight_number << " ������� ������." << endl;
				flights.erase(flights.begin() + i);
			}
		}
		if (!found) {
			cout << "���� � ����� ������� �� ������" << endl;
		}
	}
}


void searchByDate(const vector<Flight>& flights) {
	separateSection("����� �� ����");
	if (flights.empty()) {
		cout << "��� ����������� ������" << endl;
		return;
	}
	while (true) {
		Date search_date = inputDate("������� ���� ��� ������: ");
		int found_flights_count = 0;
		for (Flight flight : flights) {
			if (flight.departure_date == search_date) {
				if (found_flights_count == 0) {
					cout << "������ ������ �� " << toString(search_date) << endl;
				}
				found_flights_count++;
				separateBlock("����#", flight.flight_number);
				cout << toString(flight);
			}
		}
		if (found_flights_count == 0) {
			cout << "�� ������� ������ �� " << toString(search_date) << endl;
		}
		char continue_choice;
		cout << "����������? [y/n, �/�]: "; cin >> continue_choice;
		if (continue_choice == 'y' || continue_choice == '�') {
			continue;
		}
		break;
	}
}


void searchByDestination(const vector<Flight>& flights) {
	separateSection("����� �� ������ ����������");
	if (flights.empty()) {
		cout << "��� ����������� ������" << endl;
		return;
	}
	while (true) {
		Airport search_airport = inputAirport("������� ����� ���������� ��� ������: ");
		int found_flights_count = 0;
		for (Flight flight : flights) {
			if (flight.destination == search_airport) {
				if (found_flights_count == 0) {
					cout << "������ ������ � " << toString(search_airport) << endl;
				}
				found_flights_count++;
				separateBlock("����#", flight.flight_number);
				cout << toString(flight);
			}
		}
		if (found_flights_count == 0) {
			cout << "�� ������� ������ � " << toString(search_airport) << endl;
		}
		char continue_choice;
		cout << "����������? [y/n, �/�]: "; cin >> continue_choice;
		if (continue_choice == 'y' || continue_choice == '�') {
			continue;
		}
		break;
	}
}


void loadDataFromFile(vector<Flight>& flights) {
	separateSection("�������� �� �����");
	char continue_choice;
	cout << "������ � ����������� ������ ����� ������������. ����������? [y/n, �/�]: "; cin >> continue_choice;
	if (continue_choice != 'y' && continue_choice != '�') {
		cout << "�������� ��������" << endl;
		return;
	}
	Flight buf;
	ifstream file;
	file.open(DATABASE_FILE, ios::binary);
	if (!file) {
		cout << "�� ������� ������� ����" << endl;
		return;
	}
	flights.clear();
	file.read((char*)&buf, sizeof(buf));
	while (!file.eof()) {
		flights.push_back(buf);
		file.read((char*)&buf, sizeof(buf));
	}
	file.close();
	cout << "��������� " << flights.size() << " �������" << endl;
}


void saveDataToFile(const vector<Flight>& flights) {
	separateSection("���������� � ����");
	char continue_choice;
	cout << "������ � ���� ����� ������������. ����������? [y/n, �/�]: "; cin >> continue_choice;
	if (continue_choice != 'y' && continue_choice != '�') {
		cout << "�������� ��������" << endl;
		return;
	}
	ofstream file;
	file.open(DATABASE_FILE, ios::binary);
	if (!file) {
		cout << "�� ������� ������� ����" << endl;
		return;
	}
	for (Flight flight : flights) {
		file.write((char*)&flight, sizeof(flight));
	}
	file.close();
	cout << "��������� " << flights.size() << " �������" << endl;
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Flight> flights;

	while (true) {
		separateSection("����");
		int opcode;
		cout << "�������� �������� ��������:" << endl
			<< "[0] ����� �� ���������" << endl
			<< "[1] ���� ������" << endl
			<< "[2] ����� ������" << endl
			<< "[3] �������� ������" << endl
			<< "[4] ����� �� ����" << endl
			<< "[5] ����� �� ������ ����������" << endl
			<< "[6] ������ ������ �� �����" << endl
			<< "[7] ������ ������ � ����" << endl
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
			cout << "�������� ����� ��������" << endl;
		}
	}
}
