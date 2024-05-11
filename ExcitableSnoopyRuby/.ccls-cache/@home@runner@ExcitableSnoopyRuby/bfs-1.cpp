#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
bool visited[N];
int level[N];

void bfs(int vertex) {
  queue<int> q;
  q.push(vertex);
  visited[vertex] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    cout << cur << " ";
    for (int child : g[cur]) {
      if (!visited[child]) {
        q.push(child);
        visited[child] = true;
        level[child] = level[vertex] + 1;
      }
    }
  }

  cout << endl;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
  }
  bfs(0);
}

// 5
// 0 1
// 0 2
// 1 3
// 1 4
// 2 4
// from vertex 0: 0 1 2 3 4