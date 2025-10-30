#include <string>
#include <vector>
#define MAX 203

using namespace std;

bool visited[MAX];
int k;

void dfs(int s, vector<vector<int>> computers) {
    for(int i = 0; i < k; i++) {
        if(visited[i]) continue;
        if(computers[s][i] == 1) {
            visited[i] = true;
            dfs(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i<MAX; i++) visited[i] = false;
    k = n;
    
    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        dfs(i, computers);
        answer++;
    }
    return answer;
}