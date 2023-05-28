#include <iostream>
#include <string>
#include <vector>

enum State
{
    LOWERCASE,
    UPPERCASE,
    FIRST_CHAR
};

int buttonNumForChar(char c, const std::vector<int>& charToButtonNum) // Возвращаем номер кнопки для данного символа
{
    return charToButtonNum[static_cast<int>(c)]; // static_cast<int>(c) - приведение типа char к типу int, получаем код символа
}

int pressCountForChar(char c, const std::vector<int>& charToPressCount) // Возвращаем количество нажатий для данного символа
{
    return charToPressCount[static_cast<int>(c)]; // static_cast<int>(c) - приведение типа char к типу int, получаем код символа
}

bool isValidPunctuation(char c) // Проверяем, является ли символ знаком препинания
{
    return c == '.' || c == '!' || c == '?'; // Если да, то возвращаем true, иначе false
}

int main()
{
    std::vector<int> charToPressCount(128, -1);
    std::vector<int> charToButtonNum(128, -1);

    // Инициализируем переменные
    const int LOWER_BOUND = 1; // стейт нижнего регистра
    const int UPPER_BOUND = 2; // стейт верхнего регистра
    const int FIRST_CHAR = 3; // стейт первого символа
    int state = FIRST_CHAR;
    int lastButton = 0;
    int count = 0;

    // Читаем раскладку клавиатуры
    for (int lineNum = 1; lineNum <= 9; lineNum++)
    {
        std::string line;
        std::cin >> line;
        for (char c : line)
        {
            int charCode = static_cast<int>(c);
            charToPressCount[charCode] = line.find(c) + 1;
            charToButtonNum[charCode] = lineNum;
        }
    }

    // Читаем входную строку
    std::string inputString;
    std::cin.ignore(); // Игнорируем предыдущий символ перевода строки
    std::getline(std::cin, inputString);

    // Перебираем все символы входной строки
    for (char currChar : inputString)
    {
        if (currChar == ' ')
        {
            count++;
            lastButton = 0;
            continue;
        }
        if (isValidPunctuation(currChar)) // Проверяем, является ли символ знаком препинания
        {
            if (buttonNumForChar(currChar, charToButtonNum) == lastButton) // Проверяем, была ли нажата предыдущая кнопка
            {
                count++;
            }
            count += pressCountForChar(currChar, charToPressCount); 
            if (state == LOWERCASE) 
            {
                state = FIRST_CHAR; 
            }
            lastButton = buttonNumForChar(currChar, charToButtonNum); 
        }
        else if (islower(currChar)) 
        {
            if (buttonNumForChar(currChar, charToButtonNum) == lastButton) // Проверяем, была ли нажата предыдущая кнопка
            {
                count++; // Если да, то прибавляем 1 к количеству нажатий
            }
            count += pressCountForChar(currChar, charToPressCount); // Прибавляем количество нажатий для данного символа
            if (state == UPPERCASE || state == FIRST_CHAR) 
            {
                count++; // Если да, то прибавляем 1 к количеству нажатий
                state = LOWERCASE; // Переходим в состояние LOWERCASE
            }
            lastButton = buttonNumForChar(currChar, charToButtonNum); // Запоминаем номер кнопки, на которой был нажат символ
        }
        else if (isupper(currChar)) // Проверяем, является ли символ заглавной буквой
        {
            if (buttonNumForChar(tolower(currChar), charToButtonNum) == lastButton) 
            {
                count++; 
            }
            count += pressCountForChar(tolower(currChar), charToPressCount);
            if (state == LOWERCASE)
            {
                count++; 
                state = UPPERCASE; 
            }
            else if (state == FIRST_CHAR) 
            {
                state = LOWERCASE;
            }
            lastButton = buttonNumForChar(tolower(currChar), charToButtonNum); 
        }
    }

    std::cout << count;
    return 0;
}