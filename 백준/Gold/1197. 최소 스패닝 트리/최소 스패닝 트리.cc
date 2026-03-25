#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 10002
#define pii pair<int, int>
#define ll long long
using namespace std;

int p[MAX];
int r[MAX];

priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

int find(int a) {
	if (a == p[a]) return a;
	else return p[a] = find(p[a]);
}

void join(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (pa == pb) return;

	if (r[pa] > r[pb]) swap(pa, pb); // b가 더 깊으니 a를 붙여
	p[pa] = pb;
	if (r[pa] == r[pb]) r[pb]++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		p[i] = i;
		r[i] = 1;
	}

	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		pq.push({ C, {A, B} });
	}

	ll ans = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;

		pq.pop();

		if (find(x) == find(y)) continue;
		else {
			join(x, y);
			ans += cost;
		}
	}

	cout << ans << "\n";

	return 0;
}
