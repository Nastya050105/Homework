#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    int len, wg;
    bool tablo = true;
    string string = "", ts, rgb, number;
    ifstream file("C:\\l\\tablo.txt");
    file >> len >> wg;
    while (getline(file, ts)) {
        string += ts;
    }
    file.close();
    int j = ((len * wg) * 2) - 1;
    for (int i = 0; i < (len * wg) * 2; i++)
    {
        if (string[i] == ' ') string.erase(i, 1);
    }
    for (int i = 0; i < len * wg; i++, j--)
    {
        rgb += string[i];
        number = string[j] + number;
    }
    for (int i = 0; i < len * wg; i++)
    {
        if (rgb[i] == 'G' && (number[i] == '0' || number[i] == '1' || number[i] == '4' || number[i] == '5')) tablo = false;
        if (rgb[i] == 'R' && (number[i] == '0' || number[i] == '1' || number[i] == '2' || number[i] == '3')) tablo = false;
        if (rgb[i] == 'B' && (number[i] == '0' || number[i] == '2' || number[i] == '4' || number[i] == '6')) tablo = false;
    }

    ofstream out;
    out.open("C:\\l\\outputTablo.txt");
    if (tablo)
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