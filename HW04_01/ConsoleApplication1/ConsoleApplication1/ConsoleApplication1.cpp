// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>



class adress_transfer {
private:
	int houseNum;
	int apartNum;
	std::string adres_1;
	std::string adres_2;


public:
	adress_transfer(std::ifstream& niga) {
		niga >> adres_1;
		niga >> adres_2;
		niga >> houseNum;
		niga >> apartNum;
	}

	adress_transfer() {
		houseNum = apartNum = 0;
		adres_1=adres_2="";
		
	};

	void readadressOut(std::ofstream& niga) {
		niga << adres_1;
		niga << ". ";
		niga << adres_2;
		niga << ". ";
		niga << houseNum;
		niga << ". ";
		niga << apartNum;
		niga << ". " << '\n';

	};
};


int main(){
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	int count;
	std::ifstream readIn("in.txt");
	if (!readIn) {
		std::cout << "Ошибка: файл 'in.txt' не удалось открыть!" << std::endl;
	}
	readIn >> count;

	adress_transfer* adresspool = new adress_transfer[count];
	for (int i = 0; i < count; i++) {
	adresspool[i]= adress_transfer(readIn);
	}

	
	std::ofstream writeOut("out.txt");
	if (!writeOut) {
		std::cout << "Ошибка: файл 'out.txt' не удалось открыть!" << std::endl;
	}
	writeOut << count << '\n';
	for (int i = count - 1; i >= 0; i--) {
		adresspool[i].readadressOut(writeOut);
	}
	delete[] adresspool;
	return 0;
}
