#include <iostream>

int main() {
    int arrayLength;
    std::cin >> arrayLength;

    int *array;
    array = new int [arrayLength];

    int maximumNumb = 0;
    for (int i = 0 ; i < arrayLength; i++) {
        std::cin >> array[i];
        maximumNumb = std::max(maximumNumb,array[i]);
    }

    std::cout << maximumNumb;

    return 0;
}