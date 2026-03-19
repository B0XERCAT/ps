#include <iostream>
using namespace std;

int N, res=0;
int col[20];

void dfs(int colNo) {
	if(colNo == N + 1){
		res++;
	}
	
	// 가로 기준 어디인지 
	for(int i=1; i<=N; i++){
		//  위랑 대각선 확인하기
		bool cango = true; 
		// 현재 col보다 위에만 확인  
		for(int j = 1; j< colNo; j++){
			if(col[j] == i) // 이미 위에 있음 
				cango = false;
			// 대각선 1 
			if(j + col[j] == colNo + i)
				cango = false;
			// 대각선 2 
			if(j - col[j] == colNo - i)
				cango = false; 
		}
		
		if(!cango) continue;
		
		col[colNo] = i;
		dfs(colNo + 1);
	}
}

int main() {
	cin >> N;

	dfs(1);

	cout << res;
	return 0;
}