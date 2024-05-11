#include<bits/stdc++.h>


#define rn(i, n) for(int i = 0; i<int(n); i++)

using namespace std;
const int N = 1e5+10;
bool vis[N];
vector<int> g[N];
int height[N];
int depth[N];


void dfs(int vertex){
    cout << vertex << " ";
    vis[vertex] = true;
    for(int child: g[vertex]){
        if(vis[child] == true) continue;
        depth[child] = depth[vertex]+1;
        dfs(child);
        height[vertex] = max(height[vertex], height[child]+1);
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

    for (int i = 0; i < n; i++){
        cout << height[i] << " " << depth[i] << endl;
    }
}