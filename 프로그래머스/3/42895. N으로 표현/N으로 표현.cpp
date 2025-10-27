#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<unordered_set<int>> dp(10); // dp[x]: x개의 N을 사용해서 만들어진 수들의 집합

int repeat_digit(int reps, int N) {
    string num = "";
    for(int i = 0; i < reps; i++)
        num += to_string(N);
    return stoi(num);
}

int solution(int N, int number) {
    int answer = -1;
    dp[1].insert(N);
    
    if(N == number) return 1;
    
    for(int x = 2; x <= 8; x++) {
        int repN = repeat_digit(x, N);
        dp[x].insert(repN);
    }
    
    for(int x = 2; x <= 8; x++) {
        for(int i = 1; i < x; i++){
            for(int j = 1; j + i <= x; j++) {
                for(auto a : dp[i]) {
                    for(auto b : dp[j]){
                        dp[i + j].insert(a + b);
                        dp[i + j].insert(a * b);
                        if(a - b > 0) dp[i + j].insert(a - b);
                        if(a / b > 0) dp[i + j].insert(a / b);
                    }
                }
            }
        }
        if(dp[x].find(number) != dp[x].end()){
            return x;
        }
    }
    
    return answer;
}