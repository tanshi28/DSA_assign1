#include <iostream>
using namespace std;
#define MAX 100
class Stack{
    char arr[MAX];
    int top;
public:
    Stack(){
        top=-1;
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==MAX-1;
    }
    void push(char ch){
        if(isFull()){
            cout<<"Stack Overflow!"<<endl;
            return;
        }
        arr[++top] = ch;
    }

    char pop(){
        if(isEmpty()){
            cout<<"Stack Underflow!"<<endl;
            return '\0';
        }
        return arr[top--];
    }

    char peek(){
        if(isEmpty())
            return '\0';
        return arr[top];
    }
};

bool isMatching(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '{' && right == '}') ||
           (left == '[' && right == ']');
}

bool Parentheses(const char expr[]) {
    Stack s;
    int i = 0;

    while (expr[i] != '\0') {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {
                return false; 
            }
            char topChar = s.pop();
            if (!isMatching(topChar, ch)) {
                return false; 
            }
        }
        i++;
    }

    return s.isEmpty(); 
}

int main() {
    char expr[MAX];
    cout << "Enter an expression: ";
    cin.getline(expr, MAX);

    if (Parentheses(expr)) {
        cout << "Parentheses are balanced." << endl;
    } else {
        cout << "Parentheses are NOT balanced." << endl;
    }

    return 0;
}