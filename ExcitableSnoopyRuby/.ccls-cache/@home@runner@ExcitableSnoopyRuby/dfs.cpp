#include<bits/stdc++.h>


#define rn(i, n) for(int i = 0; i<int(n); i++)

using namespace std;
const int N = 1e5+10;
bool vis[N];
vector<int> g[N];


void dfs(int vertex){
    cout << vertex << " ";
    vis[vertex] = true;
    for(int child: g[vertex]){
        if(vis[child] == true) continue;
        dfs(child);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i< m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
}