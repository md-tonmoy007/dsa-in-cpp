#include<bits/stdc++.h>


#define rn(i, n) for(int i = 0; i<int(n); i++)

using namespace std;


const int N = 1e5+10;
vector<int> g[N];
bool vis[N];


void dfs(int vertex)
{
    /*
    take action on vertex after entering the vertex
    */
   cout << vertex << endl;
   vis[vertex] = true;
    for (int child: g[vertex]){

        /*take action on child before entering the child*/
        cout << "par "<< vertex << " child "<<  child << endl;
        if (vis[child]) continue;
        dfs(child);
        /*take action on child after exiting the child*/
    }
    /*take action on vertext before exiting the vertex*/
    
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