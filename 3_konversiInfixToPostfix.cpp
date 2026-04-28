#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int priority(char cmd) {
    if (cmd == '^')
        return 3;
    else if (cmd == '*' || cmd == '/')
        return 2;
    else if (cmd == '+' || cmd == '-')
        return 1;
    else
        return 0;
}

bool Operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string InfixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty()) {
                s.pop();
            } 
        } else if (Operator(c)) {
            while (!s.empty() && priority(s.top()) >= priority(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Infix: ";
    cin >> infix;

    string postfix = InfixToPostfix(infix);

    cout << "Postfix: " << postfix << endl;

    return 0;
}