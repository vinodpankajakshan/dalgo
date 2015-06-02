#include <iostream>
#include <cstdio>
#include <stack>
#include <cmath>
using namespace std;

stack<int> s;

bool IsOperator(char ch){
    if(ch == '/' || ch == '*' || ch == '+' || ch == '-'){
        return true;
    }
    return false;
}

bool IsNumericDigit(char ch){
    if(ch >= '0' and ch <= '9') return true;
    return false;
}

int PerformCalc(char operate, int op1, int op2){
    switch(operate){
        case '/':
            return op1 / op2;
            break;

        case '*':
            return op1 * op2;
            break;

        case '+':
            return op1 + op2;
            break;

        case '-':
            return op1 - op2;
            break;

        default:
            return 0;
            break;
    }
}

void EvaluatePostfix(string expr){
    for(int i=0; i < expr.length(); i++){
        if(expr[i] == ' ' || expr[i] == ',') continue;

        if(IsOperator(expr[i])){
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            s.push(PerformCalc(expr[i], op1, op2));
        }
        else {
            int operand = 0;
            while(i < expr.length() && IsNumericDigit(expr[i])){
                operand = (operand * 10) + ( expr[i] - '0');
                i++;
            }
            s.push(operand);
            i--;
        }
    }
    cout << "The result is " << s.top() << endl;
}

void EvaluatePrefix(string expr){
    int len = expr.length() - 1;

    for(int i=len; i >= 0 ; i--){
        if(expr[i] == ' ' || expr[i] == ',') continue;

        if(IsOperator(expr[i])){
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();
            int result = PerformCalc(expr[i], op1, op2);
            s.push(result);
        }
        else if(IsNumericDigit(expr[i])){
            int operand,n = 0;

            for(int j=i; j >= 0; j--){
                if(IsNumericDigit(expr[j])){
                    operand = ((expr[j] - '0') * (int)pow((double)10, n)) + operand;
                    n++;
                } else{
                    cout << "operand " << operand << endl;
                    s.push(operand);
                    operand  = n = 0;
                    i = j + 1;
                    break;
                }
            }
        }
    }
    cout << "The result is " << s.top() << endl;
}

int main(){
    char eval_mode;
    string expr;

    cout << "Enter an expression to evaluate: \n" << "> ";
    getline(cin, expr);

    cout << "Prefix(E) or Postfix(S) evaluation?\n" << "> ";
    cin >> eval_mode;

    if(eval_mode == 'S') EvaluatePostfix(expr);
    else if (eval_mode == 'E') EvaluatePrefix(expr);
    else cout << "Wrong input\n";
}
