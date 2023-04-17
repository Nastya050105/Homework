#include <iostream>
#include <queue>
#include<stack>

using namespace std;

class MaxStack {
private:
    stack<int> s;
    queue<int> q1, q2;
    int max;

public:
    MaxStack() {
        max = INT_MIN;
    }

    void push(int x) {
        s.push(x);
        if (x > max) {
            max = x;
        }
        q1.push(x);
    }

    void pop() {
        int top = s.top();
        s.pop();
        if (top == max) {
            max = INT_MIN;
            while (!q1.empty()) {
                int x = q1.front();
                q1.pop();
                if (x > max) {
                    max = x;
                }
                q2.push(x);
            }
            while (!q2.empty()) {
                int x = q2.front();
                q2.pop();
                q1.push(x);
            }
        }
        else {
            q2.push(top);
            while (!q1.empty()) {
                int x = q1.front();
                q1.pop();
                q2.push(x);
            }
            while (!q2.empty()) {
                int x = q2.front();
                q2.pop();
                q1.push(x);
            }
        }
    }

    int getMax() {
        return max;
    }

    int top() {
        return s.top();
    }

    bool empty() {
        return s.empty();
    }
};

int main() {
    MaxStack ms;
    ms.push(1);
    ms.push(3);
    ms.push(5);
    ms.push(8);
    cout << "Max: " << ms.getMax() << endl;
    ms.pop();
    cout << "Max: " << ms.getMax() << endl;
    ms.pop();
    cout << "Max: " << ms.getMax() << endl;
    ms.push(10);
    cout << "Max: " << ms.getMax() << endl;
    return 0;
}