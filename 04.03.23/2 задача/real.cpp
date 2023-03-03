#include "head.h"

students::students() {
    f = "f";
    i = "i";
    o = "o";
    group = 0;
    bal = 0;
}

students::students(string f, string i, string o, int group, double bal) {
    this->f = f;
    this->i = i;
    this->o = o;
    this->group = group;
    this->bal = bal;
}

void students::getINFO() {
    cout << "familia " << f << endl;
    cout << "imya " << i << endl;
    cout << "otchestvo " << o << endl;
    cout << "group " << group << endl;
    cout << "bal " << bal << endl << endl;
}

void bubblesort(students *mas, int size) {
    for (int i = 0; i < size; i++) {
        bool flag = true;
        for (int j = 0; j < size - (i + 1); j++) {
            if (mas[j].group > mas[j + 1].group) {
                flag = false;
                swap(mas[j], mas[j + 1]);
            }
        }
        if (flag) {
            break;
        }
    }
}