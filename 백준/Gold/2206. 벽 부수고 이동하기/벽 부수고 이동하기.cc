#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define MAX 1001
#define pii pair<int, int>
using namespace std;

struct Wall
{
  int x;
  int y;
  bool broken;
};

int N, M;
int graph[MAX][MAX][2];
bool visited[MAX][MAX][2];
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};

queue<Wall> q;
int bfs(int x, int y)
{
  q.push({x, y, false});
  visited[x][y][0] = true;

  while (!q.empty())
  {
    int curX = q.front().x;
    int curY = q.front().y;
    bool broken = q.front().broken;

    q.pop();

    if (curX == N - 1 && curY == M - 1)
      return graph[curX][curY][broken] + 1;

    for (int i = 0; i < 4; i++)
    {
      int newX = curX + dirX[i];
      int newY = curY + dirY[i];

      if (newX >= N || newX < 0 || newY >= M || newY < 0)
        continue;

      if (graph[newX][newY][0] == 1)
      {
        if (visited[newX][newY][1])
          continue;
        if (broken)
          continue;
        graph[newX][newY][1] = graph[curX][curY][0] + 1;
        q.push({newX, newY, true});
        visited[newX][newY][1] = true;
      }
      else if (graph[newX][newY][0] == 0)
      {
        if (visited[newX][newY][broken])
          continue;
        graph[newX][newY][broken] = graph[curX][curY][broken] + 1;
        q.push({newX, newY, broken});
        visited[newX][newY][broken] = true;
      }
    }
  }
  return -1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    string line;
    cin >> line;
    for (int j = 0; j < M; j++)
      graph[i][j][0] = line[j] - '0';
  }

  cout << bfs(0, 0) << "\n";

  return 0;
}
