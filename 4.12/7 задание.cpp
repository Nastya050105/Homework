#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	long long a = 0, b = 0;
	long long x, q, p, r;
	cin >> r;
	x = r;
	q = r * r;

	while (a < r)
	{
		p = q - a * a;
		while (x * x >= p && x >= 0)--x;
		b += (x + 1);
		a++;
	}

	b *= 4;
	cout << b;

	return 0;
}