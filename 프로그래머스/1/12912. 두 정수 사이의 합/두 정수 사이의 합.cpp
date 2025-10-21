#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if(a > b) {
        swap(a, b);
    }
    answer = (a + b);
    answer *= (b - a + 1); 
    answer /= 2;
    return answer;
}