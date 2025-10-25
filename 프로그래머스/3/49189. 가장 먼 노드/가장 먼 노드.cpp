#include <string>
#include <vector>
#include <queue>
#define MAX 20003

using namespace std;

vector<int> graph[MAX];
int dist[MAX];
queue<int> q;
bool visited[MAX];
int maxDist = 0;

void bfs(int start) {
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(auto next: graph[cur]) {
            if(visited[next]) continue;
            q.push(next);
            visited[next] = true;
            dist[next] = dist[cur] + 1;
            maxDist = max(maxDist, dist[next]);
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(auto e: edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    bfs(1);
    
    for(int i = 1; i <= n; i++) {
        if(dist[i] == maxDist) answer++;
    }
    
    return answer;
}