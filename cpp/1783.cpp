#include <bits/stdc++.h>
using namespace std;

int N, M;
int main() {
	cin >> N >> M;
	// 일직선
	if (N == 1)
		cout << 1;
	// 세로 2칸
	else if (N == 2) {
		if (M >= 7)
			cout << 4;
		else
			cout << (M - 1) / 2 + 1;
	}
	else {
		// 방문한 칸 4개 이하
		if (M < 7)
			cout << min(4, M);
		// 이동방법 모두 1번씩
		else
			cout << M - 5 + 3;
	}
	return 0;
}