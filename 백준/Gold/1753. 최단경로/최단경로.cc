#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001
#define INF 987654321
using namespace std;

vector<pair<int, int>> graph[MAX];
int result[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start) {
	result[start] = 0;
	pq.push({ 0, start }); // 거리 순으로 정렬 ㄱㄱ

	while (!pq.empty()) {
		int dist = pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		for (auto p : graph[cur]) {
			int nextDist = dist + p.second;
			if (nextDist < result[p.first])
			{
				result[p.first] = nextDist;
				pq.push({ nextDist, p.first });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K;
	cin >> V >> E >> K;

	for (int i = 1; i < MAX; i++)
		result[i] = INF;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (result[i] == INF)
			cout << "INF\n";
		else
			cout << result[i] << "\n";
	}

	return 0;
}
