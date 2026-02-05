#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

vector<pii> v;
int N, ans = 0;

void dfs(int day, int sum)
{
  for (int i = day; i < N; i++)
  {
    if (i + v[i].first >= N + 1)
      ans = max(ans, sum);
    else if (i + v[i].first == N)
      ans = max(ans, sum + v[i].second);
    dfs(i + v[i].first, sum + v[i].second);
  }
}

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int T, P;
    cin >> T >> P;
    v.push_back({T, P});
  }

  dfs(0, 0);

  cout << ans;

  return 0;
}
