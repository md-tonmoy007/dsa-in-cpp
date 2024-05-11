#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& adj, int source) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> stk;
    
    stk.push(source);
    visited[source] = true;
    
    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        cout << node << " ";
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                stk.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }
    
    int source;
    cin >> source; // Input the source node for DFS
    
    cout << "DFS traversal starting from node " << source << ":\n";
    dfs(adj, source);
    
    return 0;
}
