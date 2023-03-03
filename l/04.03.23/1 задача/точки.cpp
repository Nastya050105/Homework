#include "real.cpp"

int main()
{
	point firstpoint;
	point secondpoint(1, 2, 3);
	firstpoint.getINFO();
	secondpoint.getINFO();
	point thirdpoint(secondpoint);
	thirdpoint.getINFO();
}

