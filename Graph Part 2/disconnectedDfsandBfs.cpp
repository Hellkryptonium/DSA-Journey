#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    { // u-v
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print()
    {
        for (int u = 0; u < V; u++)
        {
            list<int> neighbors = l[u];
            cout << u << " : ";
            for (int v : neighbors)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void bfsHelper(int st, vector<bool> &vis)
    {
        queue<int> q;

        q.push(st);
        vis[st] = true;

        while (q.size() > 0)
        {
            int u = q.front(); // curr vertex
            q.pop();

            cout << u << " ";

            list<int> neighbor = l[u]; // u---v
            for (int v : neighbor)
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void bfs()
    {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                bfsHelper(i, vis);
                cout << endl;
            }
        }
    }

    void dfsHelper(int u, vector<bool> &vis)
    { // O(V+E)
        vis[u] = true;
        cout << u << " ";

        list<int> neighbors = l[u];
        for (int v : neighbors)
        {
            if (!vis[v])
            {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs()
    {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsHelper(i, vis); // starting point 1
                cout << endl;
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph graph(10);
    // undirected
    graph.addEdge(0, 2);
    graph.addEdge(2, 5);
    graph.addEdge(1, 6);
    graph.addEdge(6, 4);
    graph.addEdge(4, 9);
    graph.addEdge(4, 3);
    graph.addEdge(3, 8);
    graph.addEdge(3, 7);

    graph.print();

    cout << endl;
    cout << endl;

    graph.bfs();

    cout << endl;

    graph.dfs();

    return 0;
}