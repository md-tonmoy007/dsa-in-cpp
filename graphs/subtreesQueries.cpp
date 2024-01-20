#include<bits/stdc++.h>


#define rn(i, n) for(int i = 0; i<int(n); i++)

using namespace std;


const int N = 1e5+10;
vector<int> g[N];
bool vis[N];
int subTree_sum[N];
int even_ct[N];

void dfs(int vertex, int par = 0)
{
    /*
    take action on vertex after entering the vertex
    */
    subTree_sum[vertex] = vertex;
    if(vertex %2 == 0) even_ct[vertex]++;
    for (int child: g[vertex]){
        if(child == par) continue;
        /*take action on child before entering the child*/
        dfs(child, vertex);
        /*take action on child after exiting the child*/
        subTree_sum[vertex] += subTree_sum[child];
        even_ct[vertex] += even_ct[child];

    }
    /*take action on vertext before exiting the vertex*/
    
}


int main()
{
    int n;
    cin >> n;

    for (int i = 0; i< n-1; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << subTree_sum[i] << " >>>> " << even_ct[i]<< endl;
    }
}