#include <iostream>
using namespace std;

int N,M;
int ans[10];
bool visit[10];

void dfs(int depth) {
	if(depth == M){
		for(int i=0; i<M; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i=1; i<=N; i++){
		if(visit[i]) continue;
		ans[depth] = i;
		visit[i] = true; // 재귀 함수 들어가기 전에 방문 처리 
		dfs(depth + 1);
		visit[i] = false;
	} 
}

int main() {
	cin >> N >> M;
	
	dfs(0);
	
	return 0;
}