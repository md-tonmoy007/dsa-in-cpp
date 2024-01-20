#include<bits/stdc++.h>


#define rn(i, n) for(int i = 0; i<int(n); i++)

using namespace std;


const int N = 1e5+10;
vector<int> g[N];

bool isLoopExist;




class Solution {
public:
    const int N = 1e5+10;
    vector<int> g[N];
    bool vis[N];
    bool isLoopExist;

    bool dfs(int vertex, bool (&vis)[], vector<vector<int>>& g)
    {
        /*
        take action on vertex after entering the vertex
        */
        vis[vertex] == true;
        for (int child: g[vertex]){

            /*take action on child before entering the child*/
            if (vis[child]) return false;
            
            /*take action on child after exiting the child*/
        }
        /*take action on vertext before exiting the vertex*/
        return  true;;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) vis[i] = 0;
        return dfs(prerequisites[0][0], vis, prerequisites);
    
    }
    
};




int main()
{
    Solution s1;
    int n;
    vector<vector<int>> pre;
}