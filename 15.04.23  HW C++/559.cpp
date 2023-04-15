#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    double diameter, radius, area, left, right, middle, midArea, theta, pi;
    pi = 3.14159265358979323846; 
    cin >> diameter >> radius >> n;

    for (int i = 1; i < n; i++)
    {
        area = i * (pi * radius * radius + 2 * radius * diameter) / n;
        left = 0;
        right = 2 * radius + diameter;
        for (int j = 0; j < 64; j++)
        {
            middle = (left + right) / 2;
            if (middle < radius) 
            {
                theta = 2 * acos((radius - middle) / radius);
                midArea = radius * radius / 2 * (theta - sin(theta));
            }
            else 
            {
                if (middle <= radius + diameter)
                {
                    midArea = pi * radius * radius / 2 + (middle - radius) * 2 * radius; 
                }
                else
                {
                    theta = 2 * acos((radius - (2 * radius + diameter - middle)) / radius); 
                    midArea = (pi * radius * radius + 2 * radius * diameter) - radius * radius / 2 * (theta - sin(theta)); 
                }
            }

            if (midArea > area) 
            {
                right = middle;
            }
            else 
            {
                left = middle;
            }
        }
        cout << fixed << setprecision(6);
        cout << (left + right) / 2 << endl;
    }
}