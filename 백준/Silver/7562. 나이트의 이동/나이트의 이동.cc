#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define pii pair<int, int>
using namespace std;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(pii start, pii end, int size)
{
  if (start == end)
    return 0;

  int dist[size + 1][size + 1];
  bool visited[size + 1][size + 1];

  memset(dist, 0, sizeof(dist));
  memset(visited, false, sizeof(visited));
  queue<pii> q;

  q.push(start);

  auto [x, y] = start;
  visited[x][y] = true;

  while (!q.empty())
  {
    auto [curX, curY] = q.front();
    q.pop();

    for (int i = 0; i < 8; i++)
    {
      int newX = curX + dx[i];
      int newY = curY + dy[i];

      if (newX < 0 || newY < 0 || newX >= size || newY >= size)
        continue;
      if (visited[newX][newY])
        continue;

      q.push({newX, newY});
      dist[newX][newY] = dist[curX][curY] + 1;
      visited[newX][newY] = true;
    }
  }

  return dist[end.first][end.second];
}

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;

  while (T--)
  {
    int I;
    cin >> I;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int res = bfs({x1, y1}, {x2, y2}, I);

    cout << res << "\n";
  }

  return 0;
}
