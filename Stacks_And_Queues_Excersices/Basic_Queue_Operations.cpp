#include <iostream>
#include <stack> 
#include <string> 
#include <vector>
#include <sstream>
#include<climits>
#include<queue>

using namespace std;

int main()
{
	int totalNumbers, removeNumbers, searchNumber;

	cin >> totalNumbers >> removeNumbers >> searchNumber;
	queue<int> buffer;

	for (int i = 0; i < totalNumbers; i++)
	{
		int buf;
		cin >> buf;
		buffer.push(buf);
	}

	for (int i = 0; i < removeNumbers; i++)
		buffer.pop();
	if (buffer.size() == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	int smallest = INT_MAX;
	while (buffer.size())
	{
		int top = buffer.front();
		buffer.pop();

		if (top == searchNumber)
		{
			cout << "true" << endl;
			return 0;
		}
		if (top < smallest)
			smallest = top;
	}

	cout << smallest << endl;

	return 0;
}