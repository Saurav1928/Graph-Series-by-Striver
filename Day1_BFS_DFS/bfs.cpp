#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AdjacencyList(int n, vector<pair<int, int>> edges)
{
    vector<vector<int>> adjList(n + 1);
    for (auto edge : edges)
    {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }
    // cout << "\nPrinting Adj List:\n";
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " : ";
    //     for (auto val : adjList[i])
    //         cout << val << " ";
    //     cout << endl;
    // }
    return adjList;
}

void BFS(int s, int n, vector<pair<int, int>> edges)
{
    queue<int> Q;
    Q.push(s);
    vector<int> bfsList;
    vector<bool> visited(n + 1, false);
    vector<vector<int>> adjList = AdjacencyList(n, edges);
    cout << "Adj List: \n";
    cout << "\nPrinting Adj List:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (auto val : adjList[i])
            cout << val << " ";
        cout << endl;
    }
    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        visited[s] = true;
        bfsList.push_back(curr);
        for (auto it : adjList[curr])
        {
            if (visited[it] == false)
            {
                Q.push(it);
                visited[it] = true;
            }
        }
    }
    cout << "\nbfs List: ";
    for (auto it : bfsList)
        cout << it << " ";
}

// directed one
vector<int> bfsOfGraph(int n, vector<int> adjList[])
{
    queue<int> Q;
    Q.push(0);
    vector<int> ans;
    vector<bool> vis(n, false);
    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        if (vis[curr] == true)
            continue;
        ans.push_back(curr);
        vis[curr] = true;
        for (auto it : adjList[curr])
        {
            if (vis[it] == false)
                Q.push(it);
        }
    }
    return ans;
}

// for BFS -> TC= O(v)+O(Total Degree) ; SC= O(v);

void DFS(int n, int s, vector<vector<int>> adjList, vector<bool> &vis, vector<int> &ans)
{
    if (vis[s] == true)
        return;
    vis[s] = true;
    ans.push_back(s);
    for (auto curr : adjList[s])
        DFS(n, curr, adjList, vis, ans);
    return;
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
    int source;
    cout << "\nEnter source Node: ";
    cin >> source;
    // BFS(source, n, edges);
    vector<vector<int>> adjList = AdjacencyList(n, edges);
    vector<bool> vis(n + 1, false);
    vector<int> ans;
    DFS(n, source, adjList, vis, ans);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}