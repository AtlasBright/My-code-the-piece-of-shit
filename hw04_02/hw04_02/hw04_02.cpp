
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>




class adress_pool {
private:
	int houseNum;
	int apartNum;
	std::string cityName;
	std::string streetName;

public:
	adress_pool(std::ifstream& niga) {
		niga >> cityName;
		niga >> streetName;
		niga >> houseNum;
		niga >> apartNum;

	}
	adress_pool() {
		houseNum = apartNum = 0;
		cityName = streetName = "";

	}

	void adressWriter(std::ofstream& niga) {
		niga << cityName;
		niga << ", ";
		niga << streetName;
		niga << ", ";
		niga << houseNum;
		niga << ", ";
		niga << apartNum;
		niga << "." << '\n';
	}

	std::string city_getter(std::string city) {
		city = cityName;
		return city;
	}

};
void sorted(adress_pool addr[], int size) {
	std::string city;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (addr[j].city_getter(city) > addr[j + 1].city_getter(city)) {
				std::swap(addr[j], addr[j + 1]);
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int count;
	std::ifstream readIn("in.txt");
	if (!readIn) {
		std::cout << "Ошибка: файл 'in.txt' не удалось открыть!" << std::endl;
	}
	readIn >> count;

	adress_pool* adress = new adress_pool [count];
	
	for (int i = 0; i < count; i++) {
		adress[i] = adress_pool (readIn);
	}

	std::ofstream writeOut("out.txt");
	if (!writeOut) {
		std::cout << "Ошибка: файл 'out.txt' не удалось открыть!" << std::endl;
	}
	

	writeOut << count << '\n';
	sorted(adress, count);
	for (int i = 0; i < count; i++) {
		adress[i].adressWriter(writeOut);
	}
	delete[] adress;
	readIn.close();
	writeOut.close();
	return 0;
}