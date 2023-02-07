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
	//����������� � ����������� �� ���������
	Date(int day = 0, int month = 0, int year = 0);
	//����������� ����������� 
	Date(const Date& date_cpy);

	//���������� 
	~Date();

	//�������
	void set_day(int day_new);
	void set_month(int month_new);
	void set_year(int year_new);

	//�������
	int get_day();
	int get_month();
	int get_year();

	//����� ���������� 
	void print_info();

	//���� ������ ������� 
	void set_info();

	//��������������� �����
	void table_out();

	 //������ � �������� 
	void file_in(istream& is);
	void file_out(ostream& os);

	//���������� ��������� ������
	friend ostream& operator<<(ostream& os, const Date& date);
	
	//���������� ��������� ������������ 
	void operator =( const Date& right);

	//���������� ��������� ��������� 
	friend bool operator==(Date& left, Date& right);

	//���������� ��������� �����
	friend istream& operator>>(istream& is, Date& date);

	//������� � ����
	int conversion_to_hours();


};

