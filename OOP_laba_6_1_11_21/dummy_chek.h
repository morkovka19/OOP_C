#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;

template <typename T>
inline void dummy_check(T& n, double left = INFINITE, double right = INFINITE) {
	char buff[4096];
	int point_count = 0;
	while (true) {
		cin.getline(buff, 4096);
		point_count = 0;
		try {
			for (int i = 0; i < strlen(buff); i++) {
				if (!(buff[i] <= '9' && buff[i] >= '0' || typeid(n) == typeid(double) && buff[i] == '.' && point_count == 0))
					throw 1;
				if (buff[i] == '.')
					point_count++;
			}
			if (typeid(n) == typeid(int))
				n = atoi(buff);
			if (typeid(n) == typeid(double))
				n = atof(buff);
			if (left == INFINITE && right == INFINITE)
				return;
			if (n >= left && n <= right)
				return;
			throw "Число вне диапозона\n";
		}

		catch (int) {
			cout << "Ошибка\n";
		}
		catch (const char  str[]) {
			cout << str;
		}
		catch (...) {
			cout << "Исключение не обработано\n";
		}
	}

};

inline void dummy_check(char*& str) {
	char buff[4096];
	while (1) {
		cin.getline(buff, 4096);
		try {
			for (int i = 0; i < strlen(buff); i++) {
				if (!(buff[i] <= 'z' && buff[i] >= 'a' || buff[i] <= 'Z' && buff[i] >= 'A' || buff[i] >= 'а' && buff[i] <= 'я' || buff[i] >= 'А' && buff[i] <= 'Я' || buff[i] == '-'))
					throw "Нельзя вводить ничего кроме букв\n";

			}
			str = new char[strlen(buff) + 1];
			strcpy_s(str, strlen(buff) + 1, buff);
			return;
		}
		catch (const char str[]) {
			cout << str;
		}
		catch (...) {
			cout << "Исключение не обработано\n";
		}
	}
}


