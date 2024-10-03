#include <iostream>
#include <string>
#include <windows.h>

enum mounth {
	ending,
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December,

};

int main(){
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int mounth_in;
	std::cout << "Введите номер месяца: ";
	std::cin >> mounth_in;
	mounth_in = static_cast<mounth>(mounth_in);
	switch (mounth_in) {
		case 0:
			std::cout << mounth::ending << std::endl;
			break;
		case 1:
			std::cout << mounth::January << std::endl;
			break;
	}
		
	
	


	return 0;
}

