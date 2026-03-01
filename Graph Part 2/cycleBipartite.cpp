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
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool dfsHelper(int src,
                   int parent,
                   vector<bool> &vis,
                   vector<int> &color,
                   vector<int> &depth,
                   bool &hasOddCycle,
                   bool &hasEvenCycle)
    {
        vis[src] = true;

        for (int nbr : l[src])
        {
            if (!vis[nbr])
            {
                color[nbr] = 1 - color[src];
                depth[nbr] = depth[src] + 1;

                if (dfsHelper(nbr, src, vis,
                              color, depth,
                              hasOddCycle,
                              hasEvenCycle))
                    return true;
            }
            else if (nbr != parent)
            {
                // cycle found
                int cycleLength =
                    abs(depth[src] - depth[nbr]) + 1;

                if (cycleLength % 2 == 0)
                    hasEvenCycle = true;
                else
                    hasOddCycle = true;
            }
        }

        return false;
    }

    void analyzeGraph()
    {
        vector<bool> vis(V, false);
        vector<int> color(V, -1);
        vector<int> depth(V, 0);

        bool hasOddCycle = false;
        bool hasEvenCycle = false;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                color[i] = 0;
                depth[i] = 0;

                dfsHelper(i, -1,
                          vis,
                          color,
                          depth,
                          hasOddCycle,
                          hasEvenCycle);
            }
        }

        cout << "Cycle Exists: "
             << (hasOddCycle || hasEvenCycle) << endl;

        cout << "Odd Cycle: "
             << hasOddCycle << endl;

        cout << "Even Cycle: "
             << hasEvenCycle << endl;

        cout << "Bipartite Graph: "
             << (!hasOddCycle) << endl;
    }
};

int main()
{
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0); // odd cycle

    graph.addEdge(3, 4);

    graph.analyzeGraph();

    return 0;
}