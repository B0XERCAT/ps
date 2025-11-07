#include <string>
#include <vector>
#define MAX 102

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    bool dp[MAX][MAX];
    
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            dp[i][j] = false;
        }
    }
    
    for(auto path: results) {
        dp[path[0]][path[1]] = true;
    }
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dp[i][k] && dp[k][j]) dp[i][j] = true;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int a = 0, b = 0;
        for(int j = 1; j <= n; j++) {
            if(dp[j][i]) b++;
            if(dp[i][j]) a++;
        }
        if(a + b == n - 1) answer++;
    }
    
    return answer;
}