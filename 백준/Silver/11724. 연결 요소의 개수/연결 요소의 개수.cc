#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[1002];
bool visited[1002];

void bfs(int s) {
  queue<int> q;
  q.push(s);
  visited[s] = true;

  while(!q.empty()) {
    int cur = q.front();
    q.pop();

    for(auto next: graph[cur]) {
      if(visited[next]) continue;
      q.push(next);
      visited[next] = true;
    }
  }
}

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M, ans = 0;
  cin >> N >> M;

  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for(int i = 1; i <= N; i++) {
    if(visited[i]) continue;
    bfs(i);
    ans++;
  }

  cout << ans;

  return 0;
}
