#include <bits/stdc++.h>
using namespace std;

void printAdjacencyMatrix(int n, vector<pair<int, int>> edges)
{
    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
    for (auto edge : edges)
    {
        mat[edge.first][edge.second] = 1;
        mat[edge.second][edge.first] = 1;
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
    printAdjacencyMatrix(n, edges);
    return 0;
}