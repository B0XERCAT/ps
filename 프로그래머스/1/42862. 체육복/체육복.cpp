#include <string>
#include <vector>
#define MAX 33

using namespace std;

int cnt[MAX];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++)
        cnt[i] = 1;
    for(auto l: lost)
        cnt[l]--;
    for(auto r: reserve)
        cnt[r]++;
    
    for(int i = 1; i<= n; i++) {
        if(cnt[i] == 0) {
            if(cnt[i-1] == 2){
                cnt[i-1] = 1;
                cnt[i] = 1;
            } else if (cnt[i+1] == 2) {
                cnt[i+1] = 1;
                cnt[i] = 1;
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        if(cnt[i] >= 1)
            answer++;
    }
    
    return answer;
}