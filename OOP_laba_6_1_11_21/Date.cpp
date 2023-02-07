#include "Date.h"
//конструктор с параметрами по умолчанию
Date::Date(int day, int month, int year):day(day), month(month), year(year){}
//конструктор копирования 
Date::Date(const Date& date_cpy) :day(date_cpy.day), month(date_cpy.month), year(date_cpy.year){}

//деструктор 
Date::~Date(){}

//сеттеры
void Date::set_day(int day_new) {
	day = day_new;
}
void Date::set_month(int month_new) {
	month = month_new;
}
void Date::set_year(int year_new) {
	year = year_new;
}

//геттеры
int Date::get_day() {
	int buff = day;
	return buff;
}
int Date::get_month() {
	int buff = month;
	return buff;
}
int Date::get_year() {
	int buff = year;
	return buff;
}

//вывод информации 
void Date::print_info() {
	printf(" %#02d:%#02d:%#04d\n", day, month, year);
};

//ввод нового объекта 
void Date::set_info() {
	cout << "\nДень: ";
	dummy_check(day, 1, 31);
	cout << "\nМесяц: ";
	dummy_check(month, 1, 12);
	cout << "\nГод: ";
	dummy_check(year, 2020, 2022);
	cout << '\n';
}

//форматированный вывод
void Date::table_out() {
	cout<< setw(15) << day << ":" << month << ":" << year << "|";
}

//работа с потоками 
void Date::file_in(istream& is) {
	is >> day;
	is >> month;
	is >> year;
}
void Date::file_out(ostream& os) {
	os << day << '\n';
	os << month << '\n';
	os << year << '\n';
}

//перегрузка оператора присваивания 
void Date::operator =(const Date& right) {
	day = right.day;
	month = right.month;
	year = right.year;
}

//перегрузка оператора вывода
ostream& operator<<(ostream& os, const Date& date) {
	os <<setw(15)<< date.day << ":" << date.month << ":" << date.year << "|";
	return os;
}

//перегрузка оператора сравнения 
bool operator==(Date& left, Date& right) {
	return (left.day == right.day && left.month == right.month && left.year == right.year);
}

//перегрузка оператора ввода
istream& operator >>(istream& is, Date& date) {
	cout << "\nДень: ";
	is>> date.day;
	cout << "\nМесяц: ";
	is >> date.month;
	cout << "\nГод: ";
	is >> date.year;
	cout << '\n';
	return is;
}

//перевод в часы
int Date::conversion_to_hours() {
	int hours = day * 24 + month * 720 + year * 8760;
	return hours;
}

