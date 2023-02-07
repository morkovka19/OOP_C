#include "Food.h"

//конструктор с параметрами по умолчанию
Food::Food(char* fam, double cost, int quant, int day , int month , int year, int type, double weight):common(fam, cost, quant, day, month, year), type(type), weight(weight){}
//конструктор копирования 
Food::Food(const Food& food_cpy) {
	fam = new char[strlen(food_cpy.fam) + 1];
	strcpy(fam, food_cpy.fam);
	cost = food_cpy.cost;
	quant = food_cpy.quant;
	date1 = food_cpy.date1;
	type = food_cpy.type;
	weight = food_cpy.weight;

}

//деструктор 
Food::~Food() {
	delete[] fam;
}

//сеттеры
void Food::set_type(int type_new) {
	type = type_new;
}
void Food::set_weight(double weight_new) {
	weight = weight_new;
}

//геттеры
int Food::get_type() {
	int buff = type;
	return buff;
}
double Food::get_weight() {
	double buff = weight;
	return buff;
}

//ввод нового объекта 
void Food::set_info() {
	cout << "Название: ";
	dummy_check(fam);
	cout << "\nЦена: ";
	dummy_check(cost);
	cout << "\nКоличество: ";
	dummy_check(quant);
	cout << "\nТип: ";
	dummy_check(type,1,3);
	cout << "\nВес: ";
	dummy_check(weight);
	cout << "\nДата изготовления: ";
	date1.set_info();
}

//вывод информации об объекте 
void Food::print_info() {
	cout << "Название: " << fam;
	cout << "\nЦена: " << cost;
	cout << "\nКоличество: " << quant;
	cout << "\nТип: " << type;
	cout << "\nВес: " << weight;
	cout << "\nДата изготовления: ";
	date1.print_info();
}

//форматированный вывод
void  Food::table_out() {
	cout << setw(20) << fam << "|";
	cout << setw(15) << cost << "|";
	cout << setw(15) << quant << "|";
	cout << setw(10) << type << "|";
	cout << setw(15) << weight << "|";
	date1.table_out();
	cout << '\n';
}

//работа с потоками 
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

//перегрузка оператора вывода 
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

//сравнение по типу
bool Food::cmp_by_type(int buff) {
	return(type == buff);
}

//перегрузка оператора сравнения 
bool operator==(Food& left, Date& right) {
	return(left.date1 == right);
}

istream& operator>>(istream& is, Food& food) {
	cout << "Название: ";
	char buff[4096];
	is.ignore(9999, '\n');
	is.getline(buff, 4096);
	food.fam = new char[strlen(buff) + 1];
	strcpy(food.fam, buff);
	cout << "\nЦена: ";
	is >> food.cost;
	cout << "\nКоличество: ";
	is>> food.quant;
	cout << "\nТип: ";
	is >> food.type;
	cout << "\nВес: ";
	is>> food.weight;
	cout << "\nДата изготовления: ";
	is>>food.date1;
	return is;
}

//перегрузка оператора присваиваия 
void Food::operator=(const Food& food) {
	fam = new char[strlen(food.fam) + 1];
	strcpy(fam, food.fam);
	cost=food.cost;
	quant=food.quant;
	type=food.type;
	weight=food.weight ;
	date1 = food.date1;
}
