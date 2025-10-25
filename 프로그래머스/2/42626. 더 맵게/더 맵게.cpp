#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

void mix() {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    pq.push(a + 2 * b);
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(auto s: scoville)
        pq.push(s);
    
    while(pq.top() < K) {
        if(pq.size() == 1){
            answer = -1;
            break;
        }
        answer++;
        mix();
    }
    
    return answer;
}