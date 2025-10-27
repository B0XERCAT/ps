#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int> us;

int solution(vector<int> nums)
{
    for(auto n: nums) us.insert(n);
    return nums.size() / 2 > us.size() ? us.size() : nums.size() / 2;
}