#include <string>
#include <vector>

using namespace std;

int sol1[5] = {1, 2, 3, 4, 5};
int sol2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int sol3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int maxCnt = -1;
    
    int cnt[3] = {0, };

    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == sol1[i % 5]) cnt[0]++;
        if(answers[i] == sol2[i % 8]) cnt[1]++;
        if(answers[i] == sol3[i % 10]) cnt[2]++;
    }
    
    for(int i = 0; i < 3; i++) 
        if(cnt[i] > maxCnt) maxCnt = cnt[i];
    
    for(int i = 0; i < 3; i++)
        if(cnt[i] == maxCnt) answer.push_back(i + 1);
    
    
    return answer;
}