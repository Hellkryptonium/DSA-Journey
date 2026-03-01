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

    bool undirCycleHelper(int src, int par, vector<bool> &vis)
    {
        vis[src] = true;
        list<int> neighbors = l[src];

        for (int v : neighbors)
        {
            if (!vis[v])
            {
                if (undirCycleHelper(v, src, vis))
                {
                    return true;
                }
            }
            else
            {
                if (v != par)
                { // cycle condn
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycleUndir()
    {
        vector<bool> vis(V, false);
        return undirCycleHelper(0, -1, vis);
    }

    bool dirCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath)
    {
        vis[src] = true;
        recPath[src] = true;
        list<int> neighbors = l[src];

        for (int v : neighbors)
        {
            if (!vis[v])
            {
                if (dirCycleHelper(v, vis, recPath))
                {
                    return true;
                }
            }
            else
            {
                if (recPath[v])
                {
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    bool isCycleDir()
    {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dirCycleHelper(i, vis, recPath))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool isBipartite()
    {
        queue<int> q;
        vector<int> color(V, -1);

        q.push(0);
        color[0] = 0; // blue

        while (q.size() > 0)
        {
            int curr = q.front();
            q.pop();

            list<int> neighbors = l[curr];

            for (int v : neighbors)
            {
                if (color[v] == -1) // unvisited
                {
                    color[v] = !color[curr];
                    q.push(v);
                }
                else
                {
                    if (color[v] == color[curr])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    // undirected, bipartite graph
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    // graph.addEdge(0, 3);

    cout << graph.isBipartite() << endl;

    return 0;
}