#include <iostream>
#define MAX 28 * 19
using namespace std;

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int E, S, M; // 15, 28, 19
  cin >> E >> S >> M;
  int ans = E;

  if (E == S && S == M)
  {
    cout << E;
    return 0;
  }

  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      for (int k = 0; k < MAX; k++)
      {
        int a = 15 * i + E;
        int b = 28 * j + S;
        int c = 19 * k + M;

        if (a == b && b == c)
        {
          cout << a;
          return 0;
        }
      }
    }
  }

  return 0;
}
