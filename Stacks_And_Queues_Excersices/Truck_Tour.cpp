#include <iostream>
#include <stack> 
#include <string> 
#include <vector>
#include <sstream>
#include<climits>
#include<queue>

using namespace std;

bool canFinishTour(queue<int> amounts, queue<int> distances)
{
int reservoir = 0;
while (amounts.size()) 
{
    reservoir += amounts.front();
    int distanceToNext = distances.front();
    if (reservoir >= distanceToNext)
    {
        reservoir -= distanceToNext;
    }
    else
    {
        return false;
    }
    distances.pop();
    amounts.pop();
}
        return true;
}

int main()
{
    queue <int> amounts;
    queue <int> distances;
    int numberOfStations;
    cin >> numberOfStations;

    for (int i = 0; i < numberOfStations; i++)
    {
        int buf;
        cin >> buf;
        amounts.push(buf);
        cin >> buf;
        distances.push(buf);
    }

    int curStationStart; 
    for (curStationStart = 0; curStationStart < numberOfStations; curStationStart++)
    {
        if (canFinishTour(amounts, distances))
            break;
        int distance = distances.front();
        int amount = amounts.front();
        distances.pop();
        amounts.pop();
        distances.push(distance);
        amounts.push(amount);
    }
    cout << curStationStart <<endl;
    
    return 0;
}


