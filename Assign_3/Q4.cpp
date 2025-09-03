#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
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
    void push(char c) {
        if (full()) {
            cout << "Stack full!" << endl;
            return;
        }
        arr[++top] = c;
    }
    char pop() {
        if (empty()) {
            cout << "Stack empty!" << endl;
            return '\0';
        }
        return arr[top--];
    }
    char peek() {
        if (empty()) return '\0';
        return arr[top];
    }
};

int prec(char op) {
    if (op == '+' || op == '-') 
    return 1;
    if (op == '*' || op == '/') 
    return 2;
    if (op == '^') 
    return 3;
    return 0;
}

bool isOp(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    int i = 0, k = 0;
    char c;

    while ((c = infix[i]) != '\0') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.peek() != '(') {
                postfix[k++] = s.pop();
            }
            if (!s.empty() && s.peek() == '(') {
                s.pop();
            }
            else {
                cout << "Error: brackets mismatch" << endl;
                postfix[0] = '\0';
                return;
            }
        }
        else if (isOp(c)) {
            while (!s.empty() && prec(s.peek()) >= prec(c)) {
                if (c == '^' && s.peek() == '^') break; // right assoc
                postfix[k++] = s.pop();
            }
            s.push(c);
        }
        else if (c == ' ') {
        }
        else {
            cout << "Invalid char: " << c << endl;
            postfix[0] = '\0';
            return;
        }
        i++;
    }

    while (!s.empty()) {
        if (s.peek() == '(') {
            cout << "Error: brackets mismatch" << endl;
            postfix[0] = '\0';
            return;
        }
        postfix[k++] = s.pop();
    }
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    cout << "Enter infix expression: ";
    cin.getline(infix,MAX);

    infixToPostfix(infix, postfix);

    if (postfix[0] != '\0')
        cout << "Postfix: " << postfix << endl;

    return 0;
}
