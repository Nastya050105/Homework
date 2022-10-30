#include <iostream>
using namespace std;
int main()
{
	int n = 1;
	int s = 0;
	while (n < 1000)
	{
		if (n % 3 == 0 || n % 5 == 0)
		{
			s = n + s;
		}
		n++ ;
	}
	cout << s;
	return 0;
}
