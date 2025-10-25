#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int N = sizes.size();
    int h = -1, w = -1;
    
    for(int i=0; i<N; i++) {
        if(sizes[i][0] > sizes[i][1]) {
            h = max(h, sizes[i][0]);
            w = max(w, sizes[i][1]);
        }
        else {
            h = max(h, sizes[i][1]);
            w = max(w, sizes[i][0]);
        }
    }
    
    answer = h * w;
    
    return answer;
}