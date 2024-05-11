#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
bool visited[N];
int level[N];

void bfs(int vertex){
    queue<int> q;
    q.push(vertex);
    visited[vertex] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int child: g[cur]){
            if(visited[child!=true]){
                q.push(child);
                visited[child] = true;
                level[child] = level[cur]+1;
                
            }
        }
    }
    cout << endl;
    
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
    // /(1);
}