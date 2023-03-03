#include <iostream>
using namespace std;

class point {
public:
	point();
	point(int a, int b, int c);
	point(point& tochka);
	void getINFO();
private:
	int x;
	int y;
	int z;

};