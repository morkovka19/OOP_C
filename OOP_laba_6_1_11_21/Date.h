#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<iomanip>
#include"Set_string.h"
#include"dummy_chek.h"
using namespace std;
class Date
{
	int day;
	int month;
	int year;
public:
	//конструктор с параметрами по умолчанию
	Date(int day = 0, int month = 0, int year = 0);
	//конструктор копирования 
	Date(const Date& date_cpy);

	//деструктор 
	~Date();

	//сеттеры
	void set_day(int day_new);
	void set_month(int month_new);
	void set_year(int year_new);

	//геттеры
	int get_day();
	int get_month();
	int get_year();

	//вывод информации 
	void print_info();

	//ввод нового объекта 
	void set_info();

	//форматированный вывод
	void table_out();

	 //работа с потоками 
	void file_in(istream& is);
	void file_out(ostream& os);

	//перегрузка оператора вывода
	friend ostream& operator<<(ostream& os, const Date& date);
	
	//перегрузка оператора присваивания 
	void operator =( const Date& right);

	//перегрузка оператора сравнения 
	friend bool operator==(Date& left, Date& right);

	//перегрузка оператора ввода
	friend istream& operator>>(istream& is, Date& date);

	//перевод в часы
	int conversion_to_hours();


};

