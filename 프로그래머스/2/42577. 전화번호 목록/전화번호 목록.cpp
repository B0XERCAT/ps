#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size() - 1; i++){
        string a = phone_book[i], b = phone_book[i + 1];
        if(a.size() > b.size()) continue;
        if(a == b.substr(0, a.size())) return false;
    }
    
    return true;
}