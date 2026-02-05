#include <iostream>
#include <vector>
#define MOD 9901
using namespace std;

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  int dp[100002][3]; // 0 왼 / 1 오 / 2 없음

  dp[0][0] = 1;
  dp[0][1] = 1;
  dp[0][2] = 1;

  for (int i = 1; i < N; i++)
  {
    dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
    dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
  }

  cout << (dp[N - 1][0] + dp[N - 1][1] + dp[N - 1][2]) % MOD;

  return 0;
}
