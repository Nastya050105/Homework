#include <iostream>
#include <string>

using namespace std;

int main(){
    int boy, girl;
    string i = "";
    cin >> boy >> girl;

    while (boy > 0 || girl > 0)
    {
        if (boy > 0)
        {
            i = i + 'B';
            boy--;
        }
        if (girl > 0)
        {
            i = i + 'G';
            girl--;
        }
        if (girl > 0)
        {
            i = i + 'G';
            girl --;
        }
    }
    cout << i;
    return 0;
}