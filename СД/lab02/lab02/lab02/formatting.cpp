#include <iomanip>
#include <string>
#include <sstream>

using namespace std;


const int SEPARATOR_WIDTH = 25;
const char SECTION_SEPARATOR = '=';
const char SUBSECTION_SEPARATOR = '+';
const char BLOCK_SEPARATOR = '-';


// Базовая функция разделения
string separate(string title, char separator, int width) {
	stringstream buf;
	buf << setw(width) << setfill(separator) << separator
		<< '[' << title << ']'
		<< setw(width) << setfill(separator) << separator;
	return buf.str();
}


// Раздел
string separateSection(string title) {
	return separate(title, SECTION_SEPARATOR, SEPARATOR_WIDTH);
}


// Подраздел
string separateSubsection(string title) {
	return separate(title, SUBSECTION_SEPARATOR, SEPARATOR_WIDTH);
}


// Блок
string separateBlock(string title) {
	return separate(title, BLOCK_SEPARATOR, SEPARATOR_WIDTH);
}


// Блок с числовой информацией
string separateBlock(string title, int chapter) {
	stringstream fulltitle;
	fulltitle << title << chapter;
	return separate(fulltitle.str(), BLOCK_SEPARATOR, SEPARATOR_WIDTH);
}
