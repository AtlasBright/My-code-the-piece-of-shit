// HW03_01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>


class Calculator {
private:
	double num1, num2;

public:
	bool setnum1(double num1) {
		
		if (num1 != 0) {
			this->num1 = num1;
			return true;
		}
		else {
			this->num1 = num1;
			return false;
		}
			

	}
	bool setnum2(double num2) {
		if (num2 != 0) {
			this->num2 = num2;
			return true;
		}
		else {
			this->num2 = num2;
			std::cout << "не верное число";
			return false;
		}
	
	}
	
	double add(){
		std::cout << "num1+num2= " << num1 + num2 << std::endl;
		return 0;
	}
	
	double multiply() {
		std::cout << "num1*num2= " << num1 * num2 << std::endl;
		return 0;
	}
	
	double subtract_1_2() {
		std::cout << "num1-num2= " << num1 - num2 << std::endl;
		return 0;
	}
	 
	double subtract_2_1() {
		std::cout << "num2-num1= " << num2 - num1 << std::endl;
		return 0;
	}

	double divide_1_2() {
		std::cout << "num1/num2= " << num1 / num2 << std::endl;
		return 0;
	}
	double divide_2_1() {
		std::cout << "num2/num1= " << num2 / num1 <<std::endl;
		return 0;
	}

};


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double num1, num2;

	Calculator calc;

	for (;;) {
		for (;;) {
			std::cout << "Введите num1: \n";
			std::cin >> num1;
			if (calc.setnum1(num1) == true) {
				break;
			}
			else {
				std::cout << "не верное число" << std::endl;

			}

		}
		for (;;) {
			std::cout << "Введите num2: \n";
			std::cin >> num2;
			if (calc.setnum2(num2) == true) {
				break;
			}
			else {
				std::cout << "не верное число" << std::endl;

			}

		}

		calc.add();
		calc.subtract_1_2();
		calc.subtract_2_1();
		calc.multiply();
		calc.divide_1_2();
		calc.divide_2_1();

		return 0;

	}

	












}
