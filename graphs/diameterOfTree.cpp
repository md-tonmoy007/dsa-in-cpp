#include<bits/stdc++.h>


#define rn(i, n) for(int i = 0; i<int(n); i++)

using namespace std;


const int N = 1e5+10;
vector<int> g[N];
bool vis[N];
int depth[N];
int height[N];


void dfs(int vertex, int par=-1)
{
    /*
    take action on vertex after entering the vertex
    */

    for (int child: g[vertex]){
        if (child == par) continue;
        /*take action on child before entering the child*/
        depth[child] = depth[vertex]+1;
        dfs(child, vertex);
        /*take action on child after exiting the child*/

    }
    /*take action on vertext before exiting the vertex*/
    
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i< n-1; ++i)
    {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    
    int mx_depth = -1;
    int mx_depthNode;
    for(int i = 1; i <= n; i++)
    {
        if (mx_depth < depth[i]){
            mx_depth = depth[i];
            mx_depthNode = i;
        }
        depth[i] = 0;
    }
    dfs(mx_depthNode);
    mx_depth = -1;
    for(int i = 1; i <= n; i++)
    {
        if (mx_depth < depth[i]){
            mx_depth = depth[i];
        }
    }
    cout << mx_depth << endl;
    



}