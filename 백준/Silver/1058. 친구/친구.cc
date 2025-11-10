#include <iostream>
#include <string>
#define MAX 53
using namespace std;

bool friends[MAX][MAX];
bool ans[MAX][MAX];

int main () {
  int N;
  cin >> N;

  for(int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < N; j++) {
      if(s[j] == 'N') friends[i][j] = false;
      else friends[i][j] = true;
    }
  }

  for(int k = 0; k < N; k++) {
    for(int i = 0; i < N; i++) {
      if(friends[k][i]) ans[k][i] = true;
      for(int j = 0; j < N; j++) {
        if(friends[i][k] && friends[k][j])
          ans[i][j] = true;
      }
    }
  }

  int answer = 0;
  
  for(int i = 0; i <N; i++) {
    int cnt = 0;
    for(int j = 0; j <N; j++) {
      if(ans[i][j]) cnt++;
    }
    answer = max(answer, cnt);
  }

  if(answer == 0) cout << answer;
  else cout << answer - 1;
}