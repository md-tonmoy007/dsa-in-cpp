#include<bits/stdc++.h>


#define rn(i, n) for(int i = 0; i<int(n); i++)

using namespace std;


const int N = 1e5+10;
vector<int> g[N];
bool vis[N];



void dfs(int i , int j, vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if(i < 0 || j < 0) return;
    if(i >= n || j > m) return;
    if(grid[i][j] != '1') return;

    grid[i][j] = '0';

    dfs(i-1, j, grid);
    dfs(i+1, j, grid);
    dfs(i, j-1, grid);
    dfs(i, j+1, grid);
}



int numIslands(vector<vector<char>>& grid) {
            
            int n = grid.size();
            int m = grid[0].size();

            int ct = 0;

            for (int i = 0; i< n; i++)
            {
                for (int j; j <  m; j++){
                    if(grid[i][j] != '0')
                    dfs(i, j, grid);
                    ct++;
                }
            }
            
}

int main()
{
}


