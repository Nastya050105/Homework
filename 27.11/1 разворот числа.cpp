#include <iostream>
using namespace std;
int main()
{
    long long unsigned int number, result = 0;
    cin >> number;
    while (number > 0)
    {
        result = 10 * result + (number % 10);
        number = number  / 10;
    }
    cout << result << endl;
    retuкт 0;
}