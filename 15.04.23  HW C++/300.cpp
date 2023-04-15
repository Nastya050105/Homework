#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Rocket
{
    int number;           
    long long startTime;   
    long long speed;        
};

bool compareRockets(const Rocket& a, const Rocket& b)
{
    return a.startTime < b.startTime;
}

int main()
{
    long long time, velocity;
    vector<Rocket> rockets(4);
    long long multiplier = 1;  
    for (int i = 0; i < 4; i++)
    {
        cin >> time >> velocity;
        rockets[i].number = i;
        rockets[i].startTime = time;
        rockets[i].speed = velocity;
        multiplier *= velocity;
    }
    long long turnTime, distanceToStart;
    cin >> turnTime >> distanceToStart;
    for (int i = 0; i < 4; i++) 
    {
        rockets[i].startTime = rockets[i].startTime * multiplier + distanceToStart * multiplier / rockets[i].speed;
    }
    turnTime *= multiplier; 
    sort(rockets.begin(), rockets.end(), compareRockets);  
    for (int i = 1; i < 3; i++)
    {
        if (rockets[i].startTime == rockets[i + 1].startTime) 
        {
            if (abs(rockets[i - 1].number - rockets[i].number) == 2)
            {
                swap(rockets[i], rockets[i + 1]);
            }
        }
    }
    int count = 1; 
    int i = 1;
    while (i < 4)
    {
        if (rockets[i - 1].startTime + turnTime * (abs(rockets[i].number - rockets[i - 1].number) % 2 == 0 ? 2 : 1) <= rockets[i].startTime)
        {
            count++;
            i++;
        }
        else
        {
            break;
        }
    }
    if (count < 4)
    {
        cout << count;
    }
    else
    {
        cout << "ALIVE";
    }

    return 0;
}