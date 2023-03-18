#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

// Реализовать queue с использованием двух Stackов
class Queue
{
    stack<int> s1, s2;

public:
    // Добавляем элемент в queue
    void enqueue(int data)
    {
        // Перемещаем все элементы из первого stack во второй стек
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // помещаем элемент в первый stack
        s1.push(data);

        // Перемещаем все элементы обратно в первый стек из второго stack
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Удалить элемент из queue
    int dequeue()
    {
        // если первый stack пуст
        if (s1.empty())
        {
            cout << "Underflow!!";
            exit(0);
        }

        // вернуть верхний элемент из первого stack
        int top = s1.top();
        s1.pop();
        return top;
    }
};

int main()
{
    int keys[] = { 1, 2, 3, 4, 5 };
    Queue q;

    // вставляем вышеуказанные ключи
    for (int key : keys) {
        q.enqueue(key);
    }

    cout << q.dequeue() << endl;    // напечатать 1
    cout << q.dequeue() << endl;    // напечатать 2

    return 0;
}