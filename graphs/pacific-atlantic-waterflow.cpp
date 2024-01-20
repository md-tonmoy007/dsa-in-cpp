#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(int n, int m, vector<vector<int>> &G, vector<vector<int>>&vis)
    {
        vis[n][m] = 1;
        for (int i = 0; i<4; i++)
        {
            int x = dx[i] + n;
            int y = dy[i] + m;

            if(x>=0 && y>=0 && x<G.size() && y<G[0].size() && !vis[x][y] && G[x][y] >= G[x][y]){
                dfs(x,y,G,vis);
            }


        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int> (m, 0));
        vector<vector<int>> atlantic(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++){
            dfs(i, 0, heights, pacific);

            dfs(i, n-1, heights, atlantic);
        }
        for (int i = 0; i < n; i++){
            dfs(0, i , heights, pacific);

            dfs(n-1, i,heights, atlantic);
        }
        

        vector<vector<int>> res; 
        for (int i = 0; i< n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (pacific[i][j] == atlantic[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }

        return res;

    }

};



int main(){

}