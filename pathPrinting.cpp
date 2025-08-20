// Input
// 7 7
// 0 1
// 1 3
// 3 2
// 1 4
// 3 5
// 2 5
// 5 6
// 0
// 6

#include <bits/stdc++.h>
using namespace std;

vector<int> adjacencyList[1005];
int visitedArray[1005];
int levelArray[1005];
int parentArray[1005];

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
                levelArray[childNode] = parentNode + 1;
                parentArray[childNode] = parentNode;
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
    memset(parentArray, -1, sizeof(parentArray));

    int sourceNode, destinationNode;
    cin >> sourceNode >> destinationNode;

    bfs(sourceNode);

    int pathNode = destinationNode;
    stack<int> pathStack;

    while (pathNode != -1)
    {
        pathStack.push(pathNode);
        pathNode = parentArray[pathNode];
    }

    while (!pathStack.empty())
    {
        cout << pathStack.top() << " ";
        pathStack.pop();
    }

    return 0;
}