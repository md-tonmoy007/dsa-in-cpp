#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

#define rn(i, n) for(int i = 0; i < int(n); i++) 
// adjency matrix 
const int N = 1e3+10;
int graph[N][N];



int main(){
    int m, n;
    cin >> n >> m;
    rn(i, m)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph [v1][v2] = 1;
        graph [v2][v1] = 1;
    }

    
}