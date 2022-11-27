#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
    using namespace std;

    char stack[30];
    int istack = 0;
    int maxstack = 0;
    string str;
    int istr = 0;
    setlocale(0, "");
    cout << "Введите скобочную посл-ть: " << endl;
    cin >> str;

    while (istr < str.length()) {
        setlocale(0, "");
        if (str[istr] == '(') {
            stack[istack] = '(';
            ++istack;

            if (maxstack <= istack) {
                maxstack = istack;
            }
        }
        else if (str[istr] == ')') {
            if (stack[istack - 1] == '(') {
                istack--;
            }
            else {
                cout << "Ваша посл-ть не скобочная" << endl;
                return 0;
            }
        }
        ++istr;
    }
    if (istack != 0) {
        cout << "Ваша посл-ть не скобочная" << endl;
    }
    else {
        cout << "Ваша посл-ть скобочная!" << endl;
    }
    if (maxstack != 0) {
        cout << "максимальная глубина: " << maxstack << endl;
    }
    else {
        cout << "Скобок не найдено, глубина = 0" << endl;
    }
}