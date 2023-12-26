#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> edges;
    int n;
    cout << "Enter no of nodes:";
    cin >> n;
    while (1)
    {
        int n1, n2;
        cin >> n1 >> n2;
        if (n1 == -1 or n2 == -1)
            break;
        edges.push_back(make_pair(n1, n2));
    }
    printAdjacencyList(n, edges);
    return 0;
}

void printAdjacencyList(int n, vector<pair<int, int>> edges)
{
    vector<vector<int>> adjList(n + 1);
    for (auto edge : edges)
    {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }
    cout << "\nPrinting Adj List:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (auto val : adjList[i])
            cout << val << " ";
        cout << endl;
    }
}