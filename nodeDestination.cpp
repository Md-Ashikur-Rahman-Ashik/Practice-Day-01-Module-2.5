#include <bits/stdc++.h>
using namespace std;

vector<int> adjacencyList[1005];
int visitedArray[1005];

void bfs(int sourceNode)
{
    queue<int> integerQueue;
    integerQueue.push(sourceNode);
    visitedArray[sourceNode] = true;
    while (!integerQueue.empty())
    {
        int parentNode = integerQueue.front();
        integerQueue.pop();

        for (auto childNode : adjacencyList[parentNode])
        {
            if (visitedArray[childNode] == false)
            {
                integerQueue.push(childNode);
                visitedArray[childNode] = true;
            }
        }
    }
}

int main()
{
    int numberOfNode, numberOfEdge;
    cin >> numberOfNode >> numberOfEdge;

    for (int i = 0; i < numberOfEdge; i++)
    {
        int firstValue, secondValue;
        cin >> firstValue >> secondValue;

        adjacencyList[firstValue].push_back(secondValue);
        adjacencyList[secondValue].push_back(firstValue);
    }

    memset(visitedArray, false, sizeof(visitedArray));
    int sourceNode, destinationNode;
    cin >> sourceNode >> destinationNode;
    bfs(sourceNode);

    if (visitedArray[destinationNode])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}