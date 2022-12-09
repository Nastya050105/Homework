#include<iostream>

using namespace std;

int main()
{
    int N, K;
    int X = 1,Xm  = 1;
    cin >> N >> K;
    for (int i = 0; i < N + 1; i++)
    {
        if (Xm % N == K && Xm - K > 0)
        {
            Xm /= N;
            Xm *= N - 1;
            continue;
        }
        else
        {
            X++;
            Xm = X;
            i = 0;
        }
    }
    cout << X;

    return 0;
}