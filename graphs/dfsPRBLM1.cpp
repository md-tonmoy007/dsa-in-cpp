#include<bits/stdc++.h>


#define rn(i, n) for(int i = 0; i<int(n); i++)

using namespace std;

vector<vector<int>> cc;
vector<int> current_cc;

const int N = 1e5+10;
vector<int> g[N];
bool vis[N];



void dfs(int vertex)
{
    /*
    take action on vertex after entering the vertex
    */

   vis[vertex] = true;
   current_cc.push_back(vertex);
    for (int child: g[vertex]){

        /*take action on child before entering the child*/
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
    int ct = 0; 
    for(int i= 1;i <= n; i++)
    {
        if (vis[i]) continue;
        current_cc.clear();
        dfs(i); 
        cc.push_back(current_cc);

        ct++;
    }
    // cout << ct << endl;
    cout << cc.size() << endl;
    for(auto c_cc:cc){
        for(int v: c_cc){
            cout << v << " ";
        }
        cout << endl;
    }

}