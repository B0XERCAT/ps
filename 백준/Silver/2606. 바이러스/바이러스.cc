#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

int graph[MAX][MAX];
bool visited[MAX];

void reset()
{
    for (int i = 1; i < MAX; i++)
        visited[i] = false;
}

void bfs(int start)
{
    int cnt = -1; // 1번 컴퓨터는 포함 안 함
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int v = q.front();
        cnt++;
        q.pop();

        for (int i = 1; i < MAX; i++)
        {
            if (graph[v][i] == 0 || visited[i])
                continue;
            q.push(i);
            visited[i] = true;
        }
    }

    cout << cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    reset();
    bfs(1);

    return 0;
}