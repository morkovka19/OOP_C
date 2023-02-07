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
class Food : public common
{
	int type;
	double weight;
public:
	static int count;

	//конструктор с параметрами по умолчанию
	Food(char* fam = new char[0], double cost = 0, int quant = 0, int day = 0, int month = 0, int year = 0, int type = 0, double weight = 0);
	//конструктор копирования 
	Food(const Food& food_cpy);

	//деструктор 
	~Food();

	//сеттеры
	void set_type(int type_new);
	void set_weight(double weight_new);

	//геттеры
	int get_type();
	double get_weight();

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
	friend ostream& operator<<(ostream& os, Food& food);

	//сравнение по типу
	bool cmp_by_type(int buff);

	//перегрузка оператора сравнения 
	friend bool operator==(Food& left, Date& right);

	//перегрузка оператора ввода
	friend istream& operator>>(istream& is, Food& food);

	//перегрузка оператора присваиваия 
	void operator=( const Food& food);
	

};

