#include <iostream>
#include <string>
#include <fstream>

std::string reverse_string(std::string line) {
    std::string finishLine = "";

    for (int i = line.length(); i > -1; i--) {
        finishLine += line[i];
    }

    return finishLine;
}

std::string PerevodSysSchisl(int Number, int OsnSys) {

    std::string NumbInSys = "";
    while (Number > 0) {
        std::string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        if (Number % OsnSys < 10) {
            NumbInSys += std::to_string(Number % OsnSys);
            Number /= OsnSys;
        }
        else {
            NumbInSys += alph[(Number % OsnSys) - 10];
            Number /= OsnSys;
        }

    }

    return reverse_string(NumbInSys);
}
void makeOutputFile(std::string clearString) {

}

int main() {
    std::string fileLocation;
    std::cin >> fileLocation;

    std::string date;
    std::ifstream file(fileLocation);

    std::string day = "";
    std::string month = "";
    std::string year = "";
    int countSlash = 0;

    if (file.is_open()) {
        ;
        while (getline(file, date)) {
            int dateLen = date.length();
            for (int i = 0; i < dateLen; i++) {
                if (date[i] != '/') {
                    if (countSlash == 0) {
                        day += date[i];
                    }
                    if (countSlash == 1) {
                        month += date[i];
                    }
                    if (countSlash == 2) {
                        year += date[i];
                    }
                }
                else if (date[i] == '/') {
                    countSlash++;
                }
            }
            int OsnSysSchisl = std::stoi(day) + 1;
            std::string FinishString = "";
            FinishString = PerevodSysSchisl(std::stoi(day), OsnSysSchisl) + "/" + PerevodSysSchisl(std::stoi(month), OsnSysSchisl) + "/" + PerevodSysSchisl(std::stoi(year), OsnSysSchisl);

            std::ofstream myFile("C:\\l\\input.txt");

            myFile << FinishString;

            myFile.close();
        }
    }
    file.close();

    return 0;
}