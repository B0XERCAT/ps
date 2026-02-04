#include <iostream>
using namespace std;

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  if (N % 2 == 1)
    cout << "SK";
  else
    cout << "CY";

  return 0;
}
