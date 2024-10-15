// hw03_02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


class Counter {
private:
	int num;
public:
	Counter() {
		num = 1;
	};
	Counter(int num) {
		this->num = num;
	}


	void nextcount() {
		num++;
	}
	void pastucont() {
		num--;
	}
	void equalscount() {
		std::cout << num << std::endl;
	}

};

int main() {
	char ch;
	int nu;
	Counter co;
	std::cout << "Do you want to specify the initial value of the counter? Enter y/n \n";
	std::cin >> ch;

	if (ch == 'y') {
		std::cout << "Enter the initial value of the counter: ";
		std::cin >> nu;
		co = Counter(nu);
	}
	else if (ch == 'n') {
		co = Counter();
	}
	else {
		std::cout << "Invalid input";
	}

	for (;;) {
		std::cout << "enter a character ('+', '-', '=' or 'x'): ";
		std::cin >> ch;
		switch (ch) {
		case('+'):
			co.nextcount();
			break;
		case('-'):
			co.pastucont();
			break;
		case('='):
			co.equalscount();
			break;
		}
		if (ch == 'x') {
			std::cout << "Goodbye!";
			break;
		}
		else if (ch != '+' && ch != '-' && ch != '=' && ch != 'x') {
			std::cout << "Invalid input \n";
		}

	}



	return 0;
}


