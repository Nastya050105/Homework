#include <iostream>
#include <string> 
#include <fstream>

int any(char symbol, char alph[], int length) {
    int check = 0;
    for (int i = 0; i < length; i++) {
        if (symbol == alph[i]) {
            check = 1;
            break;
        }
    }
    return check;
}
int main() {
    std::ofstream MyFile("C:\\l\\output.txt");

    char alph[12] = { 'A','B','C','E','H','K','M','O','P','T','X','Y' };
    char numb[10] = { '0','1','2','3','4','5','6','7','8','9' };

    int countNumb;
    std::string nomer[40];
    std::ifstream file("C:\\l\\input.txt");
    file >> countNumb;
    for (int i = 0; std::getline(file, nomer[i]); i++);
    file.close();

    int count = 0;

    for (int j = 1; j < countNumb + 1; j++)
    {
        for (int i = 0; i < 6; i++) {
            if ((i == 0 || i == 4 || i == 5) && (any(nomer[j][i], alph, 12) == 1)) {
                count++;
            }
            else if ((i == 1 || i == 2 || i == 3) && (any(nomer[j][i], numb, 10) == 1)) {
                count++;
            }
        }

        if (count == 6) {
            MyFile << "Yes" << std::endl;
            count = 0;
        }
        else {
            MyFile << "No" << std::endl;;
            count = 0;
        }
    }
    MyFile.close();
}