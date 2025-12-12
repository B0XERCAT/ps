#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(auto cloth: clothes) um[cloth[1]]++;
    
    for(auto type: um) answer *= (type.second + 1);
    
    return answer - 1;
}