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

	//����������� � ����������� �� ���������
	Food(char* fam = new char[0], double cost = 0, int quant = 0, int day = 0, int month = 0, int year = 0, int type = 0, double weight = 0);
	//����������� ����������� 
	Food(const Food& food_cpy);

	//���������� 
	~Food();

	//�������
	void set_type(int type_new);
	void set_weight(double weight_new);

	//�������
	int get_type();
	double get_weight();

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
	friend ostream& operator<<(ostream& os, Food& food);

	//��������� �� ����
	bool cmp_by_type(int buff);

	//���������� ��������� ��������� 
	friend bool operator==(Food& left, Date& right);

	//���������� ��������� �����
	friend istream& operator>>(istream& is, Food& food);

	//���������� ��������� ����������� 
	void operator=( const Food& food);
	

};

