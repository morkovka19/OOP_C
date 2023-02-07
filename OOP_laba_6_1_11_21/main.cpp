#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<iomanip>
#include"common.h"
#include"Date.h"
#include"Food.h"
#include"Food1.h"
#include"Set_string.h"
#include<Windows.h>
#include"dummy_chek.h"
using namespace std;

int Food::count = 0;
int Food1::count = 0;

//ввод строки
void set_str(istream& is, char*& str) {
	char buff[4096];
	//is.ignore(9999, '\n');
	is.getline(buff, 4096);
	str = new char[strlen(buff) + 1];
	strcpy(str, buff);
}

//открытие бд
common**& open_bd(int& size) {
	int i = 0;
	fstream f("db.txt");
	if (!f.eof())
		f >> Food::count >> Food1::count;
	// cout << "wc " << Worker::count << " pc " << Personal::count << '\n';
	size = Food::count + Food1::count;
	common** common_list = new common * [size];
	for (; i < Food::count; i++) {
		common_list[i] = new Food;
		common_list[i]->file_in(f);
	}
	for (; i < Food1::count + Food::count; i++) {
		common_list[i] = new Food1;
		common_list[i]->file_in(f);
	}
	f.close();
	return common_list;
}

//меню
void menu() {
	cout << "\nМеню\n";
	cout << "1 - вывод таблицы\n";
	cout << "2 - добавление нового элемента\n";
	cout << "3 - поиск по названию\n";
	cout << "4 - фильтр по типу\n";
	cout << "5 - сортировка по уменьшению стоимости\n";
	cout << "6 - найти изделия с определенной датой выпуска\n";
	cout << "7 - поиск изделий срок годности которых истек\n";
	cout << "0 - выход\n\n";
}

//вывод таблиц
void table_out(common** common_list, const int& size) {
	int i = 0;
	if (size == 0)
	{
		cout << "База данных пустая\n";
		return;
	}
	if (Food::count == 0) {
		cout << "База изделий-1 пустая\n\n";
	}
	else {
		cout << "Изделия-1:\n";
		cout << setw(20) << "Название" << "|"
			<< setw(15) << "Цена" << "|"
			<< setw(15) << "Количество" << "|"
			<< setw(10) << "Тип" << "|"
			<< setw(15) << "Вес" << "|"
			<<setw(22)<<"Дата изготовления"<<"|"
			<< '\n';
		for (; i < Food::count; i++) {
			cout << (Food&)*common_list[i];
		}
		cout << '\n';
	}
	if (Food1::count == 0) {
		cout << "База изделий-2 пустая\n\n";
	}
	else {
		cout << "Изделия-2:\n";
		cout << setw(20) << "Название" << "|"
			<< setw(15) << "Цена" << "|"
			<< setw(15) << "Количество" << "|"
			<< setw(22) << "Дата изготовления" << "|"
			<< setw(22) << "Дата продажи" << "|"
			<< '\n';
		for (; i < size; i++) {
			cout << (Food1&)*common_list[i];
		}
	}

}

//увеличение размера массива 
void increase_size(common**& common_list, int& size, int type)
{
	int i = 0;
	if (size == 0)
		common_list = new common * [++size];
	else
	{
		common** tempworker_list = new common * [++size];
		for (; i < Food::count - 1; i++)
			tempworker_list[i] = common_list[i];
		// если 1 то увеличение для Wokrer, 0 для Personal
		i += type;
		for (; i < size + type; i++)
			tempworker_list[i] = common_list[i - type];
		delete[] common_list;
		common_list = tempworker_list;
	}
	return;
}

//добавление нового объекта 
void add_new_obj(common**& common_list, int& size) {
	int type;
	cout << "0 - Food 1 - Food1\n";
	dummy_check(type,0,1);
	if (!type) {
		Food::count++;
		cout << "Food " << Food::count << " Food1 " << Food1::count << '\n';
		increase_size(common_list, size, 1);
		common_list[Food::count - 1] = new Food;
		common_list[Food::count - 1]->set_info();
	}
	else
	{
		Food1::count++;
		increase_size(common_list, size, 0);
		common_list[size - 1] = new Food1;
		common_list[size-1]->set_info();
	}
}

//поиск по названию
void find_by_fam(common** common_list, const int& size) {
	char* fam;
	cout << "Введите название для поиска: ";
	dummy_check(fam);
	cout << '\n';
	for (int i = 0; i < size; i++) {
		if (common_list[i]->cmp_by_fam(fam)) {
			common_list[i]->print_info();
			cout << '\n';
		}
	}
	return;
}

//фильтр по типу
void filt_by_type(common** common_list, const int& size) {
	int type;
	cout << "Введите тип для фильтра: ";
	dummy_check(type,1,3);
	cout << '\n';
	for (int i = 0; i < Food::count; i++) {
		if (common_list[i]->cmp_by_type(type)) {
			common_list[i]->print_info();
			cout << '\n';
		}
	}
	return;
}

//сортировка по уменьшению цены
void sort_by_cost(common**& common_list, const int& size) {
	int i = 0;
	common* buff;
	for (; i < Food::count; i++) {
		for (int j =i; j < Food::count; j++) {
			if (common_list[i]->cmp_by_cost(common_list[j]->get_cost())) {
				buff = common_list[i];
				common_list[i] = common_list[j];
				common_list[j] = buff;
			}
		}
	}
	for (; i < size; i++) {
		for (int j = i; j <size; j++) {
			if (common_list[i]->cmp_by_cost(common_list[j]->get_cost())) {
				buff = common_list[i];
				common_list[i] = common_list[j];
				common_list[j] = buff;
			}
		}
	}
}

//поиск по дате изготовления 
void find_by_date(common** common_list, const int size) {
	int day, month, year;
	cout << "Введите дату для поиска\n";
	cout << "День: ";
	dummy_check(day, 1, 31);
	cout << "\nМесяц: ";
	dummy_check(month, 1, 12);
	cout << "\nГод: ";
	dummy_check(year, 2020, 2022);
	cout << '\n';
	Date date(day, month, year);
	int i = 0;
	for (; i < Food::count; i++) {
		if ((Food&)*common_list[i] == (date)) {
			common_list[i]->print_info();
			cout << '\n';
		}
	}
	for (; i < size; i++) {
		if ((Food1&)*common_list[i] == (date)) {
			common_list[i]->print_info();
			cout << '\n';
		}
	}
	return;
}

//закрытие бд
void close_db(common**& common_list, int& size) {
	fstream f("db.txt", ios::out);
	f << Food::count << "\n" << Food1::count << "\n";
	for (int i = 0; i < size; i++) {
		common_list[i]->file_out(f);
	}
	f.close();
}

//поиск по сроку годности 
void find_expiration_date(common** common_list, const int& size) {
	int day, month, year, k;
	int size_2 = 0;
	common** common_list_date=new common*[size_2];
	cout << "Введите параметр для срока годности в часах (36, 72, 120)\n";
	dummy_check(k,36,120);
	cout << "Введите дату: ";
	cout << "\nДень: ";
	dummy_check(day, 1, 31);
	cout << "\nМесяц: ";
	dummy_check(month, 1, 12);
	cout << "\nГод: ";
	dummy_check(year, 2020, 2022);
	Date date(day, month, year);
	int hours = date.conversion_to_hours();
	for (int i = 0; i < Food::count; i++) {
		if (common_list[i]->get_date().conversion_to_hours() - hours > k) {
			increase_size(common_list_date, size_2,0);
			common_list_date[size_2-1] = new Food((Food&)*common_list[i]);
		}
	}
	for (int i =Food::count; i < size; i++) {
		if (common_list[i]->get_date().conversion_to_hours() - hours > k) {
			increase_size(common_list_date, size_2, 0);
			common_list_date[size_2-1] = new Food1((Food1&)*common_list[i]);
		}
	}
	for (int i = 0; i < size_2; i++) 
		common_list_date[i]->print_info();
	return;
	

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	common** common_list;
	int size = 0;
	int is_stop = 0;
	common_list = open_bd(size);
	do {
		menu();
		dummy_check(is_stop);
		switch (is_stop) {
		case 1:
			table_out(common_list, size);
			break;
		case 2:
			add_new_obj(common_list, size);
			break;
		case 3:
			find_by_fam(common_list, size);
			break;
		case 4:
			filt_by_type(common_list, size);
			break;
		case 5:
			sort_by_cost(common_list, size);
			break;
		case 6:
			find_by_date(common_list, size);
			break;
		case 7:
			find_expiration_date(common_list, size);
			break;
		case 0:
			cout << Food::count << '|' << Food1::count<<'\n';
			close_db(common_list, size);
			cout << "До встречи:)\n";
			break;
		default:
			cout << "Неправильный номер\n";
			break;
		}
		//cin.clear();
		//cin.ignore(9999, '\n');
	} while (is_stop);
	return 0;
}

