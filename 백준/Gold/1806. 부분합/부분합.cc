#include <iostream>
#include <algorithm>

using namespace std;

int S[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, l = 0, r = 1, ans = 100001;
	cin >> N >> M;

	S[0] = 0;

	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		S[i] = S[i - 1] + x;
	}

	while (1) {
		if (r > N) break;
		if (S[r] - S[l] >= M) {
			ans = min(ans, r - l);
			l++;
		}
		else {
			r++;
		}
	}

	if (ans == 100001) ans = 0;

	cout << ans << "\n";
}
