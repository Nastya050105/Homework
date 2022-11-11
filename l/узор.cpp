#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    int len, wg, cnt = 0;
    bool simpatihno = true;
    string string[4], ts;
    ifstream file("C:\\l\\plitka.txt");
    for (int i = 0; getline(file, ts); i++) {
        string[i] = ts;
    }
    file.close();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (string[i][j] == string[i][j + 1] && string[i + 1][j] == string[i + 1][j + 1] && string[i][j] == string[i + 1][j + 1])
            {
                simpatihno = false;
            }
            cout << string[i][j] << string[i][j + 1] << string[i + 1][j] << string[i + 1][j + 1] << endl;
        }

    }
    ofstream out;
    out.open("C:\\l\\outputPlitka.txt");
    if (simpatihno)
    {
        cout << "yes";
        out << "yes";
    }
    else {
        cout << "no";
        out << "no";
    }
    out.close();
}