#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> strs;
    string answer = "";
    
    for(auto n: numbers) 
        strs.push_back(to_string(n));
    
    sort(strs.begin(), strs.end(), compare);
    
    for(auto s: strs) 
        answer += s;
    
    if(answer[0] == '0')
        answer = "0";

    return answer;
}