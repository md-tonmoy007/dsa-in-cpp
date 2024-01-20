#include<bits/stdc++.h>


#define rn(i, n) for(int i = 0; i<int(n); i++)

using namespace std;


const int N = 1e5+10;
vector<int> g[N];
bool vis[N];
bool isLoopExist;


bool dfs(int vertex, int par)
{
    /*
    take action on vertex after entering the vertex
    */

    vis[vertex] = true;
    isLoopExist = false;
    for (int child: g[vertex]){

        /*take action on child before entering the child*/
        if(vis[child] && child == par) continue;
        if (vis[child]) return true;
        isLoopExist |= dfs(child, vertex);
        /*take action on child after exiting the child*/
    }
    /*take action on vertext before exiting the vertex*/
    return isLoopExist;
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

    for(int i= 1;i <= n; i++)
    {
        if (vis[i]) continue;
        if(dfs(i, 0))
        {
            isLoopExist = true;
            break;
        } 
    }
    cout << isLoopExist << endl;
}