#include <iostream>
#include <queue>
#define pii pair<int, int>
using namespace std;

int board[101][101];
bool visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;

void bfs(pii start)
{
  auto [startX, startY] = start;
  queue<pii> q;
  q.push(start);
  visited[startX][startY] = true;

  while (!q.empty())
  {
    auto [curX, curY] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int newX = curX + dx[i];
      int newY = curY + dy[i];

      if (newX < 0 || newX >= N || newY < 0 || newY >= M)
        continue;
      if (visited[newX][newY] || board[newX][newY] == 0)
        continue;

      q.push({newX, newY});
      visited[newX][newY] = true;
      board[newX][newY] = board[curX][curY] + 1;
    }
  }
}

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    string line;
    cin >> line;
    for (int j = 0; j < M; j++)
      board[i][j] = line[j] - '0';
  }

  bfs({0, 0});

  cout << board[N - 1][M - 1];

  return 0;
}
