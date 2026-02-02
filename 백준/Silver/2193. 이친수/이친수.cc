#include <iostream>
#define ll long long
using namespace std;

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;

  ll dp[91] = {0, 1, 1};

  for(int i = 2; i <= 90; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  cout << dp[N];

  return 0;
}
