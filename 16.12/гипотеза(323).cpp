#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main()
{
	int n, c = 0;
	vector <int> a;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (i % j == 0)
				c += 1;
		}
		if (c == 2)
			a.push_back(i);
		c = 0;
	}

	int min1 = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] + a[j] == n)
			{
				min1 = min(a[i], min1);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] == min1 && a[i] + a[j] == n)
			{
				cout << a[i] << " " << a[j];
			}

		}
	}
	
	return 0;
}