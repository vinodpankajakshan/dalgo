#include <iostream>
#include <string>
#include <stack>
using namespace std;

void check_expression(string expression){
    stack<char> s;

    cout << "size is " << expression.size() << endl;

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
                cout << s.top() << " -- " << expression[i] << endl;
                if(s.top() != '('){
                    printf("ERROR: Expression out of balance\n");
                    return;
                }
                s.pop();

            case ']':
                cout << s.top() << " -- " << expression[i] << endl;
                if(s.top() != '['){
                    printf("ERROR: Expression out of balance\n");
                    return;
                }
                s.pop();
                
            case '}':
                cout << s.top() << " -- " << expression[i] << endl;
                if(s.top() != '{'){
                    printf("ERROR: Expression out of balance\n");
                    return;
                }
                s.pop();
        }
    }
    cout << "Expression in balance" << endl;
}

int main() {
    string expression = "{[()]}";
    check_expression(expression);
}
