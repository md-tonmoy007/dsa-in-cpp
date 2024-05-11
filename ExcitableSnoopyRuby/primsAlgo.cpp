#include<bits/stdc++.h>
using namespace std;

 vector< pair<pair<int,int>, int> > calculatePrimMST(vector<vector<int>>edges, int n, int m){
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int>par(n, -1);
    vector<bool>mst(n, false);
    vector<int>key(n, INT_MAX);

    key[0] = 0;

    for (int i=0; i < n; i++){
        int mini=INT_MAX, u;
        for (int j=0; j < key.size(); j++)
        {
            if(key[j] < mini && mst[j] == false){
                mini = key[j];
                u = j;
            }
        }

        mst[u] = true;

        for (pair<int,int> x: adj[u]){
            if (mst[x.first]==false && x.second < key[x.first]){
                key[x.first] = x.second;
                par[x.first] = u;
            }
        }

    }

    vector< pair<pair<int,int>, int> > answer;
    for(int i=1; i<n; i++) {
        answer.push_back({{par[i], i}, key[i]});
    }

    return answer;


}


int main() {
    vector<vector<int>> edges;
    int n, m, src;

    cout << "Enter the number of nodes : ";
    cin >> n;
    
    cout << "Enter the number of edges : ";
    cin >> m;

    cout << "Enter the edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    vector< pair<pair<int,int>, int> >  answer = calculatePrimMST(edges, n, m);

    for(pair<pair<int,int>, int> x : answer) {
        pair<int,int> a = x.first;
        int b = x.second;

        /*
            a.first -> u
            a.second -> v
            b -> weight
        */
        cout << a.first << "-" << a.second << " : " << b << endl;
    }

    return 0;
}