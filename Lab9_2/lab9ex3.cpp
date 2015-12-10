// Exercise 3 driver file
// Lab 9
// Fall 2014

#include <iostream>
using namespace std;

#include "IntStack.h"

IntStack stack;

int evalPostFix(string s) {
    
    for (int i=0; i<s.size(); i++) {
        
        char next = s[i];
        if (isdigit(next))
            stack.push(next-'0');
        else { //operator
            int op2 = stack.pop();
            int op1 = stack.pop();
            switch (next) {
                case '+':
                    stack.push(op1+op2);
                    break;
                case '-':
                    stack.push(op1-op2);
                    break;
                case '*':
                    stack.push(op1*op2);
                    break;
                case '/':
                    stack.push(op1/op2);
                    break;
            }
        }
    }
    
    return stack.pop();
    
}

int main() {
    cout << evalPostFix("84/") << " (should be 2)" << endl;
    cout << evalPostFix("84*") << " (should be 32)" << endl;
    cout << evalPostFix("12+84-*") << " (should be 12)" << endl;
    cout << evalPostFix("8412+-*") << " (should be 8)" << endl;
}