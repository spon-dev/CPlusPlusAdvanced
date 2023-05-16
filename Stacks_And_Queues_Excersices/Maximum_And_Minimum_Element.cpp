#include <iostream>
#include <stack> 
#include <string> 
#include <vector>
#include <sstream>
#include<climits>
#include<queue>

using namespace std;

int minimum(stack<int> buffer)
{
    int min = INT_MAX;
    while (buffer.size())
    {
        int top = buffer.top();
        buffer.pop();
        if (top < min)
        {
            min = top;
        }

    }
    return min;

}




int maximum(stack<int> buffer)
{
    int max = INT_MIN;
    while (buffer.size())
    {
        int top = buffer.top();
        buffer.pop();
        if (top > max)
        {
            max = top;
        }

    }
    return max;

}


int main()
{
    stack<int> buffer;
    int commands;
    cin >> commands;


    while (commands--)
    {
        int command, number;
        cin >> command;
        switch (command)
        {
        case 1:
            cin >> number;
            buffer.push(number);
            break;
        case 2:
            if (buffer.size())
            buffer.pop();
            break;
        case 3:
            if (buffer.size())
                cout << maximum(buffer) << endl;
            break;
        case 4:
            if (buffer.size())
                cout << minimum(buffer) << endl;
            break;
        }

    }

    while (!buffer.empty())
    {
        cout << buffer.top();
        buffer.pop();

        if (!buffer.empty())
        {
            cout << ", ";
        }
    }

    cout << endl;

    return 0;
}

