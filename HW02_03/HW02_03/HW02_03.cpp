// HW02_03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>


struct adres {
	std::string sity;
	std::string street;
	std::string houseNum;
	int flatNum;
	int adreesIndex;
};

void prAdres(std::vector <adres> ex) {
	for (int i = 0; i < 2; ++i) {
		std::cout <<"Город: " << ex[i].sity << std::endl;
		std::cout <<"Улица: " << ex[i].street << std::endl;
		std::cout << "Дом: " << ex[i].houseNum << std::endl;
		std::cout << "Квртира: " << ex[i].flatNum << std::endl;
		std::cout << "Индекс: " <<ex[i].adreesIndex << std::endl;
		std::cout << " " << std::endl;
	}
}



int main () {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	std::vector <adres> adrespool;
	adrespool.push_back({ "Москва","Арбат","12A", 19, 123456 });
	adrespool.push_back({ "Санкт-Петербург", "ул.Пушкина", "Колотушкина", 228, 3371488 });
	prAdres(adrespool);


		return 0;
}