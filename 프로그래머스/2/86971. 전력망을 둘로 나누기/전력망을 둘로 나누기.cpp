#include <string>
#include <vector>
#define MAX 101
using namespace std;

bool visited[MAX];
vector<int> graph[MAX];
int cnt;

void dfs(int start) {
    cnt++;
    visited[start] = true;
    for(auto next: graph[start]) {
        if(visited[next]) continue;
        dfs(next);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    // 끊을 거
    for(int i = 0; i < n - 1; i++) {
        // wires로 graph 만들기
        for(int j = 1; j <= n; j++) {
            graph[j].clear();
            visited[j] = false;
        }
        
        for(int j = 0; j < n - 1; j ++) {
            if(i == j) continue; // 스킵띠
            int a = wires[j][0];
            int b = wires[j][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        // dfs 돌리면서 개수 세기
        cnt = 0;
        dfs(1);
        
        int diff = abs(n - 2 * cnt);
        answer = min(answer, diff);
    }

    return answer;
}