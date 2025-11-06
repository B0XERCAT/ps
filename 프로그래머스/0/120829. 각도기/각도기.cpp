#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    if(angle % 90 == 0) return angle / 90 * 2;
    else return angle < 90 ? 1 : 3;
}