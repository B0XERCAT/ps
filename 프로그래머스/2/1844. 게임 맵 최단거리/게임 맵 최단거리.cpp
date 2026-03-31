#include <vector>
#include <queue>
#define MAX 101
#define pii pair<int, int>
using namespace std;

bool visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[MAX][MAX];

void bfs(int n, int m, vector<vector<int> > maps) {
    queue<pii> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for(int i = 0; i <4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if(newX < 0 || newY < 0 || newX >= n || newY >= m) continue;
            if(maps[newX][newY] == 0) continue;
            if(visited[newX][newY]) continue;
            
            q.push({newX, newY});
            visited[newX][newY] = true;
            dist[newX][newY] = dist[x][y] + 1;
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    dist[0][0] = 1;
    dist[n-1][m-1] = -1;
    
    bfs(n, m, maps);
    
    return dist[n-1][m-1];
}