#include <string>
#include <vector>

using namespace std;

int N, cnt = 0;

void dfs(int idx, int sum, vector<int> numbers, int target) {
    if(idx == N){
        if(sum == target) cnt++;
        return;
    }
    
    dfs(idx + 1, sum - numbers[idx], numbers, target);
    dfs(idx + 1, sum + numbers[idx], numbers, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    N = numbers.size();
    
    dfs(0, 0, numbers, target);
    
    answer = cnt;
    return answer;
}