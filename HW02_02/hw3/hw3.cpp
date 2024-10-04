#include <iostream>
#include <string>
#include <windows.h>

struct bankAcc {
	int accNum;
	float balance;
	std::string accName;

};

void accedit(bankAcc examp, float i) {
	examp.balance = i;
	std::cout << "Ваш счёт : " << examp.accNum << std::endl;
	std::cout << "Имя владельца: " << examp.accName << std::endl;
	std::cout << "Баланс: " << examp.balance;
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int i, num;
	bankAcc Andre;
	Andre.accNum = 123456789;

	for (;;) {
		std::cout << "Введите номер счёта: \n";
		std::cin >> num;
		if (Andre.accNum == num) {
			std::cout << "Введите имя владельца: \n";
			std::cin >> Andre.accName;
			std::cout << "Введите баланс: \n";
			std::cin >> Andre.balance;
			std::cout << "Введите новый баланс: \n";
			std::cin >> i;
			accedit(Andre, i);
			break;
		}
		else
			std::cout << "не известный номер \n";
	}
	return 0;
}