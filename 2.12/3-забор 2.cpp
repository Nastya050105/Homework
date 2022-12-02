#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    int n;
    double с = 0;
    int num1, num2, num3;
    cin >> n;
    vector <int> a(100);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n < 3)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (a[i] + a[j] < a[k])
                {
                    break; 
                }
                double p = (a[i] + a[k] + a[j]) / 2.0;
                double s = p * (p - a[j]) * (p - a[k]) * (p - a[i]);
                if (s > с)
                {
                    с = s;
                    num1 = i + 1;
                    num2 = j + 1;
                    num3 = k + 1;
                }
            }
        }
    }

    if (с == 0)
    {
        cout << -1;
        return 0;
    }

    cout << fixed << setprecision(7) << sqrt(с) << endl;
    cout << setprecision(0) << num1 << " " << num2 << " " << num3;

    return 0;
}