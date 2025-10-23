#include <string>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> um;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(auto &c: completion){
        um[c]++;
    }
    
    for(auto p: participant){
        auto it = um.find(p);
        if(it != um.end()){
            if(it->second == 1)
                um.erase(it->first);
            else
                it->second--;
        }
        else {
            answer = p;
        }
    }
    return answer;
}