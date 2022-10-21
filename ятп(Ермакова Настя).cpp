(Задание 2)
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, k;
    long res = 0;

    cout << "Вывод n: ";
    cin >> n;

    cout << "Вывод k: ";
    cin >> k;

    for (int i = 1; i < n + 1; i++)
    {
        res += pow(i, k);
    }

    cout << "" << endl;
    cout << "Итог: " << res << endl;
}

(Задание 3)
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cin >> n;
    cout << endl;
    if ((n / 10) > (n % 10))
    {
        cout << n / 10 << " : большая цифра " << endl;
        cout << n % 10 << " : меньшая цифра " << endl;
    }
    else {
        if ((n / 10) < (n % 10))
        {
            cout << n % 10 << " : большая цифра " << endl;
            cout << n / 10 << " : меньшая цифра " << endl;
        }
        else
        {
            cout << "цифры равны\n";
        }
    }
    cout << endl;
    return 0;
}

(Задание 5)
 #<iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    int a, n, k = 1, l;
    cout << "Возводимое в степень число: ";
    cin >> a;
    cout << endl << "Стень числа: ";
    cin >> n;
    for (l = 0; l < n; l++)
        k *= a;
    cout << endl << " Результат : " << n << " ^ " << a << " = " << k << endl;
    return 0;
}

(Задание 6)
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    cin >> n;
    switch (n) {
    case 1:
        cout << "Понедельник";
        break;
    case 2:
        cout << "Вторник";
        break;
    case 3:
        cout << "Среда";
        break;
    case 4:
        cout << "Четверг";
        break;
    case 5:
        cout << "Пятница";
        break;
    case 6:
        cout << "Суббота";
        break;
    case 7:
        cout << "Воскресенье";
        break;
    default:
        cout << "ВЫ ЧТО-ТО ПУТАЕТЕ, ТАКОГО ДНЯ НЕДЕЛИ НЕТ :) ВАМ НЕОБХОДИМО ПОВТОРИТЬ ДНИ НЕДЕЛИ!!! ";
    }
    return 0;
}