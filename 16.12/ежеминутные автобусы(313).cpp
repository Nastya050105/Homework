#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	
	int n, l, maxx = 0;

	cin >> n;

	int* a = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				l = j - i;
				break;
			}
		}
		if (l > maxx)
		{
			maxx = l;
		}
	}
	cout<< maxx << endl;

}