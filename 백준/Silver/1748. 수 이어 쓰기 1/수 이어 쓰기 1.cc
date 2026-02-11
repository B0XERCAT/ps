#include <iostream>
using namespace std;

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  int ans = 0;
  int digit = 9;

  while (N)
  {
    if (N - digit < 0)
    {
      ans += N * to_string(digit).length();
      break;
    }
    ans += digit * to_string(digit).length();
    N -= digit;
    digit *= 10;
  }

  cout << ans;

  return 0;
}
