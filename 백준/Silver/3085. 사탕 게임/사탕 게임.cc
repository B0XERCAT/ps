#include <iostream>
#include <vector>
#include <string>
#define MAX 51
using namespace std;

int board[MAX][MAX];
int answer = 0;
int N;

void countCandy()
{
  for (int i = 0; i < N; i++)
  {
    int cnt1 = 1, cnt2 = 1;
    for (int j = 1; j < N; j++)
    {
      if (board[i][j] == board[i][j - 1])
        cnt1++;
      else
      {
        answer = max(answer, cnt1);
        cnt1 = 1;
      }
      if (board[j][i] == board[j - 1][i])
        cnt2++;
      else
      {
        answer = max(answer, cnt2);
        cnt2 = 1;
      }
    }
    answer = max(answer, max(cnt1, cnt2));
  }
}

void checkRight(int x, int y)
{
  swap(board[x][y], board[x][y + 1]);
  countCandy();
  swap(board[x][y], board[x][y + 1]);
}

void checkBottom(int x, int y)
{
  swap(board[x][y], board[x + 1][y]);
  countCandy();
  swap(board[x][y], board[x + 1][y]);
}

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    string line;
    cin >> line;
    for (int j = 0; j < N; j++)
    {
      board[i][j] = line[j];
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (j != N - 1)
        checkRight(i, j);
      if (i != N - 1)
        checkBottom(i, j);
    }
  }

  cout << answer;

  return 0;
}
