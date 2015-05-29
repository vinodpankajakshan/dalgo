#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string expression = "{[()]}";

    for (int i = 0; i < expression.size(); i++) {
        cout << expression[i];
    }
    cout << endl;
    // stack<char> s;
}
