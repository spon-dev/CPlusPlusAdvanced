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

string buffer;
getline(cin, buffer);

istringstream istr(buffer);
stack<int> pile;
int curElt;
while (istr >> curElt)
{
	pile.push(curElt);
}
		int rackSize;
		cin >> rackSize;
		int racks = 1;
		int curRackSize = rackSize;

		while (pile.size())
		{
			int curPiece = pile.top();
			pile.pop();
			if (curPiece <= curRackSize)
			{
				curRackSize -= curPiece;

			}
			else
			{
				//initilize a new rack
				racks++;
				curRackSize = rackSize;
				//put the piece on the rack
				curRackSize -= curPiece;
			}
		}
		cout << racks << endl;
	
	return 0;
}


