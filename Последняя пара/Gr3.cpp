#include <iostream>
#include <fstream>
using namespace std;

struct Matr
{
    int countCity;
    int countElectr;
    int* electr;
    int** matrix;

    Matr(ifstream& file) {
        file >> countCity >> countElectr;
        electr = new int[countElectr];
        matrix = new int* [countCity];
        for (int i = 0; i < countCity; i++)
            matrix[i] = new int[countCity];

        for (int i = 0; i < countElectr; i++)
            file >> electr[i];

        for (int i = 0; i < countCity; i++) {
            for (int j = 0; j < countCity; j++)
                file >> matrix[i][j];
        }
    }

    void opti() {
        bool* been = new bool[countCity];
        int** minMoney = new int* [countElectr];
        for (int i = 0; i < countElectr; i++) {
            minMoney[i] = new int[countCity];
        }
        int* metka = new int[countCity];
        int startPoint;

        for (int i = 0; i < countElectr; i++) {

            for (int j = 0; j < countCity; j++) {
                been[j] = true;
                metka[j] = INT_MAX;
            }
            startPoint = electr[i] - 1;
            metka[startPoint] = 0;
            int newPoint;
            int minMetka = INT_MAX;

            for (int j = 0; j < countCity; j++) {
                if (j != startPoint) {
                    metka[j] = matrix[startPoint][j];
                }
            }
            bool flag = true;
            while (flag) {
                for (int j = 0; j < countCity; j++) {
                    if (matrix[startPoint][j]) {
                        if (matrix[startPoint][j] < minMetka) {
                            if (been[j]) {
                                minMetka = matrix[startPoint][j];
                                newPoint = j;
                            }
                        }
                    }
                }

                been[newPoint] = false;

                for (int j = 0; j < countCity; j++) {
                    if (been[j]) {
                        metka[j] = min(metka[j], metka[newPoint] + matrix[newPoint][j]);
                    }
                }

                flag = false;
                for (int j = 0; j < countCity; j++) {
                    if (been[j]) {
                        flag = true;
                        newPoint = j;
                        break;
                    }
                }

            }

            for (int j = 0; j < countCity; j++)
                minMoney[i][j] = metka[j];
        }

        int summa = 0;
        int thMin = INT_MAX;

        bool flag1 = true;
        for (int i = 0; i < countCity; i++) {
            for (int z = 0; z < countElectr; z++) {
                if (i == (electr[z] - 1))
                    flag1 = false;
            }
            if (flag1) {
                for (int j = 0; j < countElectr; j++) {
                    thMin = min(thMin, minMoney[j][i]);
                }
                summa += thMin;
                thMin = INT_MAX;
            }
            flag1 = true;
        }

        cout << summa;
    }

};

int main()
{
    ifstream in("input.txt");

    Matr a(in);
    a.opti();
}
