#include <iostream>
#define MOD 10007
using namespace std;

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  int dp[1001];

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 3;

  for (int i = 3; i <= 1000; i++)
  {
    dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % MOD;
  }

  cout << dp[n];

  return 0;
}
