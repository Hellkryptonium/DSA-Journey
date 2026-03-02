#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *l; // int, int : neighbor + wt
    bool isUndir;

public:
    Graph(int V, bool isUndir = true)
    {
        this->V = V;
        l = new list<pair<int, int>>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v, int wt) // u---v (weight)
    {                                  // u-v
        l[u].push_back(make_pair(v, wt));
        if (isUndir) // false
        {
            l[v].push_back(make_pair(v, wt));
        }
    }

    void primAlgo(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //(wt, v) --> minHeap

        pq.push(make_pair(0, src));

        vector<bool> mst(V, false);
        int ans = 0;

        while (pq.size() > 0)
        {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if (!mst[u])
            {
                mst[u] = true;
                ans += wt;

                list<pair<int, int>> neighbors = l[u];
                for (pair<int, int> n : neighbors)
                {
                    int v = n.first;
                    int currWt = n.second;
                    pq.push(make_pair(currWt, v));
                }
            }
        }
        cout << "final cost of MST = " << ans << endl;
    }
};

int main()
{
    // Prim's Algo Graph
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);

    graph.addEdge(1, 3, 40);

    graph.addEdge(2, 3, 50);

    graph.primAlgo(0);

    return 0;
}