#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<char> s;

bool IsOperator(char ch){
    if(ch == '/' || ch == '*' || ch == '+' || ch == '-') return true;
    return false;
}

// Returns true is stack's top has high precedence operator
// false otherwise.
bool HasHigher(char ch){
    switch(s.top()){
        case '/':
            if(ch == '*' or ch == '+' or ch == '-') return true;
            return false;
            break;

        case '*':
            if(ch == '+' or ch == '-') return true;
            return false;
            break;

        case '+':
            if(ch == '-') return true;
            return false;
            break;

        case '-':
            return false;
            break;

        default:
            return false;
            break;
    }
}

void Evaluate(string expr){
    string post_expr;

    for(int i=0; i < expr.length(); i++){
        if(IsOperator(expr[i])){
            if(s.empty()) s.push(expr[i]);
            else {
                if(HasHigher(expr[i])){
                    while(!s.empty()){
                        post_expr += s.top();
                        s.pop();
                    }
                }
                s.push(expr[i]);
            }
        }
        else if(i == expr.length() - 1){
            post_expr += expr[i];

            while(!s.empty()){
                post_expr += s.top();
                s.pop();
            }
        }
        else post_expr += expr[i];
    }
    cout << "postfix expression is " << post_expr << endl;
}

int main(){
    string expr;
    cout << "Enter a Infix Expression: " << endl << "> ";
    getline(cin, expr);
    Evaluate(expr);
}
