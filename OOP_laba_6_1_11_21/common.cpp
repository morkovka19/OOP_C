#include "common.h"

//конструктор с параметрами по умолчанию 
common::common(char* fam, double cost, int quant, int day, int month, int year): cost(cost), quant(quant), date1(day, month, year){
	this->fam = new char[strlen(fam) + 1];
	strcpy(this->fam, fam);
}
//конструктор копирования
common::common(const common& common_cpy) : cost(common_cpy.cost), quant(common_cpy.quant), date1(common_cpy.date1) {
	this->fam = new char[strlen(common_cpy.fam) + 1];
	strcpy(this->fam, common_cpy.fam);
}

//сеттеры 
void common::set_fam(char* fam_new) {
	delete[] fam;
	fam = new char[strlen(fam_new) + 1];
	strcpy(fam, fam_new);
}
void common::set_cost(double cost_new) {
	cost = cost_new;
}
void common::set_date1(Date date_new) {
	date1 = date_new;
}
void common::set_quant(int quant_new) {
	quant = quant_new;
}

//геттеры
char* common::get_fam() {
	char* buff = new char[strlen(fam) + 1];
	strcpy(buff, fam);
	return buff;
}
double common::get_cost() {
	double buff = cost;
	return buff;
}
Date common::get_date() {
	Date buff(date1);
	return buff;
}
int common::get_quant() {
	int buff = quant;
	return buff;
}

//сравнение по названию 
bool common::cmp_by_fam(char buff[4096]) {
	return(!strcmp(fam, buff));
}

//сравнение по цене 
bool common::cmp_by_cost(double buff) {
	return(buff > cost);
}
