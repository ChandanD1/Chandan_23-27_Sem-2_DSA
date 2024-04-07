// 4. Evaluate Postfix Expression using Stack ADT.

// Theory:
// This code evaluates a postfix expression by iterating through each 
// character of the expression and using a stack to perform the 
// necessary arithmetic operations. It pushes operands onto the stack 
// and when encountering an operator, it pops the required number of 
// operands from the stack, performs the operation, and pushes the 
// result back onto the stack.

#include <iostream>
#include <stack>
using namespace std;

int evaluate(const string& postfix) 
{
    stack<int> s;

    for (char c : postfix) 
    {
        if (isdigit(c)) 
        {
            s.push(c - '0');
        }
        else 
        {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            
            switch(c) 
            {
                case '+': s.push(operand1 + operand2); 
                break;
                case '-': s.push(operand1 - operand2); 
                break;
                case '*': s.push(operand1 * operand2); 
                break;
                case '/': s.push(operand1 / operand2); 
                break;
            }
        }
    }

    return s.top();
}

int main() 
{
    string postfixexp;
    
    cout << "enter postfix expression: ";
    getline(cin, postfixexp);
    
    cout << "result: " << evaluate(postfixexp) << endl;
    
    return 0;
}

