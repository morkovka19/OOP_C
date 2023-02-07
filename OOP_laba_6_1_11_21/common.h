#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<iomanip>
#include"Set_string.h"
#include"Date.h"
#include"dummy_chek.h"
using namespace std;

class common
{
protected:
	char* fam;
	double cost;
	Date date1;
	int quant;
public:
	//контруткор с параметрами по умолчанию
	common(char* fam = new char[0], double cost = 0,int quant=0, int day = 0, int month = 0, int year = 0);
	//конструктор копирования 
	common(const common& common_cpy);

	//деструктор
	virtual ~common() {};

	//сетеры
	void set_fam(char* fam_new);
	void set_cost(double cost_new);
	void set_date1(Date date_new);
	void set_quant(int quant_new);

	//геттеры
	char* get_fam();
	double get_cost();
	Date get_date();
	int get_quant();

	//работа с потоками 
	virtual void file_in(istream& is) = 0;
	virtual void file_out(ostream& os) = 0;

	virtual void table_out() =0;
	virtual void print_info() =0;
	virtual void set_info() =0;
	virtual bool cmp_by_type(int buff) { return false; };

	//сравнение по названию 
	bool cmp_by_fam(char buff[4096]);
	//сравнение по цене 
	bool cmp_by_cost(double buff);
	
};

