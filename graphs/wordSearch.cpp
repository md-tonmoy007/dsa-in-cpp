#include<bits/stdc++.h>

using namespace std;




class Solution {
public:

    bool dfs(int i, int j, string s, vector<vector<char>>&board, int k, int n, int m){
        
        if(k >= s.size()) return true;
        if(i < 0 || i >= n|| j < 0 || j>= m || board[i][j] != s[k]|| board[i][j] == '.')return false;
        if(s.size() == 1 && board[i][j] == s[k]) return true;

        board[i][j] == '.';
        bool temp = false;
        int x[] = {1, -1, 0, 0};
        int y[] = {0,0, 1, -1};
        for (int l = 0; l<4; l++)
        {
            temp = temp || dfs(i+x[l], j+y[l], s, board, k+1, n, m);
        }

    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();


        if (rows == 0 || cols == 0) return false;
        if (word.size() == 0) return false;

        for (int i = 0; i<rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(dfs(i, j, word, board, 0, rows, cols)){
                    return true;
                }
            }
        }
        return false;
    }
};