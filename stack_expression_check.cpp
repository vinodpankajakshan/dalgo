#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check_expression(string expression){
    stack<char> s;

    for (int i = 0; i < expression.size(); i++) {
        switch(expression[i]){
            case '{':
                s.push(expression[i]);
                break;

            case '[':
                s.push(expression[i]);
                break;

            case '(':
                s.push(expression[i]);
                break;

            case ')':
                if(s.top() != '('){
                    printf("ERROR: Expression out of balance\n");
                    return false;
                }
                s.pop();
                break;

            case ']':
                if(s.top() != '['){
                    printf("ERROR: Expression out of balance\n");
                    return false;
                }
                s.pop();
                break;
                
            case '}':
                if(s.top() != '{'){
                    printf("ERROR: Expression out of balance\n");
                    return false;
                }
                s.pop();
                break;
        }
    }
    return s.empty() ? true : false;
}

int main() {
    string expression = "{[()]}";
    cout << "result: " << check_expression(expression) << endl;
}
