// HW05_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


class figure {
protected:
	int side = 0;
public:
	virtual void side_info() {
		std::cout << "Number of sides: " << side << std::endl;
	}
};

class triangle : public figure {
public:
	triangle() {
		side = 3;
	}

	};

class rectangle :public figure {
public:
	rectangle() {
		side = 4;

	}
	void side_info() {
		std::cout << "rectangle number of sides :" << side << std::endl;
	}
};


int main()
{
	figure incog;
	triangle trang;
	rectangle retrang;
	std::cout << "figure:";
	incog.side_info();
	std::cout << "triangle ";
	trang.side_info();
	retrang.side_info();
  
}

