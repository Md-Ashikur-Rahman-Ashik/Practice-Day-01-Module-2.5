#include <bits/stdc++.h>
using namespace std;

vector<int> adjacencyList[1005];
int visitedArray[1005];
int levelArray[1005];

void bfs(int sourceNode)
{
    queue<int> integerQueue;
    integerQueue.push(sourceNode);
    visitedArray[sourceNode] = true;
    levelArray[sourceNode] = 0;

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
                levelArray[childNode] = levelArray[parentNode] + 1;
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
    memset(levelArray, -1, sizeof(levelArray));

    int sourceNode, destinationNode;
    cin >> sourceNode >> destinationNode;

    bfs(sourceNode);

    // for (int i = 0; i < numberOfNode; i++)
    // {
    //     cout << i << " -> " << levelArray[i] << endl;
    // }

    cout << levelArray[destinationNode] << endl;

    return 0;
}