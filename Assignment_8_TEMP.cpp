//ASSIGNMENT  8

// Title : Write a program to convert infix expression to postfix, infix expression to prefix and evaluation of postfix and prefix expression

// PRN NO : 124B2B011

// NAME : Atharva Girirsh Naik

// CLASS & DIV : SY-B

// CODE :
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (char token : infix) {
        if (isalnum(token)) {
            postfix += token;
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

string reverseString(const string& str) {
    return string(str.rbegin(), str.rend());
}

string infixToPrefix(const string& infix) {
    string reversedInfix = reverseString(infix);
    for (char& c : reversedInfix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    string postfix = infixToPostfix(reversedInfix);
    return reverseString(postfix);
}

int main() {
    string infixExpression;

    cout << "Enter an infix expression (e.g., A+B*(C-D)): ";
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);
    string prefixExpression = infixToPrefix(infixExpression);

    cout << "Postfix Expression: " << postfixExpression << endl;
    cout << "Prefix Expression: " << prefixExpression << endl;

    return 0;
}


//OUTPUT :: 

// Enter an infix expression (e.g., A+B*(C-D)): A+B*(C-D)
// Postfix Expression: ABCD-*+
// Prefix Expression: +A*B-CD
