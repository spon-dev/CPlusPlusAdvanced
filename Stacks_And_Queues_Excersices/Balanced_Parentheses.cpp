#include <iostream>
#include <stack> 
#include <string> 
#include <vector>
#include <sstream>
#include<climits>

using namespace std;



bool correctExpression(const string& expression)
{
    stack<char> brackets;
    for (int idx = 0; idx < expression.size(); idx++)
    {
        char curChar = expression[idx];
        char opening = 0;
        switch (curChar)
        {
        case '(':
        case '[':
        case '{':
            brackets.push(curChar);
            break;
        case ')': opening = '(';
            break;
        case ']': opening =  '[';
            break;
        case '}': opening = '{';
            break;
        }
        if (opening)
        {
            if (!brackets.size())
                return false; // incorrect expression 
            if (brackets.top() != opening)
                return false;
            brackets.pop();
        }
    }
    return brackets.size() == 0;
}

int main()
{
string buffer;
cin >> buffer;
cout <<(correctExpression(buffer) ? "YES" : "NO") << endl;

return 0;;
}


