#include "Food.h"

//����������� � ����������� �� ���������
Food::Food(char* fam, double cost, int quant, int day , int month , int year, int type, double weight):common(fam, cost, quant, day, month, year), type(type), weight(weight){}
//����������� ����������� 
Food::Food(const Food& food_cpy) {
	fam = new char[strlen(food_cpy.fam) + 1];
	strcpy(fam, food_cpy.fam);
	cost = food_cpy.cost;
	quant = food_cpy.quant;
	date1 = food_cpy.date1;
	type = food_cpy.type;
	weight = food_cpy.weight;

}

//���������� 
Food::~Food() {
	delete[] fam;
}

//�������
void Food::set_type(int type_new) {
	type = type_new;
}
void Food::set_weight(double weight_new) {
	weight = weight_new;
}

//�������
int Food::get_type() {
	int buff = type;
	return buff;
}
double Food::get_weight() {
	double buff = weight;
	return buff;
}

//���� ������ ������� 
void Food::set_info() {
	cout << "��������: ";
	dummy_check(fam);
	cout << "\n����: ";
	dummy_check(cost);
	cout << "\n����������: ";
	dummy_check(quant);
	cout << "\n���: ";
	dummy_check(type,1,3);
	cout << "\n���: ";
	dummy_check(weight);
	cout << "\n���� ������������: ";
	date1.set_info();
}

//����� ���������� �� ������� 
void Food::print_info() {
	cout << "��������: " << fam;
	cout << "\n����: " << cost;
	cout << "\n����������: " << quant;
	cout << "\n���: " << type;
	cout << "\n���: " << weight;
	cout << "\n���� ������������: ";
	date1.print_info();
}

//��������������� �����
void  Food::table_out() {
	cout << setw(20) << fam << "|";
	cout << setw(15) << cost << "|";
	cout << setw(15) << quant << "|";
	cout << setw(10) << type << "|";
	cout << setw(15) << weight << "|";
	date1.table_out();
	cout << '\n';
}

//������ � �������� 
void Food::file_in(istream& is) {
	char buff[4096];
	is.ignore(9999, '\n');
	is.getline(buff, 4096);
	fam = new char[strlen(buff) + 1];
	strcpy(fam, buff);
	is >> cost;
	is >> quant;
	is >> type;
	is >> weight;
	date1.file_in(is);
}
void Food::file_out(ostream& os){
	os << fam << "\n";
	os << cost << "\n";
	os << quant << "\n";
	os << type << "\n";
	os << weight << "\n";
	date1.file_out(os);
}

//���������� ��������� ������ 
ostream& operator<<(ostream& os, Food& food) {
	os << setw(20) << food.fam << "|";
	os << setw(15) << food.cost << "|";
	os << setw(15) << food.quant << "|";
	os << setw(10) << food.type << "|";
	os << setw(15) << food.weight << "|";
	os << food.date1;
	cout << '\n';
	return os;
}

//��������� �� ����
bool Food::cmp_by_type(int buff) {
	return(type == buff);
}

//���������� ��������� ��������� 
bool operator==(Food& left, Date& right) {
	return(left.date1 == right);
}

istream& operator>>(istream& is, Food& food) {
	cout << "��������: ";
	char buff[4096];
	is.ignore(9999, '\n');
	is.getline(buff, 4096);
	food.fam = new char[strlen(buff) + 1];
	strcpy(food.fam, buff);
	cout << "\n����: ";
	is >> food.cost;
	cout << "\n����������: ";
	is>> food.quant;
	cout << "\n���: ";
	is >> food.type;
	cout << "\n���: ";
	is>> food.weight;
	cout << "\n���� ������������: ";
	is>>food.date1;
	return is;
}

//���������� ��������� ����������� 
void Food::operator=(const Food& food) {
	fam = new char[strlen(food.fam) + 1];
	strcpy(fam, food.fam);
	cost=food.cost;
	quant=food.quant;
	type=food.type;
	weight=food.weight ;
	date1 = food.date1;
}
