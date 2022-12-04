#include <iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int i, n;
	vector <int> a = { 1, 2, 3, 6 };

	for (i = n = 0; i < a.size(); i++)
	{
		if (n + 1 < a[i])
		{
			break;
		}
		n += a[i];
	}

	printf("Число = %d\n", n + 1);

	return 0;
}