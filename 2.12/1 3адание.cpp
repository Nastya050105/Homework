#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


int main()
{
    int num, answ = 0, counter = 0;
    string string, ts, firstStr, secStr, thirdStr;
    ifstream file("C:\\l\\skittles.txt");
    file >> num >> answ;
    while (getline(file, ts)) {
        string += ts;
    }
    file.close();
    vector <int> arr(num);
    for (int i = 0; i < num; i++)
    {
        i >> arr[i];
    }
    for (int i = 0; i < 10; i++)
    {
        answ += arr[counter];
        if (arr[counter] == 10)
        {
            answ += arr[counter + 1];
            answ += arr[counter + 2];
            counter++;
            continue;
        }
        answ += arr[counter + 1];
        if (arr[counter] + arr[counter + 1] == 10)
        {
            answ += arr[counter + 2];
            counter += 2;
            continue;
        }
        counter += 2;
    }
    ofstream out;
    out.open("C:\\l\\outputSkittles.txt");
    out << answ;
    out.close();
    cout << answ << endl;
    return 0;
}