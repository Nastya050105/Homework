#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include<string>

using namespace std;

// Функция для разбиения строки на числа
vector<int> split(string s, char delimiter) {
    vector<int> result;
    string number = "";
    for (char c : s) {
        if (c == delimiter) {
            result.push_back(stoi(number));
            number = "";
        }
        else {
            number += c;
        }
    }
    result.push_back(stoi(number));
    return result;
}

// Функция для подсчета количества различных матчей
long long countMatches(int n, vector<vector<int>> scores) {
    map<vector<int>, int> matchCounts;
    for (int i = 0; i < n; i++) {
        matchCounts[scores[i]]++;
    }
    long long result = 1;
    for (auto it : matchCounts) {
        int count = it.second;
        for (int i = 2; i <= count; i++) {
            result *= i;
        }
    }
    return result;
}

int main() {
    ifstream inputFile("INPUT.TXT");
    ofstream outputFile("OUTPUT.TXT");

    int n;
    inputFile >> n;

    vector<vector<int>> scores;
    for (int i = 0; i < n; i++) {
        string line;
        inputFile >> line;
        vector<int> score = split(line, ':');
        scores.push_back(score);
    }

    long long result = countMatches(n, scores);
    outputFile << result;

    inputFile.close();
    outputFile.close();

    return 0;
}