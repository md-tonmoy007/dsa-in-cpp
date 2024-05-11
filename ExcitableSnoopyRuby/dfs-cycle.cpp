#include <bits/stdc++.h>

#define rn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;
const int N = 1e5 + 10;
bool vis[N];
vector<int> g[N];
bool isCycle;

bool dfs(int v, int p = 0) {
  vis[v] = true;
  isCycle = false;
  for (auto child : g[v]) {
    if (vis[v] && child == p)
      continue;
    if (vis[v])
      return true;
    isCycle |= dfs(child, v);
  }

  return isCycle;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
  }
  if (dfs(1)) {
    cout << "Cycle is present" << endl;
  };
}