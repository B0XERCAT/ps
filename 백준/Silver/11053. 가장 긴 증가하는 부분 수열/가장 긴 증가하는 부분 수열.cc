#include <iostream>
using namespace std;

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  int a[1001];
  int dp[1001];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    dp[i] = 1;
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (a[i] > a[j])
        dp[i] = max(dp[i], dp[j] + 1);

  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    ans = max(ans, dp[i]);
  }

  cout << ans;

  return 0;
}
