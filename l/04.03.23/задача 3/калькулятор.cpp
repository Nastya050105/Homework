#include <iostream>

using namespace std;

int main() {
    int a = 0;
    int b = 0;
    char operation;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    cout << "Enter operation: ";
    cin >> operation;

    switch (operation) {
    case '-':
        cout << "a - b = " << a - b << '\n';
        break;
    case '+':
        cout << "a + b = " << a + b << '\n';
        break;
    case '*':
        cout << "a * b = " << a * b << '\n';
        break;
    case '/':
        cout << "a / b = " << a / b << '\n';
        break;
    default:
        cout << "Error\n";
    }
    return 0;
}