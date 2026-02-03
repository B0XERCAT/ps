#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
int res[9];
int N, M;
bool visited[9];

void dfs(int idx, int cur)
{
  if (idx == M)
  {
    for (int i = 0; i < M; i++)
      cout << res[i] << " ";
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; i++)
  {
    if (visited[i])
      continue;
    if (arr[i] < cur)
      continue;
    cur = arr[i];
    visited[i] = true;
    res[idx] = arr[i];
    dfs(idx + 1, cur);
    visited[i] = false;
  }
}

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  sort(arr, arr + N);

  dfs(0, 0);

  return 0;
}
