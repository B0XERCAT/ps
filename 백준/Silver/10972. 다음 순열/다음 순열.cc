#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> v;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }

  if (next_permutation(v.begin(), v.end()))
  {
    for (int i = 0; i < n; i++)
      cout << v[i] << " ";
  }
  else
  {
    cout << -1;
  }

  return 0;
}
