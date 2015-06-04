#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<char> s;

bool IsOperator(char ch){
    if(ch == '/' || ch == '*' || ch == '+' || ch == '-') return true;
    return false;
}

bool HasHigherPrecedence(char top, char ch){
    switch(top){
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

void InfixToPostfix(string expr){
    string post_expr;

    for(int i=0; i< expr.length(); i++){
        if(IsOperator(expr[i]) && HasHigherPrecedence(s.top(), expr[i])){
        }
    }
}


int main(){
    string expr = "A+B*C-D*E";
    // InfixToPostfix(expr);
    HasHigherPrecedence('R', 'V');
}
