#include <string>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    
    ll answer = 0, s = 0, e = (ll) times[0] * n;
    
    while(s <= e) {
        ll mid = (s + e) / 2;
        ll cnt = 0;
        for(auto t: times) cnt += (mid / (ll) t);
        
        if(cnt >= n) {
            answer = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    
    return answer;
}