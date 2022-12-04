#include <iostream>

using namespace std;

int nod(int a, int b)
{
	while (a > 0 && b > 0)
		if (a > b)
		{
			a = a % b;
		}
		else
		{
			b = b % a;
		}

	return a + b;
}

int main() {
	int m;
	int n;
	cin >> m >> n;
	--n; --m;
	if (m == n)
	{
		printf("%d", n);
		return 0;
	}

	int pre_res = nod(m, n);
	int res = n + m - pre_res;
	printf("%d", res);

	return 0;
}
