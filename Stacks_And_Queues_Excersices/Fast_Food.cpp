#include <iostream>
#include <stack> 
#include <string> 
#include <vector>
#include <sstream>
#include<climits>
#include<queue>

using namespace std;

int maximum(queue<int> orders)
{
    int max = INT_MIN;
    while (orders.size())
    {
        int front = orders.front();
        orders.pop();
        if (front > max)
        {
            max = front;
        }

    }
    return max;

}


int main() 
{
    queue<int> orders;

    int portions;
    cin >> portions;
    cin.ignore();

    string buffer;
    getline(cin, buffer);

    istringstream istr(buffer);
    int curOrder;
    while (istr >> curOrder)
        orders.push(curOrder);
    
    cout << maximum(orders) << endl;

    while (orders.size())
    {
        int curOrder = orders.front();
        if (curOrder > portions)
            break;
        portions -= curOrder;

        orders.pop();
    }
        if (orders.size() == 0)
            cout << "Orders complete" << endl;
        else
        {
            cout << "Orders left: ";

            while (orders.size())
            {
                int curOrder = orders.front();
                orders.pop();
                cout << curOrder << ' ';
            }

        }
        cout << endl;
    
    return 0;
}