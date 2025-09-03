#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() {
        top = -1;
    }
    bool empty() {
        return top == -1;
    }
    bool full() {
        return top == MAX - 1;
    }
    void push(int x) {
        if (full()) {
            cout << "Stack is full!" << endl;
            return;
        }
        arr[++top] = x;
    }
    int pop() {
        if (empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top--];
    }
};

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluatePostfix(char exp[]) {
    Stack s;
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (c >= '0' && c <= '9') {
            s.push(c - '0');   
        }
        else if (isOperator(c)) {
            int b = s.pop();
            int a = s.pop();
            int ans;
            if (c == '+') ans = a + b;
            else if (c == '-') ans = a - b;
            else if (c == '*') ans = a * b;
            else {
                if (b == 0) {
                    cout << "Division by zero!" << endl;
                    return -1;
                }
                ans = a / b;
            }
            s.push(ans);
        }
        else if (c == ' ') {
            continue; 
        }
        else {
            cout << "Invalid character: " << c << endl;
            return -1;
        }
    }

    int result = s.pop();
    if (!s.empty()) {
        cout << "Wrong postfix expression!" << endl;
        return -1;
    }
    return result;
}

int main() {
    char exp[MAX];
    cout << "Enter postfix expression (single digit only): ";
    cin.getline(exp, MAX);

    int ans = evaluatePostfix(exp);
    if (ans != -1) {
        cout << "Answer = " << ans << endl;
    }
    return 0;
}
