#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true)
    {
        this->V = V;
        l = new list<int>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v)
    { // u-v
        l[u].push_back(v);
        if (isUndir) // false
        {
            l[v].push_back(u);
        }
    }

    void topoHelper(int src, vector<bool> &vis, stack<int> &s)
    { // dfs
        vis[src] = true;

        list<int> neighbors = l[src];
        for (int v : neighbors)
        {
            if (!vis[v])
            {
                topoHelper(v, vis, s);
            }
        }
        s.push(src);
    }

    void toppoSort()
    {
        vector<bool> vis(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                topoHelper(i, vis, s);
            }
        }

        // print topological order

        while (s.size() > 0)
        {
            cout << s.top() << " ";
            s.pop();
        }

        cout << endl;
    }
};

int main()
{
    // DAG
    Graph graph(6, false);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    graph.addEdge(4, 0);
    graph.addEdge(4, 1);

    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.toppoSort();
    return 0;
}