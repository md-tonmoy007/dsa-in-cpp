#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
 
using namespace std;
// vector< pair<pair<int,int>, int> > calculatePrimsMST(vector< vector<int> > &edges, int n, int m) {}

// Writing own compare method to sort vector according to their 2nd index
bool compare(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}


int findParent(vector<int>&parent, int node){
    if(parent[node] == node){
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}





void unionSet(int u, int v, vector<int>&parent, vector<int>&rank){
    // u = findParent(parent, u);
    // v = findParent(parent, v);

    if (rank[u] < rank[v]){
        parent[u] = v;
        rank[v]++;
    }else if (rank[v] < rank[u]){
        parent[v] = u;
        rank[u]++;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}


int calculateKruskalsMST(vector<vector<int>>&edges, int n){
    vector<int>parent(n);
    vector<int>rank(n);

    for(int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    sort(edges.begin(), edges.end(), compare);
    int minWT = 0;

    for(int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);

        if (u != v){
            unionSet(u, v, parent, rank);
            minWT += edges[i][2];
        }
        
    }
    return minWT;
}
 
int main(){
    vector<vector<int>> edges;
    int n, m, src;
    cin >> n >> m;
    for (int i=0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }


    int MinWeight = calculateKruskalsMST(edges, n);
    cout << "result: " << MinWeight << endl;;
    return 0;
}