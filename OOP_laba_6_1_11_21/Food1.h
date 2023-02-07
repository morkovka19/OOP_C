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
	//����������� � ����������� �� ���������
	Food1(char* fam = new char[0], double cost = 0, int quant = 0, int day1 = 0, int month1 = 0, int year1 = 0, int day2 = 0, int month2 = 0, int year2 = 0);
	//����������� ����������� 
	Food1(const Food1& food1_cpy);

	//���������� 
	~Food1();

	//�������
	void set_date2(Date date_new);

	//�������
	Date get_date();

	//���� ������ ������� 
	void set_info();
	//����� ���������� 
	void print_info();
	//��������������� �����
	void  table_out();

	//������ � �������� 
	void file_in(istream& is);
	void file_out(ostream& os);

	//���������� ��������� ������
	friend ostream& operator<<(ostream& os, Food1& food1);

	//���������� ��������� ��������� 
	friend bool operator==(Food1& left, Date& right);

	//���������� ��������� �����
	friend istream& operator>>(istream& is, Food1& food1);

	//���������� ��������� ����������� 
	void operator=(const Food1& food);

};

