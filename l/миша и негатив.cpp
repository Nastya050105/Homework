#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    int len, wg, cnt = 0;
    string string, ts, firstStr, secStr, thirdStr;
    ifstream file("C:\\l\\misha.txt");
    file >> len >> wg;
    while (getline(file, ts)) {
        string += ts;
    }
    file.close();
    int j = ((len * wg) * 2) - 1;
    for (int i = 0; i < len * wg; i++, j--)
    {
        firstStr += string[i];
        secStr = string[j] + secStr;
    }
    for (int i = 0; i < firstStr.length(); i++)
    {
        if (firstStr[i] == 'B') thirdStr += "W";
        if (firstStr[i] == 'W') thirdStr += "B";
        if (secStr[i] != thirdStr[i]) cnt++;
    }
    ofstream out;
    out.open("C:\\l\\outputMisha.txt");
    out << cnt;
    out.close();
    cout << cnt;
}
