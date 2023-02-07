#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<iomanip>
#include"Set_string.h"
#include"Date.h"
#include"common.h"
#include"dummy_chek.h"
using namespace std;

class Food1:public common
{
	Date date2;
public:
	static int count;
	//конструктор с параметрами по умолчанию
	Food1(char* fam = new char[0], double cost = 0, int quant = 0, int day1 = 0, int month1 = 0, int year1 = 0, int day2 = 0, int month2 = 0, int year2 = 0);
	//конструктор копирования 
	Food1(const Food1& food1_cpy);

	//деструктор 
	~Food1();

	//сеттеры
	void set_date2(Date date_new);

	//геттеры
	Date get_date();

	//ввод нового объекта 
	void set_info();
	//вывод информации 
	void print_info();
	//форматированный вывод
	void  table_out();

	//работа с потоками 
	void file_in(istream& is);
	void file_out(ostream& os);

	//перегрузка оператора вывода
	friend ostream& operator<<(ostream& os, Food1& food1);

	//перегрузка оператора сравнения 
	friend bool operator==(Food1& left, Date& right);

	//перегрузка оператора ввода
	friend istream& operator>>(istream& is, Food1& food1);

	//перегрузка оператора присваиваия 
	void operator=(const Food1& food);

};

