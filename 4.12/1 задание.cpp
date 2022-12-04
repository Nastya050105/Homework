#include <iostream>
#include<vector>
using namespace std;
int main()
{
	int k;
	cin >> k;
	vector <int> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	rotate(arr.begin(), arr.begin() + k, arr.end());
	cout << endl;
	for (auto p : arr)
	{
		cout << p << " ";
	}
	return 0;
}