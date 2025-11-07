#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100005
#define pii pair<int, int>
using namespace std;

priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

int p[MAX];
int r[MAX];

int find(int a)
{
  if (p[a] == a)
    return a;
  else
    return p[a] = find(p[a]);
}

void join(int a, int b)
{
  int pa = find(a);
  int pb = find(b);

  if (pa == pb)
    return;

  if (r[pa] > r[pb])
    swap(pa, pb); // b가 더 깊어서 a를 붙여줘
  p[pa] = pb;

  if (pa == pb)
    r[pb]++;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, ans = 0, maxCost = 0;
  cin >> N >> M;

  for(int i=1; i<=N; i++){
    p[i] = i;
    r[i] = 1;
  }

  for (int i = 0; i < M; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    pq.push({c, {a, b}});
  }

  while (!pq.empty())
  {
    int cost = pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    if (find(x) == find(y))
      continue;
    else
    {
      maxCost = max(maxCost, cost);
      join(x, y);
      ans += cost;
    }
  }

  cout << ans - maxCost << "\n";
}
