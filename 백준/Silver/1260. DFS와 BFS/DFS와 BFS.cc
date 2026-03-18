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

void dfs(int start)
{
    cout << start << " ";
    visited[start] = true;
    for (int i = 1; i < MAX; i++)
    {
        if (graph[start][i] == 0 || visited[i])
            continue;
        dfs(i);
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int v = q.front();
        cout << v << " ";
        q.pop();

        for (int i = 1; i < MAX; i++)
        {
            if (graph[v][i] == 0 || visited[i])
                continue;
            q.push(i);
            visited[i] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    reset();
    dfs(V);
    cout << "\n";
    reset();
    bfs(V);

    return 0;
}