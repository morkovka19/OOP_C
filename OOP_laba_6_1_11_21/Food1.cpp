#include "Food1.h"

//����������� � ����������� �� ���������
Food1::Food1(char* fam, double cost, int quant, int day1 , int month1, int year1 , int day2, int month2, int year2 ):common(fam, cost, quant, day1, month1, year1), date2(day2, month2, year2){}
//����������� ����������� 
Food1::Food1(const Food1& food1_cpy) {
	fam = new char[strlen(food1_cpy.fam) + 1];
	strcpy(fam, food1_cpy.fam);
	cost = food1_cpy.cost;
	quant = food1_cpy.quant;
	date1 = food1_cpy.date1;
	date2 = food1_cpy.date2;
}

//���������� 
Food1::~Food1() {
	delete[] fam;
}

//�������
void Food1::set_date2(Date date_new) {
	date2 = date_new;
}

//�������
Date Food1::get_date() {
	Date buff(date2);
	return buff;
}

//���� ������ ������� 
void Food1::set_info() {
	cout << "��������: ";
	dummy_check(fam);
	cout << "\n����: ";
	dummy_check(cost);
	cout << "\n����������: ";
	dummy_check(quant);
	cout << "\n���� ������������: ";
	date1.set_info();
	cout << "\n���� �������: ";
	date2.set_info();

}
//����� ���������� 
void Food1::print_info() {
	cout << "��������: " << fam;
	cout << "\n����: " << cost;
	cout << "\n����������: " << quant;
	cout << "\n���� ������������: ";
	date1.print_info();
	cout << "���� �������: ";
	date2.print_info();
}
//��������������� �����
void  Food1::table_out() {
	cout << setw(20) << fam << "|";
	cout << setw(15) << cost << "|";
	cout << setw(15) << quant << "|";
	date1.table_out();
	date2.table_out();
	cout << '\n';
}

//������ � �������� 
void Food1::file_in(istream& is) {
	char buff[4096];
	is.ignore(9999, '\n');
	is.getline(buff, 4096);
	fam = new char[strlen(buff) + 1];
	strcpy(fam, buff);
	is >> cost;
	is >> quant;
	date1.file_in(is);
	date2.file_in(is);
}
void Food1::file_out(ostream& os) {
	os << fam << "\n";
	os << cost << "\n";
	os << quant << "\n";
	date1.file_out(os);
	date2.file_out(os);
}

//���������� ��������� ������
ostream& operator<<(ostream& os, Food1& food1) {
	os << setw(20) << food1.fam << "|";
	os << setw(15) << food1.cost << "|";
	os << setw(15) << food1.quant << "|";
	os << food1.date1;
	os << food1.date2;
	cout << '\n';
	return os;
}

//���������� ��������� ��������� 
bool operator==(Food1& left, Date& right) {
	return(left.date1 == right);
}

//���������� ��������� �����
istream& operator>>(istream& is, Food1& food1) {
	cout << "��������: ";
	char buff[4096];
	//is.ignore(9999, '\n');
	//is.getline(buff, 4096);
	food1.fam = new char[strlen(buff) + 1];
	strcpy(food1.fam, buff);
	cout << "\n����: ";
	is >> food1.cost;
	cout << "\n����������: ";
	is >> food1.quant;
	cout << "\n���� ������������: ";
	is >> food1.date1;
	cout << "\n���� �������: ";
	is >> food1.date2;
	return is;
 }

//���������� ��������� ����������� 
void Food1::operator=(const Food1& food) {
	fam = new char[strlen(food.fam) + 1];
	strcpy(fam, food.fam);
	cost = food.cost;
	quant = food.quant;
	date1 = food.date1;
	date2 = food.date2;
}