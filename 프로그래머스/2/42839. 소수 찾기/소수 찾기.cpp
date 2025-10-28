#include <string>
#include <vector>
#include <unordered_set>
#define MAX 8

using namespace std;
int K;
bool visited[MAX];
vector<int> separated;
unordered_set<int> connected;

void dfs(int index, int number) {
    if(index == K) {
        return;
    }
    
    for(int i = 0; i < K; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        connected.insert(number * 10 + separated[i]);
        dfs(index + 1, number * 10 + separated[i]);
        visited[i] = false;
    }
}

bool is_prime(int n) {
    if(n == 1 || n == 0) return false;
    if(n == 2 || n == 3) return true;
    for(int i = 2; i * i <= n; i++) 
        if(n % i == 0) return false;
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    for(int i = 0; i < MAX; i++) visited[i] = false;
    
    K = numbers.length();
    
    for(auto c: numbers) 
        separated.push_back(c - '0');
    
    dfs(0, 0);
    
    for(auto n: connected) 
        if(is_prime(n)) 
            answer++;
    
    return answer;
}