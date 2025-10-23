#include <vector>
#include <iostream>
#include <deque>

using namespace std;

deque<int> d;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for(auto n: arr){
        if(!d.empty() && n == d.back()) continue;
        d.push_back(n);
    }
    
    while(!d.empty()){
        answer.push_back(d.front());
        d.pop_front();
    }

    return answer;
}