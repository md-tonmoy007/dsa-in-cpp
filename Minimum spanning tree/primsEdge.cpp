#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    void primMST() {
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        key[0] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int minKey = INT_MAX, minIndex;
            for (int v = 0; v < V; ++v) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    minIndex = v;
                }
            }

            inMST[minIndex] = true;

            for (auto& edge : adj[minIndex]) {
                int v = edge.first;
                int weight = edge.second;
                if (!inMST[v] && weight < key[v]) {
                    parent[v] = minIndex;
                    key[v] = weight;
                }
            }
        }

        cout << "Edges of Minimum Spanning Tree using Prim's algorithm:" << endl;
        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(4, 2, 7);

    g.primMST();

    return 0;
}
