#include "head.h"

point::point() {//конструктор поумолчанию
	x = y = z = 0;
	
}

point::point(int a, int b, int c) {//конструктор инициализации
	this->x = a;
	this->y = b;
	this->z = c;
}

point::point(point& tochka) {//конструктор копирования
	this->x = tochka.x;
	this->y = tochka.y;
	this->z = tochka.z;
}

void point::getINFO() {
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	cout << "z=" << z << endl;
}