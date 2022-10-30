#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int minuts, chas;
	cin >> minuts >> chas;
	cout << abs((chas % 12 * 30) - (minuts * 6));
	return 0;
}