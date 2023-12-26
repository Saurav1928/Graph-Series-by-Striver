#include <bits/stdc++.h>
using namespace std;

void printAdjacencyMatrix(int n, vector<pair<pair<int, int>, int>> edges)
{
    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
    for (auto edge : edges)
    {
        mat[edge.first.first][edge.first.second] = edge.second;
        mat[edge.first.second][edge.first.first] = edge.second;
    }
    cout << "\nPrinting Adj Matrix:\n";
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i != 0 and j != 0)
                cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
void printAdjacencyList(int n, vector<pair<pair<int, int>, int>> edges)
{
    vector<vector<pair<int, int>>> adjList(n + 1);
    for (auto edge : edges)
    {
        adjList[edge.first.first].push_back(make_pair(edge.first.second, edge.second));
        adjList[edge.first.second].push_back(make_pair(edge.first.first, edge.second));
    }
    cout << "\nPrinting Adj List:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (auto val : adjList[i])
            cout << " (" << val.first << " , " << val.second << ") ";
        cout << endl;
    }
}

int main()
{
    vector<pair<pair<int, int>, int>> edges;
    int n;
    cout << "Enter no of nodes:";
    cin >> n;
    while (1)
    {
        int n1, n2, wt;
        cin >> n1 >> n2 >> wt;

        if (n1 == -1 or n2 == -1)
            break;
        pair<pair<int, int>, int> pr = make_pair(make_pair(n1, n2), wt);
        edges.push_back(pr);
    }
    printAdjacencyMatrix(n, edges);
    printAdjacencyList(n, edges);
    return 0;
}